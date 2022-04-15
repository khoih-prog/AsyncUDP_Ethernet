/****************************************************************************************************************************
  AsyncUDP_Ethernet.h
  
  For ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library
  
  AsyncUDP_Ethernet is a Async UDP library for the ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library
  
  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/ASYNC_UDP_Ethernet
  
  Version: 1.2.1
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.2.1   K Hoang      15/04/2022 Initial coding for ESP8266 using W5x00/ENC8266 Ethernet.
                                  Bump up version to v1.2.1 to sync with AsyncUDP_STM32 v1.2.1        
 *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_UDP_ETHERNET_H
#define ASYNC_UDP_ETHERNET_H

#if !defined(ESP8266)
  #error This code is currently intended to run only on the ESP8266 platform
#endif 

#define ASYNC_UDP_ETHERNET_VERSION            "AsyncUDP_Ethernet v1.2.1"

#define ASYNC_UDP_ETHERNET_VERSION_MAJOR      1
#define ASYNC_UDP_ETHERNET_VERSION_MINOR      2
#define ASYNC_UDP_ETHERNET_VERSION_PATCH      1

#define ASYNC_UDP_ETHERNET_VERSION_INT        1002001

////////////////////////////////////////////////////////////

#if defined(ESP8266)
  #ifndef BOARD_NAME
	  #if defined(ARDUINO_BOARD)
	    #define BOARD_NAME			ARDUINO_BOARD
	  #else
	    #define BOARD_NAME			"ESP8266"
	  #endif	
  #endif

	#define EthernetInterface		eth
#endif		// ESP8266

////////////////////////////////////////////////////////////

#include "AsyncUDP_Ethernet.hpp"
#include "AsyncUDP_Ethernet_Impl.h"

#endif    //ASYNC_UDP_ETHERNET_H
