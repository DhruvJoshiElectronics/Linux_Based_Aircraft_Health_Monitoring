#ifndef ALERT_ENGINE_H
#define ALERT_ENGINE_H

#include "protocol/telemetry_packet.h"

// Alert Engine
class AlertEngine
{
public:
    // Analyze telemetry packet
    static void analyze(
        const TelemetryPacket& packet);

private:

    // Subsystem-specific monitoring
    static void analyzePropulsion(const TelemetryPacket& packet);
    static void analyzeHydraulic(const TelemetryPacket& packet);
};

#endif // ALERT_ENGINE_H