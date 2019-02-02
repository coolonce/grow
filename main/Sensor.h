#pragma once
#include "Arduino.h"
#include "conf.h"
#include "string.h"

using namespace std;

class Sensor {
private:
	int sensorType;
public:
	//������������� �������
	Sensor(int type);
	void initialize();
	void activate();
	void deactivate();
	int getData();
};
