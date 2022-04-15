# AsyncUDP_Ethernet


[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_Ethernet.svg?)](https://www.ardu-badge.com/AsyncUDP_Ethernet)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncUDP_Ethernet.svg)](https://github.com/khoih-prog/AsyncUDP_Ethernet/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncUDP_Ethernet.svg)](http://github.com/khoih-prog/AsyncUDP_Ethernet/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents


* [Why do we need this AsyncUDP_Ethernet library](#why-do-we-need-this-AsyncUDP_Ethernet-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)
* [HOWTO Setting up the Async UDP Client](#howto-setting-up-the-async-udp-client)
* [Examples](#examples)
  * [ 1. AsyncUDPClient](examples/AsyncUDPClient)
  * [ 2. AsyncUDPMulticastServer](examples/AsyncUDPMulticastServer)
  * [ 3. AsyncUdpNTPClient](examples/AsyncUdpNTPClient)
  * [ 4. AsyncUdpSendReceive](examples/AsyncUdpSendReceive)
  * [ 5. AsyncUDPServer](examples/AsyncUDPServer) 
  * [ 6. multiFileProject](examples/multiFileProject)
* [Example AsyncUdpNTPClient](#example-asyncudpntpclient)
  * [1. File AsyncUdpNTPClient.ino](#1-file-asyncudpntpclientino)
  * [2. File defines.h](#2-file-definesh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. AsyncUdpNTPClient on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet](#1-AsyncUdpNTPClient-on-ESP8266_NODEMCU_ESP12E-with-ESP8266_W5500-Ethernet)
  * [2. AsyncUDPSendReceive on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet](#2-AsyncUDPSendReceive-on-ESP8266_NODEMCU_ESP12E-with-ESP8266_W5500-Ethernet)
  * [3. AsyncUdpNTPClient on ESP8266_NODEMCU_ESP12E with ESP8266_ENC28J60 Ethernet](#3-AsyncUdpNTPClient-on-ESP8266_NODEMCU_ESP12E-with-ESP8266_ENC28J60-Ethernet)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [AsyncUDP_Ethernet library](https://github.com/khoih-prog/AsyncUDP_Ethernet)

#### Features

This [AsyncUDP_Ethernet library](https://github.com/khoih-prog/AsyncUDP_Ethernet) is a fully asynchronous UDP library, designed for a trouble-free, multi-connection network environment, for **ESP8266 boards using W5x00 or ENC28J60 Ethernet** using [**lwIP_w5100**](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5100), [**lwIP_w5500**](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5500) or [**lwIP_enc28j60**](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_enc28j60) library.

The library is easy to use and includes support for Unicast, Broadcast and Multicast environments.

This library is based on, modified from:

1. [Hristo Gochkov's ESPAsyncUDP](https://github.com/me-no-dev/ESPAsyncUDP)

to apply the better and faster **asynchronous** feature of the **powerful** [ESPAsyncUDP Library](https://github.com/me-no-dev/ESPAsyncUDP) into **ESP8266 boards using W5x00 or ENC28J60 Ethernet**


#### Why Async is better

- Using asynchronous network means that you can handle **more than one connection at the same time**
- You are called once the request is ready and parsed
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- After connecting to a UDP server as an Async Client, you are **immediately ready** to handle other connections while the Client is taking care of receiving the UDP responding packets in the background.
- You are not required to check in a tight loop() the arrival of the UDP responding packets to process them.


### Currently Supported Boards

1. **ESP8266 boards using W5x00 or ENC28J60 Ethernet**

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/).
 
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `AsyncUDP_Ethernet`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_Ethernet.svg?)](https://www.ardu-badge.com/AsyncUDP_Ethernet) for more detailed instructions.

### Manual Install

1. Navigate to [AsyncUDP_Ethernet](https://github.com/khoih-prog/AsyncUDP_Ethernet) page.
2. Download the latest release `AsyncUDP_Ethernet-master.zip`.
3. Extract the zip file to `AsyncUDP_Ethernet-master` directory 
4. Copy the whole `AsyncUDP_Ethernet-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AsyncUDP_Ethernet** library](https://registry.platformio.org/libraries/khoih-prog/AsyncUDP_Ethernet) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/AsyncUDP_Ethernet/installation). Search for AsyncUDP_Ethernet in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using `xyz-Impl.h` instead of standard `xyz.cpp`, possibly creates certain `Multiple Definitions` Linker error in certain use cases.

You can include this `.hpp` file

```
// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "AsyncUDP_Ethernet.hpp"         //https://github.com/khoih-prog/AsyncUDP_Ethernet
```

in many files. But be sure to use the following `.h` file **in just 1 `.h`, `.cpp` or `.ino` file**, which must **not be included in any other file**, to avoid `Multiple Definitions` Linker Error

```
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "AsyncUDP_Ethernet.h"           //https://github.com/khoih-prog/AsyncUDP_Ethernet
```

Check the new [**multiFileProject** example](examples/multiFileProject) for a `HOWTO` demo.

Have a look at the discussion in [Different behaviour using the src_cpp or src_h lib #80](https://github.com/khoih-prog/ESPAsync_WiFiManager/discussions/80)


---
---


## HOWTO Setting up the Async UDP Client

```cpp

#include <AsyncUDP_Ethernet.h>

IPAddress timeWindowsCom = IPAddress(13, 86, 101, 172);

#define NTP_REQUEST_PORT      123

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
AsyncUDP Udp;

// send an NTP request to the time server at the given address
void createNTPpacket(void)
{
  ...
}

void sendNTPPacket(void)
{
  createNTPpacket();
  //Send unicast
  Udp.write(packetBuffer, sizeof(packetBuffer));
}

void parsePacket(AsyncUDPPacket packet)
{
  ...
}

void setup()
{
  ...
  
  //NTP requests are to port NTP_REQUEST_PORT = 123
  if (Udp.connect(timeWindowsCom, NTP_REQUEST_PORT))
  {
    // Setting up Async packet Handler
    Udp.onPacket([](AsyncUDPPacket packet)
    {
      parsePacket(packet);
    });
  }
}

void loop()
{
  sendNTPPacket();

  // wait 60 seconds before asking for the time again
  delay(60000);
}
```

---
---

### Examples

 1. [AsyncUDPClient](examples/AsyncUDPClient)
 2. [AsyncUDPMulticastServer](examples/AsyncUDPMulticastServer)
 3. [AsyncUdpNTPClient](examples/AsyncUdpNTPClient)
 4. [AsyncUdpSendReceive](examples/AsyncUdpSendReceive) 
 5. [AsyncUDPServer](examples/AsyncUDPServer)
 6. [multiFileProject](examples/multiFileProject)

---

### Example [AsyncUdpNTPClient](examples/AsyncUdpNTPClient)

#### 1. File [AsyncUdpNTPClient.ino](examples/AsyncUdpNTPClient/AsyncUdpNTPClient.ino)

https://github.com/khoih-prog/AsyncUDP_Ethernet/blob/91ea83c3a9a281b4d7cceaa698f9b2696b93483a/examples/AsyncUdpNTPClient/AsyncUdpNTPClient.ino#L12-L194


#### 2. File [defines.h](examples/AsyncUdpNTPClient/defines.h)

https://github.com/khoih-prog/AsyncUDP_Ethernet/blob/91ea83c3a9a281b4d7cceaa698f9b2696b93483a/examples/AsyncUdpNTPClient/defines.h#L12-L74


---
---

### Debug Terminal Output Samples

#### 1. AsyncUdpNTPClient on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet

This is terminal debug output when running [AsyncUdpNTPClient](examples/AsyncUdpNTPClient) on **ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet**. It connects to NTP Server "0.ca.pool.ntp.org" (IPAddress(208, 81, 1, 244)) using AsyncUDP_Ethernet library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.


```
Start AsyncUdpNTPClient on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet
AsyncUDP_Ethernet v1.2.1
Connecting to network : ..
Ethernet DHCP IP address: 192.168.2.188
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.188:56234, Length: 48
Seconds since Jan 1 1900 = 3858990229
Epoch/Unix time = 1650001429
The UTC/GMT time is Fri 2022-04-15 05:43:49 GMT
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.188:56234, Length: 48
Seconds since Jan 1 1900 = 3858990289
Epoch/Unix time = 1650001489
The UTC/GMT time is Fri 2022-04-15 05:44:49 GMT
```

---

#### 2. AsyncUDPSendReceive on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet

This is terminal debug output when running [AsyncUDPSendReceive](examples/AsyncUDPSendReceive) on **ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet**. It connects to NTP Server "time.nist.gov" (IPAddress(208, 81, 1, 244)) using AsyncUDP_Ethernet library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.

```
Start AsyncUDPSendReceive on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet
AsyncUDP_Ethernet v1.2.1
Connecting to network : .
Ethernet DHCP IP address: 192.168.2.188

Starting connection to server...
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.188:63199, Length: 48
Seconds since Jan 1 1900 = 3859022269
Epoch/Unix time = 1650033469
The UTC/GMT time is Fri 2022-04-15 14:37:49 GMT
============= sendACKPacket =============
```

---

#### 3. AsyncUdpNTPClient on ESP8266_NODEMCU_ESP12E with ESP8266_ENC28J60 Ethernet

This is terminal debug output when running [AsyncUdpNTPClient](examples/AsyncUdpNTPClient) on **ESP8266_NODEMCU_ESP12E with ESP8266_ENC28J60 Ethernet**. It connects to NTP Server "0.ca.pool.ntp.org" (IPAddress(208, 81, 1, 244)) using AsyncUDP_Ethernet library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.


```
Start AsyncUdpNTPClient on ESP8266_NODEMCU_ESP12E with ESP8266_W5500 Ethernet
AsyncUDP_Ethernet v1.2.1
Connecting to network : ..
Ethernet DHCP IP address: 192.168.2.188
UDP connected
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.188:56234, Length: 48
Seconds since Jan 1 1900 = 3858990229
Epoch/Unix time = 1650001429
The UTC/GMT time is Fri 2022-04-15 05:43:49 GMT
============= createNTPpacket =============
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.188:56234, Length: 48
Seconds since Jan 1 1900 = 3858990289
Epoch/Unix time = 1650001489
The UTC/GMT time is Fri 2022-04-15 05:44:49 GMT
```


---
---

### Debug

Debug is enabled by default on Serial. To disable, use level 0

```cpp
#define ASYNC_UDP_ETHERNET_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_ETHERNET_LOGLEVEL_      0
```

You can also change the debugging level from 0 to 4

```cpp
#define ASYNC_UDP_ETHERNET_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_ETHERNET_LOGLEVEL_      4
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of Arduino IDE, the Arduino `STM32` core or depending libraries.

Sometimes, the library will only work if you update the `STM32` core to the latest version because I am always using the latest cores /libraries.

---
---


### Issues ###

Submit issues to: [AsyncUDP_Ethernet issues](https://github.com/khoih-prog/AsyncUDP_Ethernet/issues)

---

## TO DO

 1. Fix bug. Add enhancement

---

## DONE

 1. Initial porting and coding for **ESP8266 using W5x00 or ENC28J60 Ethernet** using [**lwIP_w5100**](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5100), [**lwIP_w5500**](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_w5500) or [**lwIP_enc28j60**](https://github.com/esp8266/Arduino/tree/master/libraries/lwIP_enc28j60) library.
 2. Add more examples.
 3. Add debugging features.

---
---

### Contributions and Thanks

1. Based on and modified from [Hristo Gochkov's ESPAsyncUDP](https://github.com/me-no-dev/ESPAsyncUDP). Many thanks to [Hristo Gochkov](https://github.com/me-no-dev) for good [ESPAsyncUDP Library](https://github.com/me-no-dev/ESPAsyncUDP)


<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br /><sub><b>⭐️⭐️ Hristo Gochkov</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/AsyncUDP_Ethernet/blob/main/LICENSE)

---

## Copyright

- Copyright 2016- Hristo Gochkov
- Copyright 2022- Khoi Hoang


