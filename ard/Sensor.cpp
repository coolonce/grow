#include "Sensor.h"

Sensor::Sensor(int type) {
	sensorType = type;
}

void Sensor::initialize() {
	//Для инициализации светодиодных лент, помп и насосов
	if (sensorType>=4 && sensorType<=8) {
		pinMode(sensorType, HIGH);
	}
	//Для измерения уровня воды
	else if (sensorType == 9) {
		pinMode(sensorType, INPUT_PULLUP);
	}
	//для датчиков влажности почвы
	//if(хуйня)
}

void Sensor::activate() {
	//для помпы
	if (sensorType == 6) {
		digitalWrite(sensorType, HIGH);
	}
	//для клапанов
	else if (sensorType == 7 || sensorType == 8) {
		pinMode(sensorType, HIGH);
	}
}

void Sensor::deactivate() {
	if (sensorType >= 4 && sensorType <= 6) {
		digitalWrite(sensorType, LOW);
	}
	else if (sensorType == 7 || sensorType == 8) {
		pinMode(sensorType, LOW);
	}
}

int Sensor::getData() {
	//для уровня воды
	if (sensorType == 9) {
		return !digitalRead(sensorType);
	}
	//для влажности почвы
	//ибо я не знаю конкретного номера датчика, чтобы точно его прописать
	else {
		return analogRead(sensorType);
	}
}