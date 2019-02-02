#pragma once

#include <string>

using namespace std;

class Printer {
private:
	string msg;
public:
	void addSensorData(int sensorId, float sensorData);
	void addSensorId(int id);
	string printToSerial();
};