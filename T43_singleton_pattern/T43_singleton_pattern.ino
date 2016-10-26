/*
 * @brief: this skecth will use a debug object from a singleton class 
 * the DebugSNG class will show the singleton pattern
 */

#include "DebugSng.h"

void setup() 
{
    DebugSng* dbg1;
    dbg1 = DebugSng::getInstance();
    dbg1->debugPrintln(F("main"),F("info"),F("this is Debug 1"));
    
    DebugSng* dbg2;
    dbg2 = DebugSng::getInstance();
    dbg2->turnOffDebug();
    dbg2->debugPrintln(F("main"),F("info"),F("this is Debug 2"));
    dbg2->turnOnDebug();
    dbg2->debugPrintln(F("main"),F("critical"),F("next statement wont compile"));

    //DebugSng dbg3; //wont compile as constructor is private
}

void loop() 
{

}
