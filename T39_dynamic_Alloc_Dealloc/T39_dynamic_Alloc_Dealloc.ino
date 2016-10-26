/*
 * @author: ayz
 * @brief: this skecth shows how to do dynamic memory allocation and deallocation
 */


void setup() 
{
  Serial.begin(9600);
  Serial.println(F("Dynamic alloc dealloc .."));

  
  Serial.print(F("before Alloc Free SRAM: "));
  Serial.println(getFreeRam());

  byte* arrayAtHeap; 
  arrayAtHeap = new byte[1024];     //dynamically allocating memory

  Serial.print(F("After Alloc Free SRAM: "));
  Serial.println(getFreeRam());

  delete[] arrayAtHeap;             //deallocating memory 

  
  Serial.print(F("After dealloc Free SRAM: "));
  Serial.println(getFreeRam());
}

void loop() 
{}

/*
 * @brief: this function returns the number of bytes free at SRAM
 */
int getFreeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
