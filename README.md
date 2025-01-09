# Fire and Smoke Detection System

This project is an Arduino-based fire and smoke detection system using sensors, a buzzer, and an LCD display. The system alerts the user in case of fire or smoke by triggering the buzzer and displaying warning messages on the LCD.

## Components Used
1. **Fire Sensor (Digital Output)**
   - Detects the presence of fire and provides a digital signal.
2. **Smoke Sensor (Analog Output)**
   - Measures smoke levels and provides an analog signal.
3. **Buzzer**
   - Produces an audible alert when fire or smoke is detected.
4. **16x2 I2C LCD Display**
   - Displays real-time fire and smoke status.
5. **Arduino**
   - Serves as the microcontroller for processing sensor data and controlling peripherals.

## Features
- **Fire Detection**: Alerts when the fire sensor detects a flame.
- **Smoke Detection**: Alerts when smoke levels exceed a specified threshold.
- **Buzzer Alarm**: Activates an audible alarm when fire or smoke is detected.
- **LCD Display**: Shows messages such as "FIRE DETECTED!" or "SMOKE DETECTED!" for easy monitoring.
- **Serial Output**: Outputs smoke sensor readings to the Serial Monitor for debugging and analysis.

## Circuit Diagram
- Connect the **fire sensor** (D0 output) to Arduino digital pin 2.
- Connect the **smoke sensor** (analog output) to Arduino analog pin A0.
- Connect the **buzzer** to Arduino digital pin 3.
- Connect the **16x2 I2C LCD display** to the Arduino's I2C pins:
  - **SDA** to A4 (on an Uno) or other SDA pin.
  - **SCL** to A5 (on an Uno) or other SCL pin.

## Configuration
- Fire sensor detects flames and triggers a digital `LOW` signal.
- Smoke sensor outputs analog values; thresholds for detection can be adjusted in the code:
  - Default threshold for fire: `fireSensorValue == LOW`.
  - Default threshold for smoke: `smokeSensorValue > 300` for fire scenarios, and `smokeSensorValue > 230` for non-fire scenarios.

## Installation
1. Install the required Arduino libraries:
   - **Wire**: For I2C communication.
   - **LiquidCrystal_I2C**: For the LCD display.
2. Upload the provided code to the Arduino using the Arduino IDE.

## Usage
1. Power up the system.
2. The LCD displays "No Fire" if no fire or smoke is detected.
3. If a fire is detected:
   - The LCD displays "FIRE DETECTED!" and "ALERT!"
   - The buzzer is activated.
4. If smoke is detected without fire:
   - The LCD displays "SMOKE DETECTED!" and "ALERT!"
   - The buzzer is activated.
5. Monitor smoke sensor readings in the Serial Monitor for calibration and troubleshooting.

## Code Explanation
- **Setup**:
  - Initializes the LCD, sets up pins for sensors and buzzer, and begins Serial communication.
- **Loop**:
  - Continuously checks sensor values.
  - Triggers alerts when thresholds are exceeded.
  - Updates the LCD and buzzer state based on the detected conditions.

## Customization
- Adjust smoke detection thresholds in the code:
  ```cpp
  if (smokeSensorValue > 300) { /* Fire-specific threshold */ }
  if (smokeSensorValue > 230) { /* Non-fire-specific threshold */ }
