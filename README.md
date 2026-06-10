# Arduino LDR and Laser Projects

## Description

Collection of Arduino projects featuring LDR sensors, laser modules, intrusion detection systems, security alarms, and beam monitoring applications.

---

# 1. Objective

The objective of this repository is to develop practical Arduino-based sensing and security applications using LDR sensors, laser modules, OLED displays, LEDs, buzzers, and push buttons. These projects demonstrate light detection, laser beam monitoring, intrusion detection, alarm systems, event counting, and real-time status display.

---

# 2. Components Used

### Hardware Components

* Arduino Uno
* OLED Display (SSD1306 I2C)
* LDR Sensor Module
* Laser Module
* LED
* Active Buzzer Module
* Push Button
* Breadboard
* Jumper Wires
* 220Ω Resistor

### Software Components

* Arduino IDE
* Adafruit SSD1306 Library
* Adafruit GFX Library
* Wire Library

---

# 3. Circuit Diagram

The projects use different combinations of the following modules.

### OLED Display

| OLED Pin | Arduino Uno |
| -------- | ----------- |
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

### LDR Module

| LDR Pin | Arduino Uno |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| D0      | D2          |

### Laser Module

| Laser Pin | Arduino Uno |
| --------- | ----------- |
| S         | D7          |
| VCC       | 5V          |
| GND       | GND         |

### LED

| LED Pin     | Arduino Uno                |
| ----------- | -------------------------- |
| Anode (+)   | D8 (through 220Ω resistor) |
| Cathode (-) | GND                        |

### Buzzer Module

| Buzzer Pin | Arduino Uno |
| ---------- | ----------- |
| S          | D9          |
| VCC        | 5V          |
| GND        | GND         |

### Push Button

| Button Pin | Arduino Uno |
| ---------- | ----------- |
| One Pin    | D3          |
| Other Pin  | GND         |

---

# 4. Code Explanation

This repository contains the following Arduino projects:

### OLED Light Dark Detector

Detects ambient light conditions using an LDR sensor and displays BRIGHT or DARK status on an OLED display while controlling an LED.

### LDR LED Monitor

Displays LDR status and LED status on an OLED screen based on ambient lighting conditions.

### Laser Toggle Monitor

Allows a laser module to be switched ON and OFF using a push button while displaying status and switch count.

### Laser Beam Detector

Detects whether a laser beam is reaching the LDR sensor and displays DETECTED or LOST status.

### Laser Tripwire Security Alarm

Uses a laser beam as a virtual security barrier and activates an alarm when the beam is interrupted.

### Laser Security Counter

Counts the number of laser beam interruptions and provides buzzer notifications for intrusion events.

### Mini Laser Security System

Combines beam monitoring, intrusion detection, OLED dashboard, LED indication, buzzer alerts, intrusion counting, and reset functionality into a complete security system.

---

# 5. Output Images

## OLED Light Dark Detector

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 03 PM (1)" src="https://github.com/user-attachments/assets/9e838048-37e1-4d82-b72e-7cc5bee801b5" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 03 PM" src="https://github.com/user-attachments/assets/11fed6d9-314a-4f90-a16c-66d9f10ae11b" />


## LDR LED Monitor

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 04 PM" src="https://github.com/user-attachments/assets/9a44ef70-be7e-468b-b958-5ad93a8e4abf" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 04 PM (1)" src="https://github.com/user-attachments/assets/6ce2533c-8b31-49d4-bf23-f4dd7dac8834" />


## Laser Toggle Monitor

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 05 PM" src="https://github.com/user-attachments/assets/7a9672dc-051c-4439-9374-abbd2edce47b" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 04 PM" src="https://github.com/user-attachments/assets/4ef156a8-ddda-440f-8692-1343d44bab86" />


## Laser Beam Detector

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 05 PM" src="https://github.com/user-attachments/assets/c2c87c32-e523-4390-ad2d-25d5fa8432db" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 06 PM" src="https://github.com/user-attachments/assets/7a7fc18c-a0ae-4028-a819-227cc589dabd" />


## Laser Tripwire Security Alarm

<img width="1200" height="1600" alt="WhatsApp Image 2026-06-10 at 8 08 07 PM" src="https://github.com/user-attachments/assets/072d0450-39f7-4b1a-82e0-096f3d6830b7" />
<img width="1200" height="1600" alt="WhatsApp Image 2026-06-10 at 8 08 06 PM" src="https://github.com/user-attachments/assets/4cb8533b-c3ac-48c1-879c-a86ba88127c5" />


## Laser Security Counter

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 07 PM (2)" src="https://github.com/user-attachments/assets/9c6536b7-524d-4109-9a2d-3f4236786e33" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-10 at 8 08 07 PM (1)" src="https://github.com/user-attachments/assets/296cade0-9e00-4386-a454-00361f558757" />


## Mini Laser Security System

<img width="1200" height="1600" alt="WhatsApp Image 2026-06-10 at 8 08 08 PM" src="https://github.com/user-attachments/assets/db470838-b7d6-4305-8bcd-69899e43f99c" />
<img width="1200" height="1600" alt="WhatsApp Image 2026-06-10 at 8 08 08 PM (1)" src="https://github.com/user-attachments/assets/088029d0-1ebd-42e8-9227-02618a8420e9" />


# 6. Learning Outcome

After completing these projects, learners will be able to:

* Interface sensors and modules with Arduino Uno.
* Work with OLED displays using I2C communication.
* Understand digital input and output operations.
* Monitor ambient light using LDR sensors.
* Implement laser beam detection techniques.
* Design intrusion detection and security alarm systems.
* Control LEDs and buzzers using sensor inputs.
* Develop event counting and monitoring applications.
* Create real-time status dashboards.
* Apply embedded systems concepts to practical projects.

---

**Hemanth A S**
