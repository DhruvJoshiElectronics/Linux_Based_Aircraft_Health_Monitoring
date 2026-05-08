# System Architecture

## Overview

The system simulates an aviation-inspired aircraft health monitoring unit where multiple subsystem clients communicate with a central server using a custom binary protocol over TCP.

The server processes incoming telemetry, performs anomaly detection, and generates structured alerts and logs.

---

## High-Level Architecture

Subsystem Clients → TCP Server → Data Processing → Alert System → Logging

---

## Components

### 1. Subsystem Clients

- Simulate aircraft subsystems
- Compute telemetry using real-world formulas
- Send binary packets over TCP

---

### 2. TCP Server

- Runs on Embedded Linux (WSL/Ubuntu)
- Accepts multiple client connections
- Spawns a thread per client
- Receives telemetry packets

---

### 3. Client Handler

- Handles communication for each client
- Parses incoming binary data
- Passes structured data to processing layer

---
TCP Layer
    ↓
Binary Protocol Layer
    ↓
Validation Layer
    ↓
Telemetry Processing Layer

### 4. Data Processing Layer

- Interprets telemetry values
- Validates incoming data
- Prepares data for anomaly detection

---

### 5. Anomaly Detection Engine

- Applies threshold-based and trend-based checks
- Detects abnormal conditions
- Classifies severity:
  - NORMAL
  - CAUTION
  - WARNING

---

### 6. Alert Manager

- Generates structured alerts
- Formats messages similar to cockpit alerts
- Triggers logging

---

### 7. Logging System

- Stores alerts in filesystem
- Maintains timestamped logs
- Helps in debugging and analysis

---

## Execution Model

- Server runs as a continuous process
- Each client is handled in a separate thread
- Data flows in real-time
- Alerts are generated asynchronously

---

## Data Flow

1. Client computes telemetry
2. Client sends binary packet via TCP
3. Server receives packet
4. Packet is parsed
5. Data is processed
6. Anomaly detection is applied
7. Alert is generated (if needed)
8. Alert is logged

---

## Design Decisions

- Binary protocol for efficiency and realism
- Thread-per-client model for simplicity
- Client-side computation for realistic simulation
- Modular architecture for scalability
- File-based logging for persistence

---

## Future Enhancements

- Replace thread model with event-driven model
- Add checksum validation
- Introduce Docker deployment
- Integrate CI/CD pipeline
- Extend to hardware-based clients

