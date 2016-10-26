#define LByte(w) ((uint8_t) ((w) & 0xff))
#define HByte(w) ((uint8_t) ((w) >> 8))

void setup() {
  // put your setup code here, to run onc
  Serial.begin(9600);
  unsigned int x = 0B1111000010100101;
  Serial.println(LByte(x),BIN);
  Serial.println(HByte(x),BIN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
