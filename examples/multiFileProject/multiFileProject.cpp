/****************************************************************************************************************************
  multiFileProject.cpp
  For ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library

  AsyncUDP_Ethernet is a Async UDP library for the ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library

  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/ASYNC_UDP_Ethernet
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#include "multiFileProject.h"

#if USING_W5500
  Wiznet5500lwIP eth(CSPIN);
#elif USING_W5100
  Wiznet5100lwIP eth(CSPIN);
#elif USING_ENC28J60
  ENC28J60lwIP eth(CSPIN);
#else
  // default if none selected
  Wiznet5500lwIP eth(CSPIN);
#endif
