/**
 * @file  DebugSng.cpp
 * @mainpage The DebugSng Library
 * @brief This is the Debug class following singleton pattern
 * 
 * @section intro_sec Introduction
 * A Singleton Class for debug print so that the whole system has can create only one object of this
 * 
 * @note ![my Blog] http://whileinthisloop.blogspot.com
 * 
 * @subsection step1 License
 * this work is under ![Creative Common License] (https://creativecommons.org/licenses/by/4.0/)
 * 
 * @subsection step2 Using the Library
 * usage: in order to use this library
 * 
 *      1. you need to associate a pin which will act as the debug wire
 *      
 *      2. you need to set the pin no & baud rate in the header file
 *      
 * @author  Hassin Ayaz 
 * @date 09/23/2016
 */


#include "DebugSng.h"

bool DebugSng::instanceFlag = false;
DebugSng* DebugSng::single = NULL;

DebugSng::DebugSng()
{
  DBG_UART_TX_PORT |= (1<<DBG_UART_TX_PIN); 
  DBG_UART_TX_DDR |= (1<<DBG_UART_TX_PIN);
  debugOnDecsn = true;
  printFlashString(F("constructor called"));
  printLineFeed();
}

DebugSng::~DebugSng()
{
  instanceFlag = false;
}

DebugSng* DebugSng::getInstance()
{
    if(! instanceFlag)
    {
        single = new DebugSng();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}
void DebugSng::dbg_putchar(uint8_t c)
{
  uint8_t sreg;
  uint16_t tmp;
  uint8_t numiter = 10;

  sreg = SREG;
  cli();

  asm volatile (
    /* put the START bit */
    "in %A0, %3"    "\n\t"  /* 1 */
    "cbr %A0, %4"   "\n\t"  /* 1 */
    "out %3, %A0"   "\n\t"  /* 1 */
    /* compensate for the delay induced by the loop for the
     * other bits */
    "nop"     "\n\t"  /* 1 */
    "nop"     "\n\t"  /* 1 */
    "nop"     "\n\t"  /* 1 */
    "nop"     "\n\t"  /* 1 */
    "nop"     "\n\t"  /* 1 */

    /* delay */
     "1:" "ldi %A0, lo8(%5)"  "\n\t"  /* 1 */
    "ldi %B0, hi8(%5)"  "\n\t"  /* 1 */
     "2:" "sbiw %A0, 1"   "\n\t"  /* 2 */
    "brne 2b"   "\n\t"  /* 1 if EQ, 2 if NEQ */
    #if DBG_UART_TX_NUM_ADD_NOP > 0
        "nop"     "\n\t"  /* 1 */
      #if DBG_UART_TX_NUM_ADD_NOP > 1
        "nop"     "\n\t"  /* 1 */
        #if DBG_UART_TX_NUM_ADD_NOP > 2
        "nop"     "\n\t"  /* 1 */
        #endif
      #endif
    #endif
    /* put data or stop bit */
    "in %A0, %3"    "\n\t"  /* 1 */
    "sbrc %1, 0"    "\n\t"  /* 1 if false,2 otherwise */
    "sbr %A0, %4"   "\n\t"  /* 1 */
    "sbrs %1, 0"    "\n\t"  /* 1 if false,2 otherwise */
    "cbr %A0, %4"   "\n\t"  /* 1 */
    "out %3, %A0"   "\n\t"  /* 1 */

    /* shift data, putting a stop bit at the empty location */
    "sec"     "\n\t"  /* 1 */
    "ror %1"    "\n\t"  /* 1 */

    /* loop 10 times */
    "dec %2"    "\n\t"  /* 1 */
    "brne 1b"   "\n\t"  /* 1 if EQ, 2 if NEQ */
    : "=&w" (tmp),      /* scratch register */
      "=r" (c),     /* we modify the data byte */
      "=r" (numiter)    /* we modify number of iter.*/
    : "I" (_SFR_IO_ADDR(DBG_UART_TX_PORT)),
      "M" (1<<DBG_UART_TX_PIN),
      "i" (DBG_UART_TX_NUM_DELAY_CYCLES),
      "1" (c),      /* data */
      "2" (numiter)
  );
  SREG = sreg;
}

void DebugSng::debugPrintln(const __FlashStringHelper* moduleName,const __FlashStringHelper* debugType, const __FlashStringHelper* msg)
{
  if(debugOnDecsn)
  {
    printFlashString(moduleName);
    dbg_putchar(',');
    printFlashString(debugType);
    dbg_putchar(':');
    dbg_putchar(' ');
    dbg_putchar('"');
    printFlashString(msg);
    dbg_putchar('"');
    printLineFeed();    
  }
}

void DebugSng::printFlashString(const __FlashStringHelper* str)
{
  PGM_P p = reinterpret_cast<PGM_P>(str);
  while (1) 
  {
    unsigned char c = pgm_read_byte(p++);
    if (c == 0) break;
    dbg_putchar(c);
  }
}

void DebugSng::printLineFeed(void)
{
  dbg_putchar('\r');
  dbg_putchar('\n'); //line feed LF  
}

void DebugSng::turnOnDebug(void)
{
  debugOnDecsn = true;
}

void DebugSng::turnOffDebug(void)
{
  debugOnDecsn = false;
}

