# 🚤 Rescue Boat Project – README

## 📌 Overview

This project implements a **remotely operated rescue boat** using an ESP32 microcontroller for control and an ESP32-CAM for live video streaming. The system allows a user to navigate the boat wirelessly using the Blynk mobile application while monitoring the surroundings in real time through a web-based camera feed.

---

## ⚙️ System Architecture

The system is divided into two main modules:

1. **ESP32 (Main Controller)**

   * Handles WiFi connection
   * Communicates with Blynk app
   * Controls motors via BTS7960 drivers

2. **ESP32-CAM**

   * Streams live video
   * Operates independently via web server

---

## 🔌 Hardware Components

* ESP32 Dev Module
* ESP32-CAM Module
* BTS7960 Motor Drivers (x2)
* 775 DC Motors (x2)
* 12V Battery
* LM2596 Buck Converter (12V → 5V)
* Fuse, Capacitor, Wiring

---

## 📲 Blynk Control Mapping

| Action   | Virtual Pin |
| -------- | ----------- |
| Forward  | V0          |
| Backward | V1          |
| Left     | V2          |
| Right    | V3          |
| Stop     | V4          |

---

## 🔧 Pin Configuration

### Motor Driver Connections

| ESP32 Pin | Function                   |
| --------- | -------------------------- |
| GPIO12    | Left Motor Forward (RPWM)  |
| GPIO13    | Left Motor Reverse (LPWM)  |
| GPIO14    | Right Motor Forward (RPWM) |
| GPIO15    | Right Motor Reverse (LPWM) |

---

### ESP32 ↔ ESP32-CAM (UART)

| ESP32  | ESP32-CAM |
| ------ | --------- |
| GPIO17 | RX        |
| GPIO16 | TX        |
| GND    | GND       |
| 5V     | 5V        |

---

## ⚡ Power System

* Battery provides 12V to motor drivers
* Buck converter reduces 12V → 5V for ESP32 & ESP32-CAM
* All components share **common ground**
* Fuse ensures circuit protection
* Capacitor stabilizes voltage during motor startup

---

## 🧠 Code Functionality

### 1. WiFi & Blynk Connection

ESP32 connects to WiFi and Blynk server using credentials. This allows remote control through the mobile app.

---

### 2. PWM Motor Control

* Uses PWM (Pulse Width Modulation) to control motor speed
* Speed is limited (~70–80%) to prevent current spikes
* Smooth and efficient motor operation

---

### 3. Movement Functions

The code defines functions for:

* Forward
* Backward
* Left turn
* Right turn
* Stop

Each function controls motor direction using BTS7960 driver inputs.

---

### 4. Blynk Command Handling

* Virtual pins (V0–V4) receive button inputs from app
* Each input triggers corresponding movement
* Real-time response

---

### 5. Main Loop

Continuously runs:

```cpp
Blynk.run();
```

This keeps system connected and responsive.

---

## 🎥 Camera Module

* ESP32-CAM runs **CameraWebServer** code
* Provides live video via browser

Example:

```
http://192.168.x.x
```

---

## 🚀 How to Run

1. Upload motor control code to ESP32
2. Upload CameraWebServer code to ESP32-CAM
3. Connect hardware as per wiring
4. Power system using battery + buck converter
5. Open Blynk app for control
6. Open browser for video stream

---

## ⚠️ Important Notes

* Always use stable 5V supply for ESP32-CAM
* Ensure all grounds are connected
* Do not connect 12V directly to ESP32
* Test system without motors first
* Use fuse for safety

---

## 🎯 Conclusion

This system provides a **low-cost, efficient, and safe rescue solution** with real-time control and monitoring. The integration of wireless control, motor drivers, and camera streaming makes it suitable for practical rescue applications.

---
