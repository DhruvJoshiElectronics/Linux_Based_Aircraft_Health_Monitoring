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
