/*all the functions are declared in the header file this .cpp file have the constructor 
and other function definitions*/

#include "UI.h"

/*constructor when a object of this type is created this constructor is called & lcd object's constructor is also called with arguments*/
UI::UI(byte rs,byte cs,byte din,byte clk):lcd(rs,cs,din,clk)  
{
}
void UI::Initialize(void)
{ 
  delay(100);
  lcd.begin();
  lcd.displayNormal();
  lcd.clear();
}


/*void UI::printInfo(int line_no, char *title, char *value)
{
  lcd.line(line_no);
  lcd.print("                ");
  lcd.print(title);
  lcd.print(value);
}*/

void UI::logo(void)               //public function which will show the logo 
{
  unsigned char buff;
  for(int index = 0; index < 96*8; index++)
     { 
     buff=(pgm_read_byte(LOGO+index));
     lcd.data(buff);
     }  
}


void UI::emptyTank(byte x) //48 or 0
{
  unsigned char buff;
  for(byte page=1; page<=PAGE; page++)
   {
     UI::Lcd_set_pos_pix(x,(page-1));
     for(unsigned int i=page; i<=(BLANK_TANK[0]*PAGE); i+=PAGE)
        {
		  buff=(pgm_read_byte(BLANK_TANK+i));
          lcd.data(buff);
        }
   }  
}

void UI::filledTank(byte x)  //48 or 0
{
 unsigned char buff;
  for(byte page=1; page<=PAGE; page++)
   {
     UI::Lcd_set_pos_pix(x,(page-1));
     for(unsigned int i=page; i<=(FULL_TANK[0]*PAGE); i+=PAGE)
        {
		  buff=(pgm_read_byte(FULL_TANK+i));
          lcd.data(buff);
        }
   } 

}

void UI::PrintString(byte x, byte y, char *characters, char size){
byte newpos=x;
byte offset=0;
while(*characters!='\0'){
     offset=UI::PrintCharacter(newpos, y, *characters++, size);
     newpos=newpos+offset;
     if((95-newpos)<offset)
       {
       newpos=0;
	   switch(size)
	         {
			 case 's': y+=1;break;
			 case 'm': y+=2;break;  
			 }
       }
     }

}

byte UI::PrintCharacter(byte x, byte y, char character, char size){
  byte buff,limit;
  
  switch(size)
        {
		case 's':
		      {
			  limit=pgm_read_byte(&SMALL[character - 0x20][0]);
			  UI::Lcd_set_pos_pix(x,y);
              for (int i = 1; i <= limit; i++)
                  {
                  buff=pgm_read_byte(&SMALL[character - 0x20][i]);
                  lcd.data(buff);  
                  }			  
			  }
			  break;
	    case 'm':
		      {
			  limit=pgm_read_byte(&MED[character - 0x20][0]);
              UI::Lcd_set_pos_pix(x,y);
              for (int odd = 1; odd <= limit*2; odd+=2)
                  {
                  buff=pgm_read_byte(&MED[character - 0x20][odd]);
                  lcd.data(buff);  
                  }
              y=(y+1);
              UI::Lcd_set_pos_pix(x,y);
              for (int even = 2; even <= limit*2; even+=2)
                  {
                  buff=pgm_read_byte(&MED[character - 0x20][even]);
                  lcd.data(buff);  
                  }			  
			  }
			  break;
        }  
return (limit+1);
}

void UI::Lcd_set_pos_pix(byte c, byte r){
  lcd.command(0xB0 | (r & 0x0F));
  lcd.command(0x10 | ((c >> 4) & 0x07));
  lcd.command(0x00 | (c & 0x0F));
}

void UI::ClearScreen(void){
  lcd.clear();
} 