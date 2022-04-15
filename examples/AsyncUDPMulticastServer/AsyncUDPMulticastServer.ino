/****************************************************************************************************************************
  AsyncUDPMulticastServer.ino

  For ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library
  
  AsyncUDP_Ethernet is a Async UDP library for the ESP8266 with lwIP_5100, lwIP_5500 or lwIP_enc28j60 library
  
  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/ASYNC_UDP_Ethernet
 *****************************************************************************************************************************/
 
#include "defines.h"

#define ASYNC_UDP_ETHERNET_VERSION_MIN_TARGET      "AsyncUDP_Ethernet v1.2.1"
#define ASYNC_UDP_ETHERNET_VERSION_MIN             1002001

#include <Ticker.h>

AsyncUDP udp;

// 600s = 10 minutes to not flooding, 60s in testing
#define UDP_REQUEST_INTERVAL     60

void sendRequest();

// Repeat forever, millis() resolution
//Ticker sendUDPRequest(sendRequest, UDP_REQUEST_INTERVAL_MS, 0, MILLIS); 
Ticker sendUDPRequest;

void sendRequest()
{
  UDP_LOGDEBUG("Send multicast");
  
  //Send multicast
  udp.print("Anyone here?");
}

void parsePacket(AsyncUDPPacket packet)
{
  Serial.print("UDP Packet Type: ");
  Serial.print(packet.isBroadcast() ? "Broadcast" : packet.isMulticast() ? "Multicast" : "Unicast");
  Serial.print(", From: ");
  Serial.print(packet.remoteIP());
  Serial.print(":");
  Serial.print(packet.remotePort());
  Serial.print(", To: ");
  Serial.print(packet.localIP());
  Serial.print(":");
  Serial.print(packet.localPort());
  Serial.print(", Length: ");
  Serial.print(packet.length());
  Serial.print(", Data: ");
  Serial.write(packet.data(), packet.length());
  Serial.println();
  //reply to the client
  packet.printf("Got %u bytes of data", packet.length());
}

void initEthernet()
{
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);

#if !USING_DHCP
  eth.config(localIP, gateway, netMask, gateway);
#endif
  
  eth.setDefault();
  
  if (!eth.begin()) 
  {
    Serial.println("No Ethernet hardware ... Stop here");
    
    while (true) 
    {
      delay(1000);
    }
  } 
  else 
  {
    Serial.print("Connecting to network : ");
    
    while (!eth.connected()) 
    {
      Serial.print(".");
      delay(1000);
    }
  }
 
  Serial.println();

#if USING_DHCP  
  Serial.print("Ethernet DHCP IP address: ");
#else
  Serial.print("Ethernet Static IP address: ");
#endif
  
  Serial.println(eth.localIP());
}

void setup()
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  delay(200);

  Serial.print("\nStart AsyncUDPMulticastServer on "); Serial.print(BOARD_NAME);
  Serial.print(" with "); Serial.println(SHIELD_TYPE);
  Serial.println(ASYNC_UDP_ETHERNET_VERSION);

  initEthernet();

  if (udp.listenMulticast(IPAddress(239, 1, 2, 3), 1234))
  {
    Serial.print("UDP Listening on IP: ");
    Serial.println(eth.localIP());

    udp.onPacket([](AsyncUDPPacket packet)
    {
      parsePacket(packet);
    });

    //Send multicast
    udp.print("Hello!");
  }

  sendRequest();

  sendUDPRequest.attach(UDP_REQUEST_INTERVAL, sendRequest);
}

void loop()
{
  delay(1);
}
