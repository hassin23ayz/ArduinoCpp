//this code that negative numbers are stored in 2's complement form 

void setup() 
{
Serial.begin(9600);
char a = 1;
Serial.println(a,BIN);
a = 0;
Serial.println(a,BIN);
a = 0b11111111;     // to get -1 ...... first 1 = 0b0000 0001 then invert it 0b1111 1110 then add 1 to it 0b1111 1111 = -1  
//a = 0b10000001;   //-127           
Serial.println(a,DEC);
}

void loop() 
{}
