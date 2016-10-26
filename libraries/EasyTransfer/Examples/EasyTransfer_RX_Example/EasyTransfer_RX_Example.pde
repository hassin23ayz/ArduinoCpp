#include <EasyTransfer.h>

//create object
EasyTransfer ET; 

struct RECEIVE_DATA_STRUCTURE{
    String inData;
};

//give a name to the group of data
RECEIVE_DATA_STRUCTURE mydata;

void setup(){
  Serial.begin(1200);
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
  ET.begin(details(mydata), &Serial);
  pinMode(13, OUTPUT); 
}

void loop(){
  //check and see if a data packet has come in. 
  if(ET.receiveData())
  {
    if(mydata.inData=="upUP")
      digitalWrite(13,HIGH);
    if(mydata.inData=="down")
      digitalWrite(13,LOW);
  }
}
