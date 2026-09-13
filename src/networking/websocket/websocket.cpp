#include "websocket.h"

void Websocket::setup() {
    // Setup windows socket
#ifdef _WIN32
    INT rc;
    WSADATA wsaData;

    rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc) {
        printf("WSAStartup Failed.\n");
        return;
    }
#endif

    ws = easywsclient::WebSocket::from_url("ws://localhost:8080");
    if (!ws) {
        printf("failed to connect\n");
        return;
    }

    ws->send("hello from native sim");
}

void Websocket::loop() {
    if (ws->getReadyState() != WebSocket::CLOSED) {
        ws->poll(100);  // ms timeout
        ws->dispatch([](const std::string& msg) {
            printf("received: %s\n", msg.c_str());
        });
    }
}