#include "core/packet_validator.h"
#include <iostream>

// Validate Telemetry Packet
bool PacketValidator::validate(const TelemetryPacket& packet,ssize_t bytes_received)
{
    // Validate packet size
    if (bytes_received != sizeof(TelemetryPacket))
    {
        std::cerr
            << "[VALIDATOR] Invalid packet size\n";

        return false;
    }

    /*
     * Important:
     * TCP may return:
     * - partial packets
     * - incomplete reads
     *
     * Packet size mismatch indicates:
     * protocol violation or transmission issue.
     */
     // Validate synchronization header
     if (packet.header != PACKET_HEADER)
    {
        std::cerr
            << "[VALIDATOR] Invalid packet header\n";

        return false;
    }

     /*
     * Header acts as synchronization marker.
     *
     * Helps detect:
     * - corrupted packets
     * - random data
     * - desynchronization
     */
     // Validate subsystem ID range
      if (packet.subsystem_id < 1 || packet.subsystem_id > 8)
    {
        std::cerr
            << "[VALIDATOR] Invalid subsystem ID\n";

        return false;
    }
    /*
     * Prevents undefined subsystem processing.
     */

     //Packet is valid
    return true;
}