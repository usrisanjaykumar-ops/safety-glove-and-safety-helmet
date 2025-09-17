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
