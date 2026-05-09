#include "core/parameter_interpreter.h"

//------------------------------------------------------------
// Return engineering interpretation for subsystem parameters
//------------------------------------------------------------
std::vector<ParameterInfo>
ParameterInterpreter::getParameterInfo(
    uint8_t subsystem_id)
{
    switch (subsystem_id)
    {
        //----------------------------------------------------
        // Propulsion System
        //----------------------------------------------------
        case 1:
            return {
                {"Thrust", "N"},
                {"EGT", "C"},
                {"Efficiency", ""}
            };

        //----------------------------------------------------
        // Flight Control System
        //----------------------------------------------------
        case 2:
            return {
                {"Angle of Attack", "deg"},
                {"Roll Rate", "deg/s"},
                {"Control Error", ""}
            };

        //----------------------------------------------------
        // Electrical Power System
        //----------------------------------------------------
        case 3:
            return {
                {"Power", "W"},
                {"Voltage Error", "V"},
                {"Load Percentage", "%"}
            };

        //----------------------------------------------------
        // Fuel System
        //----------------------------------------------------
        case 4:
            return {
                {"Fuel Flow Rate", "kg/s"},
                {"Fuel Quantity", "L"},
                {"Fuel Density", "kg/m3"}
            };

        //----------------------------------------------------
        // Hydraulic System
        //----------------------------------------------------
        case 5:
            return {
                {"Pressure", "Pa"},
                {"Flow Rate", "m3/s"},
                {"Leak Detection", ""}
            };

        //----------------------------------------------------
        // Pneumatic System
        //----------------------------------------------------
        case 6:
            return {
                {"Pressure", "Pa"},
                {"Mass Flow Rate", "kg/s"},
                {"Temperature Drop", "C"}
            };

        //----------------------------------------------------
        // Environmental Control System
        //----------------------------------------------------
        case 7:
            return {
                {"Cabin Pressure Altitude", "m"},
                {"Temperature Error", "C"},
                {"Airflow Rate", "kg/s"}
            };

        //----------------------------------------------------
        // Avionics System
        //----------------------------------------------------
        case 8:
            return {
                {"Velocity", "m/s"},
                {"Position Drift", "m"},
                {"Kalman Residual", ""}
            };

        //----------------------------------------------------
        // Unknown subsystem
        //----------------------------------------------------
        default:
            return {
                {"Unknown Param 1", ""},
                {"Unknown Param 2", ""},
                {"Unknown Param 3", ""}
            };
    }
}