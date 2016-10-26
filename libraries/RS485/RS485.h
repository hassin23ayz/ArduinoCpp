#ifndef RS485_h      //constructor
#define RS485_h

#define byte uint8_t
#define boolean bool

#include <arduino.h>
#include <SoftwareSerial.h>

class RS485 {
	public:
	RS485(byte _rx, byte _tx);
	void RS485init(unsigned long _bps);
	boolean RS485compare(char* this);

	private:
	byte rx,tx;
	char inData[5]; // Allocate some space for the string
	char inChar = -1; // Where to store the character read
	byte index = 0; // Index into array; where to store the character
};
#endif