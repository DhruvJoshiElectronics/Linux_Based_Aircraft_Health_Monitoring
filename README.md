# Aircraft Health Monitoring & Alert System (Embedded Linux + TCP)

## Overview

This project simulates an aviation-inspired real-time health monitoring system where multiple aircraft subsystems transmit telemetry data to a central monitoring unit using a custom binary protocol over TCP.

The system performs real-time data processing, anomaly detection, and structured alert generation to mimic safety-critical aircraft monitoring systems.

---

## Problem Statement

Modern aircraft subsystems continuously generate telemetry such as thrust, temperature, electrical load, and pressure. Detecting abnormal conditions in real-time is critical for ensuring operational safety.

This project implements a Linux-based monitoring system that receives telemetry from multiple simulated subsystems, processes it, and generates alerts based on predefined thresholds and trends.

---

## Key Features

- Multi-client TCP communication (subsystem simulators)
- Custom binary protocol for efficient data transmission
- Physics-based telemetry calculations at client side
- Real-time anomaly detection
- Structured alert system (NORMAL / CAUTION / WARNING)
- File-based fault logging
- Modular and scalable architecture

---

## Subsystems Simulated

- Propulsion System
- Flight Control System
- Electrical Power System
- Fuel System
- Hydraulic System
- Pneumatic System
- Environmental Control System (ECS)
- Avionics System

---

## Technology Stack

- Language: C++
- OS: Linux (WSL / Ubuntu)
- Build System: CMake
- Networking: TCP (POSIX sockets)
- Logging: File-based logging (std::ofstream / spdlog)

---

## Project Structure

Refer to `/docs/architecture.md` for detailed system design.

---

## Future Scope

- Integration with embedded hardware (ESP32 / Raspberry Pi)
- MQTT/cloud integration
- Docker-based deployment
- CI/CD pipeline with automated testing
- Web dashboard for visualization

# Current Features

## Networking Layer

- Linux TCP socket programming
- Persistent TCP sessions
- IPv4 communication
- Real-time telemetry streaming
- SO_REUSEADDR support

---

## Concurrent Backend Architecture

- Thread-per-client architecture
- Continuous accept loop
- Detached worker threads
- Persistent telemetry receive loops

---

## Binary Telemetry Protocol

Custom binary packet structure:

```cpp
struct TelemetryPacket
{
    uint8_t  header;
    uint8_t  subsystem_id;
    uint32_t timestamp;

    float param1;
    float param2;
    float param3;
};

## Build & Run Instructions

### Clone Repository
```bash
git clone <your-repository-link>
cd Linux_Based_Aircraft_Health_Monitoring

mkdir build
cd build
cmake ..
cmake --build .
./server
./client

