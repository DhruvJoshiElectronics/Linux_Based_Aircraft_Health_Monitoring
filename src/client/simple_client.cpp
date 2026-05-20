#include <iostream>
#include <unistd.h>         // close()
#include <arpa/inet.h>      // socket APIs
#include <cstring>          // strlen
#include <ctime>
#include <thread>
#include <chrono>
#include <cmath>
#include "protocol/telemetry_packet.h"

/**
 * ------------------------------------------------------------
 * TestMode
 * ------------------------------------------------------------
 *
 * Used for protocol robustness testing.
 */
enum class TestMode
{
    NORMAL,
    INVALID_HEADER,
    INVALID_SUBSYSTEM,
    PARTIAL_PACKET
};

int main() {

    TestMode test_mode = TestMode::NORMAL;

     //--------------------------------------------------------
    // 1. Create socket
    //--------------------------------------------------------
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    /*
     * AF_INET     → IPv4
     * SOCK_STREAM → TCP
     *
     * This creates a communication endpoint (like opening a phone line)
     */
    if (sock < 0) {
        std::cerr << "Socket creation failed\n";
        return -1;
        }
    
    //--------------------------------------------------------
    // 2. Defining server address
    //--------------------------------------------------------
    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    /*
     * inet_pton converts IP string → binary format
     * "127.0.0.1" = localhost (same machine)
     */

    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    //--------------------------------------------------------
    // 3. Connect to server
    //--------------------------------------------------------
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection failed\n";
        return -1;
    }

    std::cout << "[INFO] Connected to server\n";

    //--------------------------------------------------------
    // Create telemetry packet
    //--------------------------------------------------------
    TelemetryPacket packet{};

    // Packet validation header
    packet.header = PACKET_HEADER;

    //Fault Injection 
    switch (test_mode)
    {
        //----------------------------------------------------
        // Invalid synchronization header
        //----------------------------------------------------
        case TestMode::INVALID_HEADER:

            packet.header = 0x55;
            break;

        //----------------------------------------------------
        // Invalid subsystem ID
        //----------------------------------------------------
        case TestMode::INVALID_SUBSYSTEM:

            packet.subsystem_id = 99;
            break;

        //----------------------------------------------------
        // Normal packet
        //----------------------------------------------------
        default:
            break;
    }
    float t = 0.0f;    //Time variable 
    bool propulsion_mode = false;


    // Send binary packet
    while (true)
    {
        if (propulsion_mode)
        {
            packet.subsystem_id =static_cast<uint8_t>(SubsystemID::PROPULSION);
            // Thrust
            packet.param1 =12500.0f +500.0f * std::sin(0.2f * t);
            // EGT
            packet.param2 =710.0f +15.0f * std::sin(0.5f * t);
            // Efficiency
            packet.param3 =0.87f +0.01f * std::sin(0.1f * t);
        }
        else
        {
            packet.subsystem_id =
                static_cast<uint8_t>(
                    SubsystemID::HYDRAULIC);

            // Pressure
            packet.param1 =
                3000.0f +
                200.0f * std::sin(0.3f * t);

            // Flow Rate
            packet.param2 =
                45.0f +
                5.0f * std::sin(0.4f * t);

            // Fluid Temperature
            packet.param3 =
                75.0f +
                8.0f * std::sin(0.2f * t);
        }


        // Send telemetry packet
        ssize_t bytes_sent =send(sock,&packet,sizeof(packet),0);

        // Validate transmission
        if (bytes_sent <= 0)
        {
            std::cerr
                << "[ERROR] Telemetry transmission failed\n";

            break;
        }

        std::cout << "[INFO] Telemetry packet streamed (" << bytes_sent << " bytes)\n";
        
        // Simulate telemetry rate
        t += 0.1f;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // 5. Close socket
    close(sock);
    return 0;
}