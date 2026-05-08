#ifndef PACKET_VALIDATOR_H
#define PACKET_VALIDATOR_H
#include <sys/types.h>
#include "protocol/telemetry_packet.h"

/**
 * PacketValidator
 * Responsible for validating incoming telemetry packets.
 *
 * Validation checks:
 * - packet size
 * - synchronization header
 * - subsystem ID
 */
class PacketValidator
{
public:

    /**
     * @brief Validates received telemetry packet
     *
     * @param packet           Packet received from client
     * @param bytes_received   Number of bytes read from socket
     *
     * @return true if packet is valid
     * @return false otherwise
     */
    static bool validate(
        const TelemetryPacket& packet,
        ssize_t bytes_received);
};

#endif // PACKET_VALIDATOR_H


