//arduino uses little endian : stores the least significabt bit(0) in the smallest address which is at far right 
// |7|6|5|4|3|2|1|0|   0th bit is is LSb and 7th bit is MSb 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


char ch = 'B'; //which is actually 0B01000010 .. so below you see printing this binary byte ---> character 'B' is printed  
               //which conforms that little endian is used in arduino
               
byte b = 0b01000010;
Serial.println(b,BIN);
Serial.write(b);

Serial.println("\n******************");

Serial.println(ch,BIN); //rechecking
Serial.write(ch);
}

void loop() {
  // put your main code here, to run repeatedly:

}
