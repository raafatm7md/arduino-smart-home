# Smart Home Arduino Project

This project utilizes Arduino to create a smart home system incorporating various sensors and devices to monitor and control environmental factors and access.

## Overview

The project involves the integration of several components:

### Components Used
- **Temperature Sensor:** Utilizes a TMP sensor to measure the ambient temperature.
- **Passive Infrared Sensor (PIR):** Detects motion within its field of view.
- **Flame Sensor:** Detects the presence of flames.
- **RFID Reader:** Allows access control using RFID cards.

### Actuators
- **Buzzer:** Generates sound alerts based on sensor readings.
- **LED:** Indicates motion detection.
- **Servo Motor:** Controls access to a door lock.

## Setup

### Hardware Requirements
- **Arduino Board:** Used to control the entire system.
- **Liquid Crystal Display (LCD):** Displays temperature and system messages.
- **RFID Module:** Interfaces with RFID cards for access control.
- **Servo Motor:** Controls the door lock mechanism.
- **Sensors:** TMP temperature sensor, PIR motion sensor, and flame sensor.

### Connections
- **TMP Sensor:** Connected to analog pin A5.
- **PIR Sensor:** Connected to digital pin 2.
- **Flame Sensor:** Connected to digital pin 8.
- **Buzzer:** Connected to analog pin A4.
- **LED:** Connected to analog pin A3.
- **Servo Motor:** Connected to digital pin 3.
- **RFID Module:** Connected to digital pins 9 and 10.
- **LCD:** Connected to digital pins 0, 1, 4, 5, 6, 7.

### Libraries Used
- `LiquidCrystal.h`: For controlling the LCD.
- `Servo.h`: For controlling the servo motor.
- `SPI.h` and `RFID.h`: For RFID functionality.

## Functionality

The Arduino sketch continuously monitors the environment:

- **Temperature:** Displays the temperature in Celsius and Fahrenheit on the LCD. A buzzer is activated if the temperature exceeds a certain threshold (30°C in this case).
- **Motion Detection:** Utilizes the PIR sensor to detect motion, triggering an LED indicator.
- **Flame Detection:** Alerts when a flame is detected using the flame sensor.
- **Access Control:** Utilizes RFID cards for door access. Authorized cards trigger the servo motor to unlock the door, while unauthorized attempts trigger a warning message on the LCD and activate a buzzer alert.

### Usage
- Upload the provided Arduino sketch to your Arduino board.
- Ensure proper wiring and connections as described above.
- Monitor the Serial Monitor to view sensor outputs and system messages.

## Note
- Ensure that appropriate safety measures are taken when dealing with flame-related sensors and electronic devices connected to power sources.

## Disclaimer
This project is for educational purposes. Use it responsibly and ensure safety measures when implementing and testing the system.

---

Feel free to expand on the sections based on specifics about the connections, safety precautions, or any additional functionalities of your project!
