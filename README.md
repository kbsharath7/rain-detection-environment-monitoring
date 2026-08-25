# ESP32 IoT Rain Detection and Environment Monitoring System

An ESP32-based IoT rain detection and environment monitoring system that detects rainfall and changes in light conditions using a rain sensor and LDR. The system displays real-time sensor readings on a 16x2 I2C LCD and automatically controls relays and a buzzer based on the detected environmental conditions. Sensor data and system status can also be monitored remotely through the Blynk IoT platform.

## Features

* Rain detection using a rain sensor
* Light intensity monitoring using LDR
* 16x2 I2C LCD display
* Automatic relay control based on environmental conditions
* Buzzer warning during rainy conditions
* Wi-Fi connectivity using ESP32
* Real-time monitoring through Blynk IoT
* Serial Monitor output for sensor readings
* Automatic detection of dark conditions
* Automatic detection of rain
* Rainy climate indication when dark and rainy conditions occur simultaneously

## Components Used

* ESP32
* Rain Sensor Module
* LDR (Light Dependent Resistor)
* 16x2 I2C LCD
* 2-Channel Relay Module
* Buzzer
* Jumper Wires
* Power Supply

## Software & Libraries

* Arduino IDE
* ESP32 Board Package
* Wire.h
* LiquidCrystal_I2C.h
* WiFi.h
* BlynkSimpleEsp32.h

## How It Works

The ESP32 continuously reads the light intensity from the LDR and rainfall level from the rain sensor.

The sensor values are displayed on the 16x2 I2C LCD and sent to the Blynk IoT platform through Wi-Fi.

The system performs automatic actions according to the detected environmental conditions:

* When the LDR value exceeds the configured threshold, the system detects a dark condition and activates Relay 1.
* When the rain sensor detects rainfall, the system activates Relay 2 and displays "Rain Detected".
* When both dark and rainy conditions are detected simultaneously, the system identifies the condition as "Climate Rainy" and activates the buzzer.
* Sensor readings and system status are continuously updated on Blynk.
* The current environmental condition is displayed on the LCD.

## Configured Thresholds

| Parameter              | Threshold |
| ---------------------- | --------: |
| Dark Condition (LDR)   |    > 1500 |
| Rain Detection         |    < 2000 |
| Sensor Update Interval |  1 second |

> Note: The actual threshold values can vary depending on the sensor module, environment, and calibration.

## Blynk Monitoring

The project uses the Blynk IoT platform for remote monitoring.

| Blynk Virtual Pin | Function                      |
| ----------------- | ----------------------------- |
| V0                | LDR Sensor Value              |
| V1                | Rain Sensor Value             |
| V2                | Dark Condition Status         |
| V3                | Rain Detection Status         |
| V4                | Buzzer / Rainy Climate Status |
| V5                | Current System Status         |

## Output Display

The LCD displays the current environmental condition along with the sensor readings.

Examples:

* `System Normal`
* `Dark Detected`
* `Rain Detected`
* `Dark & Rain`
* `Climate Rainy`

The second line displays the real-time LDR and rain sensor values.

## Project Code

The complete Arduino source code is available in the project repository.

`rain_detection.ino`

## Project Images

The repository contains images of the ESP32-based rain detection and environment monitoring system, including the sensor connections, LCD display, relay module, and overall hardware setup.

## Future Improvements

* Add automatic rainwater harvesting control
* Add a mobile application with detailed alerts
* Store sensor data for historical analysis
* Add temperature and humidity monitoring
* Add cloud-based data logging
* Add automatic window or roof control during rainfall
* Improve sensor calibration for different environmental conditions

## Author

**K B Sharath**

GitHub: https://github.com/kbsharath7
