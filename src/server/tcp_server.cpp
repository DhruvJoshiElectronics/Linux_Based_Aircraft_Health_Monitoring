#include "server/tcp_server.h"

#include <iostream>
#include <cstring>        // memset
#include <unistd.h>       // close()
#include <arpa/inet.h>    // socket, bind, listen, accept

//------------------------------------------------------------
// Constructor
//------------------------------------------------------------
TCPServer::TCPServer(uint16_t port)
    : server_fd(-1), port(port) {}

//------------------------------------------------------------
// Initialization: socket + bind + listen
//------------------------------------------------------------
bool TCPServer::initialize() {

    //--------------------------------------------------------
    // 1. Create Socket
    //--------------------------------------------------------
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    /**
     * AF_INET     → IPv4 addressing
     * SOCK_STREAM → TCP protocol (reliable, connection-oriented)
     *
     * Why TCP?
     * - Guaranteed delivery
     * - Ordered packets
     * - Required for safety-critical systems (aviation simulation)
     */

    if (server_fd < 0) {
        std::cerr << "[ERROR] Socket creation failed\n";
        return false;
    }

    //--------------------------------------------------------
    // 2. Configure Address Structure
    //--------------------------------------------------------
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // Accept connections from any IP
    address.sin_port = htons(port);        // Convert host → network byte order

    /**
     * Why htons?
     * - Different machines use different byte ordering (endianness)
     * - Network standard = Big Endian
     */

    //--------------------------------------------------------
    // 3. Bind Socket to Port
    //--------------------------------------------------------
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "[ERROR] Bind failed (Port may be in use)\n";
        return false;
    }

    /**
     * bind() associates:
     * Socket → IP + Port
     *
     * Without bind:
     * Server has no identity in network
     */

    //--------------------------------------------------------
    // 4. Start Listening
    //--------------------------------------------------------
    if (listen(server_fd, 5) < 0) {
        std::cerr << "[ERROR] Listen failed\n";
        return false;
    }

    /**
     * listen() → marks socket as passive (server mode)
     *
     * backlog = 5:
     * Maximum number of pending connections in queue
     */

    std::cout << "[INFO] Server initialized on port " << port << "\n";

    return true;
}

//------------------------------------------------------------
// Start Server (Main Execution Loop)
//------------------------------------------------------------
void TCPServer::start() {

    // Initialize server components
    if (!initialize()) {
        std::cerr << "[FATAL] Server initialization failed\n";
        return;
    }

    std::cout << "[INFO] Waiting for client connections...\n";

    //--------------------------------------------------------
    // Accept a client connection
    //--------------------------------------------------------
    int client_socket = accept(server_fd, nullptr, nullptr);

    /**
     * accept():
     * - Blocks until a client connects
     * - Returns a NEW socket (client-specific)
     *
     * Important:
     * server_fd → listens
     * client_socket → communicates
     */

    if (client_socket < 0) {
        std::cerr << "[ERROR] Accept failed\n";
        close(server_fd);
        return;
    }

    std::cout << "[INFO] Client connected\n";

    // Receive telemetry packet
    TelemetryPacket packet{};
    ssize_t bytes_received =read(client_socket,&packet,sizeof(TelemetryPacket));

    /**
     * read():
     * - Reads raw bytes from socket
     * - Blocking call
     *
     * Future:
     * This will be replaced with structured binary packet reading
     */
    if (bytes_received <= 0) {
        std::cerr << "[ERROR] Packet receive failed\n";
    }else if (packet.header != PACKET_HEADER) {
        std::cerr << "[ERROR] Invalid packet header\n";
    }
    else {
        std::cout << "[INFO] telemetry packet:\n";
        std::cout << "  Subsystem ID: " << static_cast<int>(packet.subsystem_id) << "\n";
        std::cout << "  Timestamp: " << packet.timestamp << "\n";
        std::cout << "  Param1: " << packet.param1 << "\n";
        std::cout << "  Param2: " << packet.param2 << "\n";
        std::cout << "  Param3: " << packet.param3 << "\n";
    }

    //--------------------------------------------------------
    // Cleanup
    //--------------------------------------------------------
    close(client_socket);
    close(server_fd);

    /**
     * Always close sockets:
     * - Prevent resource leaks
     * - Avoid port lock issues
     */
}