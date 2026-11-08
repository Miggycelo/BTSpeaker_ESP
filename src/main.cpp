#include <Arduino.h>
#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);
const int DT_PIN = 26;
const int CLK_PIN = 25;
const int SW_PIN = 27;
int lastvolume = 0;
volatile int volume = 0;
volatile unsigned long lastInterruptTime = 0;
int lastButtonState = HIGH;
unsigned long lastpressedtime = 0;
const int MAX_VOLUME = 100;


void IRAM_ATTR readEncoder() {
  unsigned long now = millis();
  if (now - lastInterruptTime < 20){
    return;
  }
  lastInterruptTime = now;

  int dstate = digitalRead(DT_PIN);
  int clkstate = digitalRead(CLK_PIN);

  if (dstate == clkstate) {
    volume--;
  } else{
    volume++;
  }

  if(volume < 0){
    volume = 0;
  } else if (volume > MAX_VOLUME){
    volume = MAX_VOLUME;
  }
}

void setup(){
  Serial.begin(115200);
  pinMode(DT_PIN, INPUT_PULLUP);
  Serial.println("ESP32 started");
  pinMode(CLK_PIN, INPUT_PULLUP);
  pinMode(SW_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(CLK_PIN), readEncoder, CHANGE);
  a2dp_sink.start("A.M. Speaker");
}

void loop() {
  if (volume != lastvolume) {
    lastvolume = volume;
      Serial.print("Volume: ");
      Serial.println(volume);
  }

  int buttonState = digitalRead(SW_PIN);
  unsigned long now = millis();

  if (buttonState == LOW && lastButtonState == HIGH && (now - lastInterruptTime) > 200) {
    Serial.println("Button pressed");
  }
  lastButtonState = digitalRead(SW_PIN);

}