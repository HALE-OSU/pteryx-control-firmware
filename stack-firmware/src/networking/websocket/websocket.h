#pragma once

#include <cstdio>
#include <cstdint>
#include <string>
#include "easywsclient.hpp"

// Inlcude windows socket
#ifdef _WIN32
#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#endif

using easywsclient::WebSocket;

class Websocket {
    easywsclient::WebSocket::pointer ws;

   public:
    void setup();
    void loop();

    void send(uint8_t* data, size_t packetSize);
};