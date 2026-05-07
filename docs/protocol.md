# Telemetry Protocol Specification

## Overview

This project uses a custom binary protocol for efficient and deterministic communication between subsystem clients and the central monitoring server.

Each subsystem transmits telemetry packets containing computed physical parameters derived from real-world aviation formulas.

---

## Packet Structure

Each telemetry packet has a fixed size and structure:

| Field          | Type        | Size (bytes) |
|----------------|------------|--------------|
| Header         | uint8_t     | 1            |
| Subsystem ID   | uint8_t     | 1            |
| Timestamp      | uint32_t    | 4            |
| Param 1        | float       | 4            |
| Param 2        | float       | 4            |
| Param 3        | float       | 4            |

**Total Size:** 18 bytes (aligned to 20 bytes if padded)

---

## Packet Definition (C++)

```cpp
#pragma pack(push, 1)
struct TelemetryPacket {
    uint8_t header;        // Fixed value: 0xAA
    uint8_t subsystem_id;  // Range: 1–8
    uint32_t timestamp;

    float param1;
    float param2;
    float param3;
};
#pragma pack(pop)
--------------------------------xxxxxxxxxx----------------------------
| ID | Subsystem                    |
| -- | ---------------------------- |
| 1  | Propulsion                   |
| 2  | Flight Control               |
| 3  | Electrical                   |
| 4  | Fuel                         |
| 5  | Hydraulic                    |
| 6  | Pneumatic                    |
| 7  | Environmental Control System |
| 8  | Avionics                     |
------------------------------xxxxxxxxxxx------------------------------
Each subsystem computes 3 parameters using real-world formulas.

1. Propulsion System
Thrust: F = ṁ (Ve − V0)
EGT: corrected sensor value
Efficiency: η = (F × V0) / (ṁ_fuel × LHV)

2. Flight Control System
Angle of Attack (AoA)
Roll Rate (p = dφ/dt)
Control Error (Command − Feedback)

3. Electrical System
Power: P = V × I × cos(φ)
Voltage Error
Load Percentage

4. Fuel System
Fuel Flow Rate
Fuel Density
Fuel Quantity

5. Hydraulic System
Pressure
Flow Rate
Leak Detection

6. Pneumatic System
Pressure (Ideal Gas Law)
Mass Flow Rate
Temperature Drop

7. Environmental Control System
Cabin Pressure Altitude
Temperature Error
Airflow Rate

8. Avionics System
Velocity
Position
Drift/Error estimation
----------------------------------xxxxxxxxxx-----------------------------------------
## Protocol Rules

All packets must start with header value 0xAA
Fixed packet size must be maintained
All fields are mandatory
Floats are transmitted in IEEE 754 format
System assumes little-endian encoding

## Future Enhancements
Add checksum for data integrity
Introduce versioning in header
Transition to advanced binary serialization (e.g., Protobuf)