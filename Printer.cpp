#include "Printer.h"

void Printer::addSensorData(int sensorId, float sensorData) {
	if (data.empty()) {
		msg += "{\"sensors\": [";
		msg += "{\"id\":" + to_string(sensorId) + ", \"data\":" + to_string(sensorData) + "}";
	}
	else {
		msg += ",";
		msg += "{\"id\":" + to_string(sensorId) + ", \"data\":" + to_string(sensorData) + "}";
	}	
}

void Printer::addSensorId(int id) {
	msg += " ], \"device_id\":" + to_string(id) + "}\0";
}

string Printer::printToSerial() {
	string result = msg;
	msg = "";
	return result;
}