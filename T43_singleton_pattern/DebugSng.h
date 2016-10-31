/**
 * @file  Debug.h
 * @brief This is the Debug singleton class header file.
 * @author  Hassin Ayaz 
 * @date 08/13/2016
 * @debugType: this could be one of the following
 * #info
 * #debug
 * #error
 * #warn
 * #none
 */

#include <Arduino.h> //needed for NULL and F_CPU macro recognition

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* User setting -> Output pin the software UART */
#define DBG_UART_TX_PORT  PORTC
#define DBG_UART_TX_DDR   DDRC
#define DBG_UART_TX_PIN   PC5      //arduino Uno A5 no pin

/* User setting -> Software UART baudrate. */
#define DBG_UART_BAUDRATE 4800

#ifndef F_CPU
  #define F_CPU 16000000
#endif

#define DBG_UART_TX_NUM_DELAY_CYCLES  ((F_CPU/DBG_UART_BAUDRATE-16)/4+1)
#define DBG_UART_TX_NUM_ADD_NOP   ((F_CPU/DBG_UART_BAUDRATE-16)%4)

///DebugSNG is a singleton class 
class DebugSng
{
private:
    static bool instanceFlag;
    static DebugSng* single;
    DebugSng();
    void dbg_putchar(uint8_t c);
    void printFlashString(const __FlashStringHelper* str);
    void printLineFeed(void);
    bool debugOnDecsn; 
public:
    static DebugSng* getInstance();
    void debugPrintln(const __FlashStringHelper* moduleName,const __FlashStringHelper* debugType, const __FlashStringHelper* msg);
    void turnOnDebug(void);
    void turnOffDebug(void);
    ~DebugSng();
};


