// Includes
#include "logging/logger.h"
#include <fstream>
#include <ctime>
#include "core/subsystem_parser.h"

// Log Telemetry Packet
void Logger::logTelemetry(const TelemetryPacket& packet)
{
    // Open telemetry CSV log file
    std::ofstream log_file("telemetry_log.csv",std::ios::app);

    // Validate file open
    if (!log_file.is_open())
    {
        return;
    }

    // Write CSV telemetry entry
    log_file << packet.timestamp << "," << SubsystemParser::getSubsystemName(packet.subsystem_id) << ","
        << packet.param1 << ","
        << packet.param2 << ","
        << packet.param3
        << "\n";

    // Close file
    log_file.close();
}

// Log Alert Message
void Logger::logAlert(const std::string& message)
{
    // Open alert log file
    std::ofstream log_file("alert_log.txt",std::ios::app);

    // Validate file open
    if (!log_file.is_open())
    {
        return;
    }
    // Current timestamp
    std::time_t now = std::time(nullptr);
    // Write alert entry
    log_file << "[" << now << "] " << message << "\n";
    // Close file
    log_file.close();
}