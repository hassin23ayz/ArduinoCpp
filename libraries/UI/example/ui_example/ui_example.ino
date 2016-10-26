#include <graphicsLCD.h>
#include <UI.h>

//nokia 1202 GLCD configuration
#define lcd_RST_pin 5
#define lcd_CS_pin 6
#define lcd_DIN_pin 7
#define lcd_CLK_pin 8

UI u(lcd_RST_pin,lcd_CS_pin,lcd_DIN_pin,lcd_CLK_pin);
void setup() {
  // put your setup code here, to run once:
u.Initialize();
u.logo();
delay(2000);
u.ClearScreen();
char txt[] = "APLOMBTECHBD PUMP CONTROLLER....\0";
u.PrintString(0,0,txt,'m'); 
delay(2000);
u.ClearScreen();
u.PrintString(3,6,"Sump",'m');
u.PrintString(52,6,"Roof",'m');
u.filledTank(0);
u.emptyTank(48);
}

void loop() {
u.filledTank(48);
delay(500);
u.emptyTank(48);
delay(500);
}
