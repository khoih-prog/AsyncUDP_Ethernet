/****************************************************************************************************************************
  multiFileProject.h
  For ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library

  AsyncUDP_Ethernet is a Async UDP library for the ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library

  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/ASYNC_UDP_Ethernet
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#pragma once

#define _AWS_ETHERNET_LOGLEVEL_       1

//////////////////////////////////////////////////////////

#define USING_W5500         true
#define USING_W5100         false
#define USING_ENC28J60      false

#include <SPI.h>

#define CSPIN       16      // 5

#if USING_W5500
  #include "W5500lwIP.h"
  #define SHIELD_TYPE       "ESP8266_W5500 Ethernet"

  extern Wiznet5500lwIP eth;

#elif USING_W5100
  #include <W5100lwIP.h>
  #define SHIELD_TYPE       "ESP8266_W5100 Ethernet"

  extern Wiznet5100lwIP eth;

#elif USING_ENC28J60
  #include <ENC28J60lwIP.h>
  #define SHIELD_TYPE       "ESP8266_ENC28J60 Ethernet"

  extern ENC28J60lwIP eth;
#else
  // default if none selected
  #include "W5500lwIP.h"

  #define SHIELD_TYPE       "ESP8266_W5500 Ethernet"

  extern Wiznet5500lwIP eth;
#endif

#include <WiFiClient.h> // WiFiClient (-> TCPClient)

using TCPClient = WiFiClient;

//////////////////////////////////////////////////////////

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include <AsyncUDP_Ethernet.hpp>        // https://github.com/khoih-prog/AsyncUDP_Ethernet
