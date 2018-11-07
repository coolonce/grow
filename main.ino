
//конфигурациооный файл
#include "conf.h"

#include "string.h"

//Уровень воды
const uint8_t lvlWater = 9;
//DTH
#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//PHmetr
#define SensorPin A0            //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00            //deviation compensate
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0;

//Датчик влажности почвы
int gndHmd1 = A1;
int gndHmd2 = A2;

//Светодиодная лента
//1Линия
int ledLenta1 = 4;
int ledAct1 = 0;
//2линия
int ledLenta2 = 5;
int ledAct2 = 0;


//Насос
int pomp = 6;
int pompAct = 0;
//Клапаны
int clapans1 = 7;
int clapansAct1 = 0;
//вторая линия
int clapans2 = 8;
int clapansAct2 = 0;




//Датчик расхода воды
const    uint8_t  pinSensor = 2; 
         uint8_t  intSensor; //переменную для хранения № прерывания для вывода pinSensor
         float    GC = 7.5; //частота в Гц, так как расчёт происходит 1 раз в секунду
volatile uint16_t countImpuls  = 0;  // Кол-во импульсов поступивших от датчика
         uint32_t endTimeCalc   = 0; // Последний расчет
         uint8_t  speedFlowWater = 0; //

volatile uint32_t END_TIME_PULLING_DATA = 0;
         uint32_t END_TIME_ON_LED = 0;


void setup() {
  Serial.begin(9600);
  lvlWaterAct();
  ledActivate1();
  ledActivate2();
//  sensorWaterFlowActivate();
  pompActivate();
  clapansOn1();
  clapansOn2();
  //dht.begin();
 
}

void loop() {
  if((END_TIME_PULLING_DATA + SEND_DATA_TIME)<millis() || END_TIME_PULLING_DATA > millis()){
    Serial.print("{\"sensors\": [{\"id\":2, \"data\":");
    Serial.print(dht.readTemperature());
    Serial.print("}, {\"id\":3, \"data\":");
    Serial.print(dht.readHumidity());
    Serial.print("},{\"id\":7, \"data\":");
    Serial.print(pullDataGndHmd1());
    Serial.print("},{\"id\":8, \"data\":");
    Serial.print(pullDataGndHmd2());
    Serial.print("},{\"id\":9, \"data\":");
    Serial.print(pullDataLvlWater());
    Serial.print("} ], \"device_id\":");
	Serial.print(ID);
	Serial.println("}\0");
    END_TIME_PULLING_DATA = millis();
  }
  
  if(END_TIME_ON_LED + TIME_ON_LED <= millis()){
    ledToggle1();
    ledToggle2()
    END_TIME_ON_LED = millis();
  }
  
  if(pullDataGndHmd1() > HUMIDITY_MAX1 && pullDataLvlWater()){
    clapansOn1();
    pompOn();
  }
  
  if(pullDataGndHmd1() - 100 <  HUMIDITY_MIN1 && pullDataLvlWater()){
    clapansOff1();
    pompOff();
  }

  if(pullDataGndHmd2() > HUMIDITY_MAX2 && pullDataLvlWater()){
    clapansOn2();
    pompOn();
  }
  
  if(pullDataGndHmd2() - 100 <  HUMIDITY_MIN2 && pullDataLvlWater()){
    clapansOff2();
    pompOff();
  }
  
  
}

float pullPHData(){
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float pHValue,voltage;
  if(millis()-samplingTime > samplingInterval)
  {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLenth)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
      pHValue = 3.5*voltage+Offset;
      samplingTime=millis();
  }
  return pHValue;
}
double avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if(number<5){   //less than 5, calculated directly statistics
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}


int pullDataGndHmd1(){
  return analogRead(gndHmd1);
}

int pullDataGndHmd2(){
  return analogRead(gndHmd1);
}


//void sensorWaterFlowActivate(){
//  pinMode(pinSensor, INPUT);
//  intSensor = digitalPinToInterrupt(pinSensor);
//  attachInterrupt(intSensor, funCountInt, RISING);  
//}
//void funCountInt(){countImpuls++;}
//Считываем данные с датчика
//uint8_t pullDataSWF(){
//  if((endTimeCalc+1000)<millis() || endTimeCalc>millis()){
//        speedFlowWater=countImpuls/GC;
//        countImpuls=0; 
//        endTimeCalc=millis();
//        return speedFlowWater;
//    }                                      
//}

//Подпервую линию
void ledActivate1(){
  pinMode(ledLenta1, HIGH);
  ledAct1 = 1;
}
//Включение и выключение ленты
void ledToggle1(){
  Serial.println("Led");
  if(!ledAct1)
   {
    ledAct1 = 1;
    digitalWrite(ledLenta1, HIGH);
   }else{
      ledAct1 = 0;
      digitalWrite(ledLenta1, LOW);
    }
}

void lvlWaterAct(){
  pinMode(lvlWater, INPUT_PULLUP);  
}
int pullDataLvlWater(){
  //Вода есть 1 
  return !digitalRead(lvlWater);
}


//Под вторую линию
void ledActivate2(){
  pinMode(ledLenta2, HIGH);
  ledAct2 = 1;
}
//Включение и выключение ленты
void ledToggle2(){
  Serial.println("Led");
  if(!ledAct2)
   {
    ledAct2 = 1;
    digitalWrite(ledLenta2, HIGH);
   }else{
      ledAct2 = 0;
      digitalWrite(ledLenta2, LOW);
    }
}

void pompActivate(){
  pinMode(pomp, HIGH);
  pompAct = 1;
}

void pompOn(){
   Serial.println("popm on");
    pompAct = 1;
    digitalWrite(pomp, HIGH);
}
void pompOff(){
   Serial.println("pomp off");
  pompAct = 0;
  digitalWrite(pomp, LOW);
}



void clapansOn1(){
  pinMode(clapans1, HIGH);
  clapansAct1 = 1;
}
void clapansOn2(){
  pinMode(clapans1, HIGH);
  clapansAct2 = 1;
}

void clapansOff1(){
  pinMode(clapans1, LOW);
  clapansAct1 = 1;
}
void clapansOff2(){
  pinMode(clapans2, LOW);
  clapansAct2 = 0;
}


