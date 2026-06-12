# RLS08 Based Line Follower Robot using Arduino UNO and L298N

## Overview

This project is a basic Line Follower Robot built using:

- Arduino UNO
- RLS08 8-Channel IR Sensor Array
- L298N Motor Driver
- Two BO Motors

The robot detects a black line on a white surface using the RLS08 sensor array and adjusts its movement accordingly. Sensor readings are processed to calculate the line position, and the motors are controlled through the L298N motor driver.

---

## Features

- 8-channel line detection using RLS08
- Position-based line tracking
- Differential motor speed control
- Forward, Left, and Right movement logic
- Easy to upgrade to PID control
- Beginner-friendly code structure

---

## Components Required

| Component | Quantity |
|------------|------------|
| Arduino UNO | 1 |
| RLS08 Sensor Array | 1 |
| L298N Motor Driver | 1 |
| BO Motors | 2 |
| Robot Chassis | 1 |
| Wheels | 2 |
| Castor Wheel | 1 |
| Battery Pack | 1 |
| Jumper Wires | As Required |

---

## Pin Connections

### RLS08 to Arduino

| RLS08 | Arduino UNO |
|---------|------------|
| D1 | D2 |
| D2 | D3 |
| D3 | D4 |
| D4 | D5 |
| D5 | D6 |
| D6 | D7 |
| D7 | D8 |
| D8 | D9 |
| VCC | 5V |
| GND | GND |

---

### L298N to Arduino

| L298N | Arduino UNO |
|---------|------------|
| ENA | D10 |
| IN1 | A0 |
| IN2 | A1 |
| IN3 | D12 |
| IN4 | D13 |
| ENB | D11 |
| GND | GND |

---

### Motors to L298N

| Motor | L298N |
|---------|--------|
| Left Motor | OUT1, OUT2 |
| Right Motor | OUT3, OUT4 |

---

### Power Connections

| Device | Connection |
|----------|------------|
| Battery Positive | L298N 12V |
| Battery Negative | L298N GND |
| Arduino GND | L298N GND |

**Important:** All grounds must be connected together.

---

## Working Principle

The RLS08 sensor array continuously reads the surface beneath the robot.

- White Surface → 0
- Black Line → 1

Each sensor is assigned a weight:

| Sensor | Weight |
|----------|---------|
| S1 | -7 |
| S2 | -5 |
| S3 | -3 |
| S4 | -1 |
| S5 | +1 |
| S6 | +3 |
| S7 | +5 |
| S8 | +7 |

The robot calculates the average position of the detected line.

### Example

```text
0 0 0 1 1 0 0 0
```

Detected Sensors:

```text
S4 = -1
S5 = +1
```

Position:

```text
(-1 + 1) / 2 = 0
```

Result:

```text
Line is at the center.
```

---

## Robot Decision Logic

### Center

```text
Position = 0
```

Action:

```text
Move Forward
```

---

### Left

```text
Position < 0
```

Action:

```text
Turn Left
```

---

### Right

```text
Position > 0
```

Action:

```text
Turn Right
```

---

## Project Structure

```text
LineFollower/
│
├── LineFollower.ino
├── README.md
└── Images/
    ├── CircuitDiagram.png
    ├── Robot.jpg
    └── SensorArray.jpg
```

---

## Future Improvements

- PID Control
- Adjustable Speed
- Sharp Turn Detection
- Junction Detection
- Maze Solving
- Competition Line Follower

---

## Learning Outcomes

By completing this project, you will learn:

- Arduino Programming
- Arrays and Loops
- Sensor Interfacing
- Motor Driver Control
- PWM Speed Control
- Robotics Fundamentals
- Line Following Algorithms

---

## Author

Manish Gupta

Arduino and Robotics Learning Project
