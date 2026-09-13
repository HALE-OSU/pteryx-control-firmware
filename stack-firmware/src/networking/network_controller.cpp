#include "network_controller.h"
#include "serial_logger/serial_logger.h"

void NetworkController::setup() {
#if ENV_TEENSY
  // TODO: CAN communication
  // TODO: Web dashboard communication over USB
#endif  

#if ENV_SIMULATE
  ws.setup();
#endif
}

void NetworkController::loop() {
#if ENV_TEENSY
  // TODO: CAN communication
  // TODO: Web dashboard communication over USB
#endif  

#if ENV_SIMULATE
  ws.loop();
#endif
}

void NetworkController::sendPacket(uint32_t moduleId, PacketType packetType, uint8_t *data, size_t packet_length) {

  // Packet format <moduleId><packetType><data><packet_length>
  
#if ENV_TEENSY
  // TODO: CAN communication
  // TODO: Web dashboard communication over USB
#endif  

#if ENV_SIMULATE
  // TODO: websocket communication
  ws.send(data, packet_length);
#endif
}

void NetworkController::sendSensorPacket(uint32_t moduleId, uint8_t *data, size_t packet_length) {
  sendPacket(moduleId, PacketType::SENSOR, data, packet_length);
}

void NetworkController::sendActuatorPacket(uint32_t moduleId, uint8_t *data, size_t packet_length) {
  sendPacket(moduleId, PacketType::ACTUATOR, data, packet_length);
}

void NetworkController::sendCommand(uint32_t moduleId, uint8_t commandCode) {
  
#if ENV_TEENSY
  // TODO: CAN communication
  // TODO: Web dashboard communication over USB
#endif  

#if ENV_SIMULATE
  // TODO: websocket communication
#endif

  // Packet length is 1 because a commandCode is exactly 1 byte
  SerialLogger::printLine("[Networking]: Sending Command");

  sendPacket(moduleId, PacketType::COMMAND, &commandCode, 1);
}
