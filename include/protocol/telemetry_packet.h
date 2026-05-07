#ifndef TELEMETRY_PACKET_H
#define TELEMETRY_PACKET_H

#include <cstdint>

/**
 * ------------------------------------------------------------
 * Packet Header Definitions
 * ------------------------------------------------------------
 * Fixed synchronization byte
 */
constexpr uint8_t PACKET_HEADER = 0xAA;

/**
 * ------------------------------------------------------------
 * Subsystem IDs
 * ------------------------------------------------------------
 */
enum class SubsystemID : uint8_t {
    PROPULSION     = 1,
    FLIGHT_CONTROL = 2,
    ELECTRICAL     = 3,
    FUEL           = 4,
    HYDRAULIC      = 5,
    PNEUMATIC      = 6,
    ECS            = 7,
    AVIONICS       = 8
};

/**
 * ------------------------------------------------------------
 * Binary Telemetry Packet
 * ------------------------------------------------------------
 *
 * This structure represents one telemetry message
 * transmitted from client → server.
 *
 * Packet Layout:
 * * +------------+---------------+-------------+
 * | Field      | Type          | Size        |
 * +------------+---------------+-------------+
 * | Header     | uint8_t       | 1 byte      |
 * | Subsystem  | uint8_t       | 1 byte      |
 * | Timestamp  | uint32_t      | 4 bytes     |
 * | Param1     | float         | 4 bytes     |
 * | Param2     | float         | 4 bytes     |
 * | Param3     | float         | 4 bytes     |
 * +------------+---------------+-------------+
 *
 * Total: 18 bytes
 *
 * IMPORTANT:
 * pragma pack ensures compiler does NOT add padding bytes.
 */
#pragma pack(push, 1)

struct TelemetryPacket {
    // Synchronization / validation byte
    uint8_t header;
    // Aircraft subsystem identifier
    uint8_t subsystem_id;
    // timestamp
    uint32_t timestamp;
    // Physics-based telemetry parameters
    float param1;
    float param2;
    float param3;
};

#pragma pack(pop)

#endif // TELEMETRY_PACKET_H