#include <Arduino.h>

const int DT_PIN = 26;
int volume = 0;

void setup(){
  Serial.begin(115200);
  pinMode(DT_PIN, INPUT);
  Serial.println("ESP32 started");
}

void loop() {
  int dstate = digitalRead(DT_PIN);

  if (dstate == HIGH){
    volume++;
  } else{
    volume--;
  }
  
  Serial.print("Volume: ");
  Serial.println(volume);
}