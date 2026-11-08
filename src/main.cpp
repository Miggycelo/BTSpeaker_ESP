#include <Arduino.h>

const int DT_PIN = 26;
const int CLK_PIN = 25;
int lastvolume = 0;

volatile int volume = 0;

void IRAM_ATTR readEncoder() {
  int dstate = digitalRead(DT_PIN);
  int clkstate = digitalRead(CLK_PIN);

  if (dstate == clkstate) {
    volume--;
  } else{
    volume++;
  }
}

void setup(){
  Serial.begin(115200);
  pinMode(DT_PIN, INPUT);
  Serial.println("ESP32 started");
  pinMode(CLK_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLK_PIN), readEncoder, CHANGE);
}

void loop() {
  if (volume != lastvolume) {
    lastvolume = volume;
      Serial.print("Volume: ");
      Serial.println(volume);
  }
}