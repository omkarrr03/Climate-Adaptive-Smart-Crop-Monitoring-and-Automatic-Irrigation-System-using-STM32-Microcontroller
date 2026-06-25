# Climate-Adaptive-Smart-Crop-Monitoring-and-Automatic-Irrigation-System-using-STM32-Microcontroller

This project implements a smart climate-adaptive crop monitoring system using the STM32 Nucleo-F401RE microcontroller. The system continuously monitors environmental conditions such as temperature, humidity, and soil moisture, predicts crop disease risk, and automatically controls irrigation using interrupt-driven logic.
The system uses I2C-based environmental sensing, interrupt-driven irrigation control, and disease risk prediction to automate crop monitoring and watering.

# Working Principle

-TIM2 generates an interrupt every 1 second.

-STM32 reads temperature and humidity data from HTU21D via I2C.
-Soil moisture sensor generates an EXTI interrupt whenever soil condition changes.
-If soil becomes dry, irrigation pump is turned ON.
-If soil becomes wet, irrigation pump is turned OFF.
-Disease risk is evaluated based on environmental conditions.
-Sensor data and system status are displayed on the UART terminal.
