#include <Arduino.h>

const int DT_PIN = 26;
<<<<<<< HEAD
const int CLK_PIN = 25;

=======
>>>>>>> 545556589de361557e88cd9b7840a5d237ce8eaf
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
<<<<<<< HEAD
  }
  
  Serial.print("Volume: ");
  Serial.println(volume);

  attachInterrupt(digitalPinToInterrupt(CLK_PIN), readEncoder, CHANGE);
}

 void IRAM_ATTR readEncoder() {
  int dstate = digitalRead(DT_PIN);

  if (dstate == HIGH){
    volume++;
  } else{
    volume--;
=======
>>>>>>> 545556589de361557e88cd9b7840a5d237ce8eaf
  }
  
  Serial.print("Volume: ");
  Serial.println(volume);
}