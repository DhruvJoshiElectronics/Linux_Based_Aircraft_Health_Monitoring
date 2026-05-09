#ifndef SUBSYSTEM_PARSER_H
#define SUBSYSTEM_PARSER_H

#include <string>
#include <cstdint>

/**
 * ------------------------------------------------------------
 * SubsystemParser
 * ------------------------------------------------------------
 *
 * Responsible for converting subsystem IDs
 * into meaningful subsystem names.
 */
class SubsystemParser
{
public:

    /**
     * @brief Returns subsystem name
     *        corresponding to subsystem ID.
     *
     * @param subsystem_id Numeric subsystem identifier
     *
     * @return Human-readable subsystem name
     */
    static std::string getSubsystemName(
        uint8_t subsystem_id);
};

#endif // SUBSYSTEM_PARSER_H