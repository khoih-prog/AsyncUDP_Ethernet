/****************************************************************************************************************************
  AsyncUDP_Ethernet_Debug.h
  
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

#ifndef ASYNC_UDP_DEBUG_ETHERNET_H
#define ASYNC_UDP_DEBUG_ETHERNET_H

////////////////////////////////////////////////////////////

#ifdef ASYNC_UDP_ETHERNET_DEBUG_PORT
  #define DBG_PORT      ASYNC_UDP_ETHERNET_DEBUG_PORT
#else
  #define DBG_PORT      Serial
#endif

////////////////////////////////////////////////////////////

// Change _ASYNC_UDP_ETHERNET_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _ASYNC_UDP_ETHERNET_LOGLEVEL_
  #define _ASYNC_UDP_ETHERNET_LOGLEVEL_       0
#endif

////////////////////////////////////////////////////////////

#define UDP_LOGERROR(x)         if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>0) { DBG_PORT.print("[UDP] "); DBG_PORT.println(x); }
#define UDP_LOGERROR0(x)        if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>0) { DBG_PORT.print(x); }
#define UDP_LOGERROR1(x,y)      if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>0) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define UDP_LOGERROR2(x,y,z)    if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>0) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define UDP_LOGERROR3(x,y,z,w)  if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>0) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

////////////////////////////////////////////////////////////

#define UDP_LOGWARN(x)          if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>1) { DBG_PORT.print("[UDP] "); DBG_PORT.println(x); }
#define UDP_LOGWARN0(x)         if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>1) { DBG_PORT.print(x); }
#define UDP_LOGWARN1(x,y)       if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>1) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define UDP_LOGWARN2(x,y,z)     if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>1) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define UDP_LOGWARN3(x,y,z,w)   if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>1) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

////////////////////////////////////////////////////////////

#define UDP_LOGINFO(x)          if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>2) { DBG_PORT.print("[UDP] "); DBG_PORT.println(x); }
#define UDP_LOGINFO0(x)         if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>2) { DBG_PORT.print(x); }
#define UDP_LOGINFO1(x,y)       if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>2) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define UDP_LOGINFO2(x,y,z)     if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>2) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define UDP_LOGINFO3(x,y,z,w)   if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>2) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

////////////////////////////////////////////////////////////

#define UDP_LOGDEBUG(x)         if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>3) { DBG_PORT.print("[UDP] "); DBG_PORT.println(x); }
#define UDP_LOGDEBUG0(x)        if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>3) { DBG_PORT.print(x); }
#define UDP_LOGDEBUG1(x,y)      if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>3) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define UDP_LOGDEBUG2(x,y,z)    if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>3) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define UDP_LOGDEBUG3(x,y,z,w)  if(_ASYNC_UDP_ETHERNET_LOGLEVEL_>3) { DBG_PORT.print("[UDP] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

////////////////////////////////////////////////////////////

#endif    //ASYNC_UDP_DEBUG_ETHERNET_H
