# 🚗 Parking-Sensor

This project is a simple but effective **car parking sensor system** built using an Arduino board, an **ultrasonic distance sensor**, a **buzzer**, and an **RGB LED**. The sensor continuously measures the distance to the nearest object (e.g., a wall or another car) and provides both **auditory** and **visual feedback** to help with parking.

---

## 📦 Features

- **Real-time distance measurement** using an ultrasonic sensor
- **Variable-pitch sound alerts** via a buzzer (higher pitch = closer object)
- **RGB LED status indication**:
  - 🔴 Red: Object very close (under 20cm)
  - 🟡 Yellow: Caution zone (20–50cm)
  - 🟢 Green: Safe distance (50–100cm)
  - 🔵 Blue: No object detected / out of range

---

## 🔧 Components Used

- Arduino Uno (or compatible board)
- Ultrasonic sensor (HC-SR04)
- Passive buzzer
- RGB LED (common cathode)

---

## 🛠️ How It Works

- The ultrasonic sensor (HC-SR04) is connected to digital pins `6` (trigger) and `5` (echo).
- The buzzer is connected to digital pin `7`.
- The RGB LED is connected to PWM-enabled pins `9` (Red), `10` (Green), and `11` (Blue).
- The sensor reads distance in centimeters.
- If the distance is **greater than 100cm**, the LED turns blue and no sound is emitted.
- If the object is within **100cm**, the buzzer emits a **beep with a frequency** that increases as the object gets closer.
- The RGB LED color reflects the distance range.

![WhatsApp Image 2025-04-05 at 19 08 25_7d5e2b78](https://github.com/user-attachments/assets/03910286-1329-4473-af7a-7ad62d559ec9)


---

