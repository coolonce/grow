#pragma once
#include "conf.h"
#include "string.h"

using namespace std;

class Sensor {
private:
	int sensorType;
public:
	//Инициализация датчика
	Sensor(int type);
	void initialize();
	void activate();
	void deactivate();
	int getData();
};