
//конфигурациооный файл
#include "conf.h"
#include "Sensor.h"
#include "string.h"
#include "Printer.h"

//Датчик влажности почвы
int gndHmd1 = A1;
int gndHmd2 = A2;
Sensor HumiditySensor1(gndHmd1);
Sensor HumiditySensor2(gndHmd2);
//Уровень воды
const uint8_t lvlWater = 9;
Sensor WaterLevelSensor(lvlWater);
//Светодиодная лента
//1Линия
int ledLenta1 = 4;
Sensor LedSensor1(ledLenta1);
//2линия
int ledLenta2 = 5;
Sensor LedSensor2(ledLenta2);
//Насос
int pomp = 6;
Sensor PompSensor(pomp);
//Клапаны
//первая линия
int clapans1 = 7;
Sensor ClapanSensor1(clapan1);
//вторая линия
int clapans2 = 8;
Sensor ClapanSensor2(clapan2);

Printer printer;
// Для полива
unsigned long endWateringTime = 0;
unsigned long sleepWatering = 0;

//DTH
#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

volatile uint32_t END_TIME_PULLING_DATA = 0;
         uint32_t END_TIME_ON_LED = 0;

void setup() {
  Serial.begin(9600);
  //инициализируем датчик воды
  WaterLevelSensor.initialize();
  //Инициализация светодиодных лент
  LedSensor1.initialize();
  LedSensor2.initialize();
  //Инициализация помпы
  PompSensor.initialize();
  //Инициализация клапанов
  ClapanSensor1.initialize();
  ClapanSensor2.initialize();
  //dht.begin();
}

void loop() {
	if ((END_TIME_PULLING_DATA + SEND_DATA_TIME) < millis() || END_TIME_PULLING_DATA > millis()) {
		//Формируем строку
		//из-за того, что немного запутался с id устройств заебенил сюда константы
		printer.addSensorData(2, dht.readTemperature());
		printer.addSensorData(3, dht.readHumidity());
		printer.addSensorData(7, HumiditySensor1.getData());
		printer.addSensorData(8, HumiditySensor2.getData());
		printer.addSensorData(9, WaterLevelSensor.getData());
		printer.addSensorId(ID);
		//Выводим строку в сериал порт
		Serial.print(printer.printToSerial());
		END_TIME_PULLING_DATA = millis();
	}
	watering();
	/*
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
  watering();
  */
}

void watering(){
	static bool state;
    static unsigned long time;
	//Запускаем на 20 секунд каждые 4 часа
    if((millis() - time) > (state ? 20000 : 14400000))
    {
      state = !state;
      if(state){
		  ClapanSensor1.activate();
		  ClapanSensor2.activate();
		  PompSensor.activate();
	  }else{
		  ClapanSensor1.deactivate();
		  ClapanSensor2.deactivate();
		  PompSensor.deactivate();
	  }    
      time = millis();
    }
}

