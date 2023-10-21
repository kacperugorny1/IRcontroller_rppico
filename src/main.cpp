#include <Arduino.h>
#include <IRremote.h>

#define ADC0 26
#define LED 22


void setup(){
  Serial.begin(9600);
  IrReceiver.begin(ADC0);
}

void loop() {
  if(IrReceiver.decode()){
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command);
  }
}
