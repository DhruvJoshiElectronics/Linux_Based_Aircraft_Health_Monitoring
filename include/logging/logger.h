#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "protocol/telemetry_packet.h"

class Logger
{
public:
    static void logTelemetry(const TelemetryPacket& packet);
    static void logAlert(const std::string& message);
};

#endif // LOGGER_H