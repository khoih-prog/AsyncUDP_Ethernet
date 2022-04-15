/****************************************************************************************************************************
  multiFileProject.ino
  For ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library
  
  AsyncUDP_Ethernet is a Async UDP library for the ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library
  
  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/ASYNC_UDP_Ethernet
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#if !defined(ESP8266)
  #error Only ESP8266 supported
#endif

#define ASYNC_UDP_ETHERNET_VERSION_MIN_TARGET      "AsyncUDP_Ethernet v1.2.1"
#define ASYNC_UDP_ETHERNET_VERSION_MIN             1002001

#include "multiFileProject.h"

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include <AsyncUDP_Ethernet.h>        // https://github.com/khoih-prog/AsyncUDP_Ethernet

void setup() 
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);
 
  Serial.println("\nStart multiFileProject");
  Serial.println(ASYNC_UDP_ETHERNET_VERSION);

#if defined(ASYNC_UDP_ETHERNET_VERSION_MIN)
  if (ASYNC_UDP_ETHERNET_VERSION_INT < ASYNC_UDP_ETHERNET_VERSION_MIN)
  {
    Serial.print("Warning. Must use this example on Version equal or later than : ");
    Serial.println(ASYNC_UDP_ETHERNET_VERSION_MIN_TARGET);
  }
#endif

  Serial.print("You're OK now");
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
