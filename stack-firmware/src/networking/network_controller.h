#pragma once

#include <cstdint>

#ifdef ENV_TEENSY
// TODO: CAN communication
// TODO: Web dashboard communication over USB
#endif

#ifdef ENV_SIMULATE
#include "websocket/websocket.h"
#endif

enum class PacketType {
  SENSOR,
  ACTUATOR,
  COMMAND
};


class NetworkController {
  private:
#ifdef ENV_TEENSY
  // TODO: CAN communication
  // TODO: Web dashboard communication over USB
#endif

#ifdef ENV_SIMULATE

  Websocket ws;
#endif

  void sendPacket(uint32_t moduleId, PacketType packetType, uint8_t *data, size_t packet_length);

  public: 

  /** Setup the network controller */
  void setup();  

  /** Listen for incoming data */
  void loop();

  void sendSensorPacket(uint32_t moduleId, uint8_t *data, size_t packet_length);

  void sendActuatorPacket(uint32_t moduleId, uint8_t *data, size_t packet_length);

  void sendCommand(uint32_t moduleId, uint8_t commandCode);

  /** Registers a function that will be called when an actuator data packer is received for a specific module. */
  void registerActuatorPacketCallback(uint32_t moduleId);

  /** Registers a function that will be called when a command code is received for a specific module.
   * @param moduleId - the ID of the module to target. Pass -1 for commands meant for the Pteryx stack rather than a specific module. */
  void registerCommandPacketCallback(uint32_t moduleId);
};
