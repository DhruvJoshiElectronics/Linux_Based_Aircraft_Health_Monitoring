#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

// Includes
#include <string>
#include <unordered_map>

// Config Manager
class ConfigManager
{
public:

    // Load configuration file
    static bool loadConfig(const std::string& filename);

    // Get threshold value
    static float getValue(const std::string& key);

private:
    // Internal configuration storage
    static std::unordered_map<
        std::string,
        float> config_map;
};

#endif // CONFIG_MANAGER_H