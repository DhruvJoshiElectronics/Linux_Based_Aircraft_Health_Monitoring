#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include <cstdint>
#include "protocol/telemetry_packet.h"

/**
 * @brief TCP Server responsible for receiving telemetry data from subsystem clients.
 *
 * This class encapsulates:
 * - Socket creation
 * - Binding to a port
 * - Listening for incoming connections
 * - Accepting and handling client connections
 */
class TCPServer {
public:
    /**
     * @brief Constructor
     * @param port Port number on which server will listen
     */
    explicit TCPServer(uint16_t port);

    /**
     * @brief Starts the TCP server (blocking call)
     */
    void start();

    private:
    int server_fd;      // File descriptor for server socket
    uint16_t port;      // Listening port

    /**
     * @brief Initializes socket, bind, and listen
     * @return true if successful, false otherwise
     */
    bool initialize();
};

#endif // TCP_SERVER_H