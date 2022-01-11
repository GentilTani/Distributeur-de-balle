#include<Servo.h>
Servo reservoir;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  reservoir.attach(8);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  reservoir.write(100);
  delay(2000);
  reservoir.write(80);
  
}
