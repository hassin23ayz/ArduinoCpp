#include <graphicsLCD.h>

//nokia 1202 GLCD configuration
#define lcd_RST_pin 5
#define lcd_CS_pin 6
#define lcd_DIN_pin 7
#define lcd_CLK_pin 8

graphicsLCD lcd(lcd_RST_pin,lcd_CS_pin,lcd_DIN_pin,lcd_CLK_pin);

byte line_no=0;

void setup() {
  lcd.begin();
  lcd.clear();
  lcd.displayNormal();
  lcd.logo();
  delay(3000);
  lcd.clear();
}

void loop() {
  char lcd_str[6];
  unsigned long t = millis();
  float _min = 0.0;
  _min = ((float)t/60000);
  dtostrf(_min,6,2,lcd_str);
  lcd.printInfo(line_no, "Min:", lcd_str);
  delay(2000);
  line_no++;
  if(line_no==8)line_no=0;
}
