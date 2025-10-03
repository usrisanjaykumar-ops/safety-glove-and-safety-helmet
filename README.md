# safety-glove-and-safety-helmet
Wearable safety device that detects gas and heat (Arduino).
# Smart Glove

This is an Arduino-based wearable safety device.  
- Detects gas leaks and heat.  
- Warns the user with buzzer, LED, and OLED display.  
- Helps in kitchens, factories, and homes.  

## Usage
Wear the glove → if danger is detected → it shows alert + sound.  

## Components
- Arduino UNO  
- MQ2 Gas Sensor  
- LM35 Temperature Sensor  
- OLED Display  
- Buzzer, LED  

## How to Run
1. Open `SmartGlove.ino` in Arduino IDE.  
2. Install library: U8g2 (for OLED).  
3. Connect sensors to pins:  
   - MQ2 → A0  
   - LM35 → A1  
   - OLED → SDA A4, SCL A5  
   - LED → D8  
   - Buzzer → D9  
4. Upload code → Done.  
# Smart Helmet

This is an Arduino-based safety helmet project.  
- Detects harmful gas leaks and loud accident sounds.  
- Vibrates and shows alerts on an OLED display.  
- Sends information to a mobile phone via Bluetooth.  
- Works only when the helmet is worn (Hall sensor check).  

## Usage
Wear the helmet → if danger is detected → it vibrates, shows warning on screen, and can send alerts to phone.  
Helps bike riders, factory workers, and people in risky environments.  

## Components
- Arduino UNO  
- MQ2 Gas Sensor (A0)  
- Hall Sensor (D2) + Magnet  
- Sound Sensor (D5)  
- IR Sensor (D8) + Remote  
- Vibrator Motor (D10)  
- HC-05 Bluetooth Module (TX → D9, RX → D10)  
- OLED Display (SDA A4, SCL A5)  

## How to Run
1. Open `SmartHelmet.ino` in Arduino IDE.  
2. Install library: U8g2 (for OLED).  
3. Connect sensors to pins as listed above.  
4. Upload code → Done.  


## Citation

If you use this project, please cite it as:

Kumar, Sri Sanjay. (2025). Low-Cost Wearable Safety Devices: Smart Glove and Smart Helmet. Zenodo. [https://doi.org/10.5281/zenodo.17254484]

## Notes
- Vibrator turns on when gas value is high or loud sound is detected.  
- OLED shows all alerts clearly (no animation).  
- Bluetooth can send data to a connected phone.  
- IR Remote can trigger alerts manually.  
