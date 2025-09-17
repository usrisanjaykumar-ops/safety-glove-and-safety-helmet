#include <Wire.h>
#include <U8g2lib.h>
#include <SoftwareSerial.h>

// OLED Display Setup
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0); // I2C OLED

// Bluetooth Module on D7 (TX), D8 (RX)
SoftwareSerial BT(7, 8); // TX, RX

// Pin Definitions
#define MQ2_PIN A0
#define SOUND_SENSOR_PIN 5
#define HALL_SENSOR_PIN 2
#define VIBRATOR_PIN 10

void setup() {
  // Start Serial & Bluetooth
  Serial.begin(9600);
  BT.begin(9600);

  // Sensor and Output Pin Modes
  pinMode(MQ2_PIN, INPUT);
  pinMode(SOUND_SENSOR_PIN, INPUT);
  pinMode(HALL_SENSOR_PIN, INPUT_PULLUP);  // Hall sensor needs pull-up
  pinMode(VIBRATOR_PIN, OUTPUT);
  digitalWrite(VIBRATOR_PIN, LOW);

  // Start OLED
  u8g2.begin();
}

void loop() {
  // Read all sensor values
  int gasValue = analogRead(MQ2_PIN);
  bool soundDetected = digitalRead(SOUND_SENSOR_PIN) == HIGH;
  bool hallTriggered = digitalRead(HALL_SENSOR_PIN) == LOW;

  // Determine if danger is detected
  bool danger = (gasValue > 400) || soundDetected || hallTriggered;

  // Control vibrator
  digitalWrite(VIBRATOR_PIN, danger ? HIGH : LOW);

  // Debug to Serial Monitor
  Serial.print("Gas: "); Serial.print(gasValue);
  Serial.print(" | Sound: "); Serial.print(soundDetected ? "HIGH" : "LOW");
  Serial.print(" | Hall: "); Serial.println(hallTriggered ? "MAGNET" : "CLEAR");

  // Send over Bluetooth
  BT.print("Gas: "); BT.print(gasValue);
  BT.print(" | Sound: "); BT.print(soundDetected ? "HIGH" : "LOW");
  BT.print(" | Hall: "); BT.println(hallTriggered ? "MAGNET" : "CLEAR");

  // Show on OLED
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(0, 15); u8g2.print("Smart Helmet");
  u8g2.setCursor(0, 30); u8g2.print("Gas: "); u8g2.print(gasValue);
  u8g2.setCursor(0, 45); u8g2.print("Sound: "); u8g2.print(soundDetected ? "HIGH" : "LOW");
  u8g2.setCursor(0, 60); u8g2.print("Hall: "); u8g2.print(hallTriggered ? "MAGNET" : "CLEAR");
  u8g2.sendBuffer();

  delay(300);  // Delay for stability
}



