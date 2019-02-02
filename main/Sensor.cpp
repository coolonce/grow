#include "Sensor.h"

Sensor::Sensor(int type) {
	sensorType = type;
}

void Sensor::initialize() {
	//��� ������������� ������������ ����, ���� � �������
	if (sensorType>=4 && sensorType<=8) {
		pinMode(sensorType, HIGH);
	}
	//��� ��������� ������ ����
	else if (sensorType == 9) {
		pinMode(sensorType, INPUT_PULLUP);
	}
	//��� �������� ��������� �����
	//if(�����)
}

void Sensor::activate() {
	//��� �����
	if (sensorType == 6) {
		digitalWrite(sensorType, HIGH);
	}
	//��� ��������
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
	//��� ������ ����
	if (sensorType == 9) {
		return !digitalRead(sensorType);
	}
	//��� ��������� �����
	//��� � �� ���� ����������� ������ �������, ����� ����� ��� ���������
	else {  
		return analogRead(sensorType);
	}
}
