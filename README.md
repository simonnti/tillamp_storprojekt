# Accelerometer-Based Motor Control

## Overview
This project uses an **ADXL345 accelerometer** to measure acceleration along three axes and controls a motor based on the sensor's readings. If certain thresholds are exceeded, the motor is activated.

## Features
- 📡 Reads acceleration data from an **ADXL345 accelerometer**.
- 🖥 Outputs real-time acceleration values via **Serial Monitor**.
- ⚙️ Activates a motor when predefined acceleration thresholds are met.

## Hardware Requirements
- 🛠 **Arduino board**
- 📟 **ADXL345 accelerometer module**
- 🔧 **DC motor**
- 🔌 **Motor driver** (if required by the motor type)
- 🔗 **Connecting wires**

## Code Explanation
### 🔧 Initialization (`setup()`)
- Initializes the motor pin as an **output**.
- Starts **serial communication** at 9600 baud.
- Initializes the **ADXL345 accelerometer** and checks for proper connection.

### 🔄 Main Loop (`loop()`)
1. Reads **acceleration data** from the **ADXL345**.
2. Prints the **acceleration values** (`X`, `Y`, and `Z`) to the **Serial Monitor**.
3. Controls the motor based on acceleration thresholds:
   - **Activates** the motor if **Z acceleration** is `< -5 m/s²`.
   - **Activates** the motor if **X acceleration** is `> 4 m/s²` or `< -4 m/s²`.
   - Otherwise, **deactivates** the motor.
4. Adds a **delay of 100 ms** for readability and stability.

## 📌 Setup & Usage
1. **Connect** the ADXL345 accelerometer to the **Arduino via I2C**.
2. **Connect** the motor to **pin 5** (use a motor driver if necessary).
3. **Upload** the code to the Arduino.
4. **Open the Serial Monitor** to observe acceleration readings.
5. **Tilt or move the sensor** to trigger the motor.

## 📦 Dependencies
- [Adafruit Sensor Library](https://github.com/adafruit/Adafruit_Sensor)
- [Adafruit ADXL345 Library](https://github.com/adafruit/Adafruit_ADXL345)

## ⚠️ Notes
- Ensure **proper wiring** of the **ADXL345** and **motor**.
- Modify the **acceleration thresholds** in the code to suit specific needs.
- Use a **motor driver** if the motor requires higher current than the Arduino can supply.

## 📜 License
This project is **open-source** and can be modified for **personal or educational use**.

