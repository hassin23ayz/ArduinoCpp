#ifndef COMM_H
#define COMM_H

#include <Arduino.h>

class ListElement
{
  private:
    char* domainName;
    char* ipAddress;
    char* macId; 
  public:
    void setDomainName(const char* dn); {}
    void setIpAddress(const uint8_t* ipAddr); {}
    void setMacId(const char* mId); {}

    void getDomainName(char* buf_dn); {}
    void getIpAddress(char* buf_ip); {} 
    void getMacId(char* buf_mId); {}
};
#endif 
