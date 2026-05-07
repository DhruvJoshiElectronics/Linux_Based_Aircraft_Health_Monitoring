# Development Plan (Sprints)

## Overview

This project is developed in incremental sprints, focusing on building a working system first and then progressively enhancing features, structure, and robustness.

---

## Sprint 1: TCP Communication (Single Client)

### Goal
Establish basic TCP communication between one client and the server.

### Tasks
- Create TCP server
- Create single subsystem client
- Send and receive binary packet
- Print received data

### Outcome
Basic communication pipeline working

---

## Sprint 2: Multi-Client Handling

### Goal
Handle multiple subsystem clients simultaneously.

### Tasks
- Implement thread-per-client model
- Accept multiple connections
- Ensure independent handling

### Outcome
Concurrent client communication

---

## Sprint 3: Packet Parsing & Validation

### Goal
Parse binary packet into structured data.

### Tasks
- Deserialize packet
- Validate header and fields
- Map subsystem IDs

### Outcome
Reliable data extraction

---

## Sprint 4: Anomaly Detection

### Goal
Detect abnormal conditions.

### Tasks
- Define thresholds
- Implement trend detection (e.g., temperature rise)
- Classify severity (NORMAL, CAUTION, WARNING)

### Outcome
Basic intelligence in system

---

## Sprint 5: Alert System

### Goal
Generate structured alerts.

### Tasks
- Create alert manager
- Format cockpit-style messages
- Integrate with detection engine

### Outcome
Human-readable alerts

---

## Sprint 6: Logging System

### Goal
Persist alerts to filesystem.

### Tasks
- Implement file logging
- Add timestamps
- Store severity levels

### Outcome
Persistent fault logs

---

## Sprint 7: Refactoring & Structure

### Goal
Improve code quality and modularity.

### Tasks
- Separate modules (server, core, utils)
- Clean interfaces
- Improve readability

### Outcome
Production-quality structure

---

## Sprint 8: Advanced Features (Optional)

### Goal
Enhance system with modern tools.

### Tasks
- Add unit testing (GoogleTest / Catch2)
- Add CI/CD (GitHub Actions)
- Add Docker support

### Outcome
Industry-level project completeness