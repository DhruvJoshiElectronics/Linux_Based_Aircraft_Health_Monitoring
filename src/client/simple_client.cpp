#include <iostream>
#include <unistd.h>         // close()
#include <arpa/inet.h>      // socket APIs
#include <cstring>          // strlen
#include <ctime>
#include "protocol/telemetry_packet.h"

int main() {
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

    // Subsystem type
    packet.subsystem_id =
        static_cast<uint8_t>(SubsystemID::PROPULSION);

    // Current Unix timestamp
    packet.timestamp = static_cast<uint32_t>(std::time(nullptr));

    /*
    * Example Propulsion System Parameters
    *
    * param1 → Thrust
    * param2 → EGT
    * param3 → Efficiency
    */
    packet.param1 = 12500.5f;
    packet.param2 = 640.2f;
    packet.param3 = 0.87f;

    //--------------------------------------------------------
    // Send binary packet
    //--------------------------------------------------------
    ssize_t bytes_sent =send(sock,&packet,sizeof(packet),0);

    if (bytes_sent > 0) {
    std::cout << "[INFO] Telemetry packet sent ("
              << bytes_sent
              << " bytes)\n";
    }
    else {
        std::cerr << "[ERROR] Packet transmission failed\n";
    }

    //--------------------------------------------------------
    // 5. Close socket
    //--------------------------------------------------------
    close(sock);
    return 0;
}