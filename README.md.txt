⚡ EV GUARD

📌 Project Title

**EV GUARD – IoT Based Smart EV Charging Monitoring and Protection System**

---

📖 Description
EV GUARD is an IoT-based smart EV charging monitoring and protection system developed using **ESP32** and **Blynk IoT platform**.  
It monitors voltage, temperature, charging status and provides real-time updates with LED indicators, buzzer alerts, and cloud dashboard visualization.

The system also simulates charging levels using a potentiometer and ensures safety through fault detection and automatic relay control.

---

🚀 Features

- Real-time Voltage Monitoring (ZMPT101B)
- Temperature Monitoring (DHT11)
- Charging Status Indication
- Potentiometer-based Charging Simulation
- LED Indicators (Green, Yellow, Red)
- Buzzer Alerts for Completion & Fault
- Relay-based Charging Control
- Blynk IoT Live Dashboard
- Fault Detection System

---

🧰 Hardware Used

- ESP32 Development Board
- DHT11 Temperature Sensor
- ZMPT101B Voltage Sensor
- 10k Potentiometer
- Relay Module (4 Channel)
- LEDs (Green, Yellow, Red)
- Active Buzzer
- Breadboard & Jumper Wires

---

💻 Software Used

- Arduino IDE
- Blynk IoT Platform
- C / C++ Programming

---

🔄 System Workflow

System works in 4 main states:

1. 🟢 System Ready
2. 🟡 Charging Mode
3. 🔴 Charging Complete
4. 🚨 Fault Condition

---

📊 Blynk Dashboard

Displays:
- Voltage
- Temperature
- Charging Status
- Relay Status
- System State Indicators
- Charging Progress

---

🎯 Working Principle

- Potentiometer controls simulated charging level (0–100%)
- ESP32 reads sensor values continuously
- Based on thresholds:
  - LEDs change state
  - Relay ON/OFF
  - Buzzer alerts trigger
- Data is sent to Blynk cloud in real-time

---

🔮 Future Improvements

- Real current sensor integration (SCT-013)
- Battery percentage estimation
- Energy consumption tracking
- Mobile notifications
- AI-based fault prediction
- Cloud data logging

---

👨‍💻 Developed By

**Haridharshan S**  

Electrical and Electronics Engineering Student