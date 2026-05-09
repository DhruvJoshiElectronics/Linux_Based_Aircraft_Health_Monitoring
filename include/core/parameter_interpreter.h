#ifndef PARAMETER_INTERPRETER_H
#define PARAMETER_INTERPRETER_H

#include <vector>
#include <string>
#include <cstdint>

/**
 * ------------------------------------------------------------
 * ParameterInfo
 * ------------------------------------------------------------
 *
 * Represents engineering meaning of telemetry parameter.
 */
struct ParameterInfo
{
    std::string name;
    std::string unit;
};

/**
 * ------------------------------------------------------------
 * ParameterInterpreter
 * ------------------------------------------------------------
 *
 * Responsible for converting generic telemetry
 * parameters into engineering-aware meanings.
 */
class ParameterInterpreter
{
public:

    /**
     * @brief Returns parameter interpretation
     *        for a subsystem.
     *
     * @param subsystem_id Aircraft subsystem ID
     *
     * @return Vector containing parameter metadata
     */
    static std::vector<ParameterInfo>
    getParameterInfo(uint8_t subsystem_id);
};

#endif // PARAMETER_INTERPRETER_H