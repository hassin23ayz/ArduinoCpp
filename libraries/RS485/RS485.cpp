
#define byte uint8_t
#define boolean bool

#include "RS485.h"

RS485::RS485(byte _rx, byte _tx){
	rx = _rx;
	tx = _tx;
	delay(5);
}

void RS485::RS485init(unsigned long _bps){
	SoftwareSerial serial(rx,tx);
	serial.begin(_bps);
}
boolean RS485::RS485compare(char* This) {
	while (serial.available() > 0) // Don't read unless there you know there is data
	{
		if (index < 4) // One less than the size of the array
		{
			inChar = serial.read(); // Read a character
			inData[index] = inChar; // Store it
			index++; // Increment where to write next
			inData[index] = '\0'; // Null terminate the string
		}
	}

	if (strcmp(inData, This)  == 0) {
		for (int i = 0; i < 4; i++) {
			inData[i] = 0;
		}
		index = 0;
		return true;
	}
	else {
		return false;
	}
}






