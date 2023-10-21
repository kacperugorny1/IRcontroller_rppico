#include <Arduino.h>
#include <IRremote.h>

#define ADC0 26
#define LED 22
/*
CH- - 69
CH  - 70
CH+ - 71
|<< - 68
>>| - 64
>|| - 67
-   - 7
+   - 21
EQ  - 9
0   - 22
100+- 25
200+- 13
1   - 12
2   - 24
3   - 94
4   - 8
5   - 28
6   - 90
7   - 66
8   - 82
9   - 74


*/

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(ADC0);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  if(IrReceiver.decode()){
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command);
    digitalWrite(LED, HIGH);
    delay(100);
  }
  digitalWrite(LED,LOW);
}
