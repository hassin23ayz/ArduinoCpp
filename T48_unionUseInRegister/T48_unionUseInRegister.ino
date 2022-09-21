typedef union
{
  struct
  {
    uint8_t  CAL_0:1;
    uint8_t  CAL_1:1;
    uint8_t  CAL_2:1;
    uint8_t  CAL_3:1;
    uint8_t  CAL_4:1;
    uint8_t  CAL_5:1;
    uint8_t  CAL_6:1;
    uint8_t  CAL_7:1;
  }b;              //distributed in bits
  uint8_t u8;      //all in one 
} REG_8Type;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  REG_8Type myReg;
  uint8_t tmp = OSCCAL; //Read the  Oscillator Calibration Register value 
  myReg.u8 = tmp; //assign the register value to the union REG_8Type type to the u8 . 
                      //And as union will hold only one member So the value put at u8 will get divided to the members of the struct b 

  Serial.print("Original OSCCAL value in bits are :");
  Serial.println(OSCCAL, BIN);
  Serial.print("value of u8 in the union is :");
  Serial.println(myReg.u8, BIN); 
  
  Serial.print("distributed values of struct b in the union are :");
  Serial.print(myReg.b.CAL_7);
  Serial.print(myReg.b.CAL_6);
  Serial.print(myReg.b.CAL_5);
  Serial.print(myReg.b.CAL_4);
  Serial.print(myReg.b.CAL_3);
  Serial.print(myReg.b.CAL_2);
  Serial.print(myReg.b.CAL_1);
  Serial.print(myReg.b.CAL_0);

  Serial.println("");
  Serial.print("Size of REG_8Type in byte is : ");
  Serial.println(sizeof(REG_8Type));
}

void loop() {
  // put your main code here, to run repeatedly:

}
