# Smart Parking System with AI + Blynk
![Uploading image.png…]()

## Description
This project uses **ESP32 + Ultrasonic Sensors** to detect parking slot occupancy and displays it on a **Blynk Dashboard**.  
A **Python AI module** predicts busy periods based on historical data.

---

## Hardware Needed
- ESP32 / NodeMCU
- 4 Ultrasonic Sensors (HC-SR04)
- Optional LEDs for each slot
- Buzzer (optional)
- Jumper wires & breadboard

---

## Setup Instructions

1. **Arduino Setup**
   - Install libraries: `Blynk`, `NewPing`.
   - Replace `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD`, and `YOUR_BLYNK_AUTH_TOKEN`.
   - Upload `SmartParking.ino` to ESP32.

2. **Blynk App**
   - Create a new project (ESP32).
   - Add 4 LED widgets → Virtual Pins V1–V4.
   - Optional: Add Notification widget.

3. **Python AI**
   - Install Python packages: `requests`.
   - Replace `YOUR_BLYNK_AUTH_TOKEN` in `ai_predictor.py`.
   - Run the script to see predictions and occupancy.

---

## Features
- Real-time parking slot monitoring
- Dashboard via Blynk
- Predict traffic patterns using Python AI

---

## Optional Enhancements
- Push notifications on slot changes
- Web dashboard using Flask
- Machine learning for advanced predictions
