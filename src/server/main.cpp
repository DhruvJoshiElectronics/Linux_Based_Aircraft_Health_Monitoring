#include "server/tcp_server.h"

/**
 * @brief Entry point of server application
 */
int main() {

    // Create server instance on port 8080
    TCPServer server(8080);

    // Start server (blocking call)
    server.start();

    return 0;
}