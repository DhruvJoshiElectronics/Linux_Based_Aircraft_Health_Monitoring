cmake_minimum_required(VERSION 3.10)

project(Linux_Based_Aircraft_Health_Monitoring)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(server
    src/server/main.cpp
    src/server/tcp_server.cpp
    src/core/packet_validator.cpp
    src/core/subsystem_parser.cpp
    src/core/parameter_interpreter.cpp
    src/monitoring/alert_engine.cpp
    src/logging/logger.cpp
)
add_executable(client
    src/client/simple_client.cpp
)