#pragma once

#include "WString.h"

using namespace std;

class Printer {
private:
	String msg;
public:
	void addSensorData(int sensorId, float sensorData);
	void addSensorId(int id);
	String printToSerial();
};
