
#include "monitoring/alert_engine.h"
#include "logging/logger.h"
#include <iostream>

void AlertEngine::analyze(const TelemetryPacket& packet)
{
    switch (packet.subsystem_id)
    {
        case static_cast<uint8_t>(SubsystemID::PROPULSION):

            analyzePropulsion(packet);
            break;

        case static_cast<uint8_t>(SubsystemID::HYDRAULIC):

            analyzeHydraulic(packet);
            break;

        default:
            break;
    }
}

// Propulsion Monitoring Logic
void AlertEngine::analyzePropulsion(const TelemetryPacket& packet)
{
    // Parameter Mapping
    float thrust     = packet.param1;
    float egt        = packet.param2;
    float efficiency = packet.param3;

    
    // High EGT Detection
    if (egt > 700.0f)
    {
        std::string warning = "[WARNING] High propulsion EGT detected";
        std::cout << warning << "\n";
        Logger::logAlert(warning);
    }

    // Low Efficiency Detection
    if (efficiency < 0.82f)
    {
        std::string warning = "[WARNING] Low engine efficiency detected";
        std::cout << warning << "\n";
        Logger::logAlert(warning);
    }

    // Excessive Thrust Detection
    if (thrust > 13000.0f)
    {
        std::string warning = "[WARNING] Excessive thrust condition detected";
        std::cout << warning << "\n";
        Logger::logAlert(warning);
    }
}

void AlertEngine::analyzeHydraulic(const TelemetryPacket& packet)
{
    float pressure    = packet.param1;
    float flow_rate   = packet.param2;
    float fluid_temp  = packet.param3;


    if (pressure < 2800.0f)
    {
        std::cout
            << "[WARNING] Low hydraulic pressure detected\n";
    }


    if (fluid_temp > 82.0f)
    {
        std::cout
            << "[WARNING] Hydraulic fluid overheating detected\n";
    }

    if (flow_rate > 52.0f)
    {
        std::cout
            << "[WARNING] Abnormal hydraulic flow rate detected\n";
    }
}