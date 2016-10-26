/*
 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 */
#include <RS485.h>
#include <SoftwareSerial.h>

RS485 r(10,11); // RX, TX, bps, string Length

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("RS485_r");
  r.RS485init(1200);
}

void loop() // run over and over
{
  if(r.RS485Compare("upUP") == true) {
    Serial.println("matched");
  }
  else {
    Serial.println("did not match");
  }
}



