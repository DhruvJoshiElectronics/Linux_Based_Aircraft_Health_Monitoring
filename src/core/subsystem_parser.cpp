#include "core/subsystem_parser.h"

//------------------------------------------------------------
// Convert subsystem ID to readable subsystem name
//------------------------------------------------------------
std::string SubsystemParser::getSubsystemName(
    uint8_t subsystem_id)
{
    switch (subsystem_id)
    {
        case 1:
            return "Propulsion System";

        case 2:
            return "Flight Control System";

        case 3:
            return "Electrical Power System";

        case 4:
            return "Fuel System";

        case 5:
            return "Hydraulic System";

        case 6:
            return "Pneumatic System";

        case 7:
            return "Environmental Control System";

        case 8:
            return "Avionics System";

        default:
            return "Unknown Subsystem";
    }
}