#include "websocket.h"
#include "serial_logger/serial_logger.h"
#include <vector>

void Websocket::setup() {
    // Setup windows socket
#ifdef _WIN32
    INT rc;
    WSADATA wsaData;

    rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc) {
        printf("WSAStartup Failed.\n");
        SerialLogger::logError("Websockets started failed");
        return;
    }
#endif

    ws = easywsclient::WebSocket::from_url("ws://localhost:8080");
    if (!ws) {
        // TODO: error log
        SerialLogger::logError(
            "Failed to connect to websockets at ws://localhost:8080. Is the "
            "dashboard running?");

        return;
    }

    // ws->send("hello from native sim");
}

void Websocket::loop() {
    if (!ws) return;

    if (ws->getReadyState() != WebSocket::CLOSED) {
        ws->poll(100);  // ms timeout
        ws->dispatch([](const std::string& msg) {
            printf("received: %s\n", msg.c_str());
        });
    }
}

void Websocket::send(uint8_t* data, size_t packetSize) {
    if (!ws) return;

    // TODO: move to shared scope
    std::vector<uint8_t> dataVec;
    dataVec.reserve(packetSize);

    for (int i = 0; i < packetSize; i++) {
        dataVec.push_back(data[i]);
    }

    printf("COMMAND DATA %d\n", dataVec.at(0));

    ws->sendBinary(dataVec);

    dataVec.clear();
}
