#include <Arduino.h>

const int LED_PIN = 2;

unsigned long previousMillis  = 0;
const unsigned long interval = 2000;

bool ledstate = false;

void setup(){
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  Serial.println("ESP32 started");

}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      ledstate = !ledstate;
      digitalWrite(LED_PIN, ledstate);

      Serial.print("LED state: ");
      Serial.println(ledstate);
  }
}