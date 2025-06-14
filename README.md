# TempMate ☕  
TempMate is a smart temperature-regulating mug that keeps your drink at the perfect sipping temperature. It uses temperature sensors, a PID control loop, and PWM control to apply just the right amount of heat—saving battery and keeping your drink warm without overheating. Compact and portable, it’s perfect for enjoying hot drinks anywhere, anytime.

---

## 🔧 Features

- ✅ Maintains optimal sipping temperature
- 🔄 Smart temperature sensing
- 🧠 PID control for precise temperature regulation
- ⚡ PWM-based energy-efficient heating
- 🔋 Battery-saving design
- 👜 Portable and lightweight
- 🔌 Embedded microcontroller-based control system

---

## 💡 How It Works

1. **Temperature Sensor**: Continuously monitors the drink's temperature.
2. **Microcontroller**: Reads sensor data and calculates the required heating power.
3. **PID Control Loop**: A closed-loop control system calculates the error between current and target temperature, adjusting the PWM duty cycle for smooth and accurate heating.
4. **PWM Control with MOSFET Switching**: A power MOSFET (e.g., IRF540N) switches the heating element on and off rapidly based on the PID output, ensuring efficient and safe power delivery.
5. **Feedback Loop**: Automatically adjusts heating in real time to preserve beverage quality and extend battery life.

---

## 🧰 Tech Stack / Hardware

- Microcontroller (Arduino Uno)
- NTC Thermistor or Digital Temperature Sensor (e.g., DS18B20)
- Heating Element 
- Power MOSFET (IRF540N) for PWM switching
- Power Source (Li-ion battery)
- Basic passive components (resistors, capacitors)

---



