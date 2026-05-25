
#include "config/config_manager.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::unordered_map<
    std::string,
    float> ConfigManager::config_map;

bool ConfigManager::loadConfig(
    const std::string& filename)
{
    std::ifstream config_file(filename);

    if (!config_file.is_open())
    {
        std::cerr
            << "[ERROR] Failed to open config file\n";

        return false;
    }

    std::string line;

    while (std::getline(config_file, line))
    {

        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        //----------------------------------------------------
        // Parse key=value
        std::stringstream ss(line);

        std::string key;
        std::string value;

        if (std::getline(ss, key, '=') &&
            std::getline(ss, value))
        {
            config_map[key] =
                std::stof(value);
        }
    }

    // Close file
    config_file.close();

    std::cout << "[INFO] Configuration loaded successfully\n";

    return true;
}

// Get Configuration Value
float ConfigManager::getValue(const std::string& key)
{
    // Check if key exists
    if (config_map.find(key)!= config_map.end())
    {
        return config_map[key];
    }

    // Missing key
    std::cerr << "[WARNING] Missing config key: "<< key << "\n";
    return 0.0f;
}