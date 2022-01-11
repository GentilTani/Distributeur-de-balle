#include<Servo.h>
Servo pince;
int capteur = 11;
Servo engrenage;
Servo reservoir;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  reservoir.attach(8);
  pince.attach(9);
  engrenage.attach(10);
  pinMode(capteur,INPUT);//capteur
  digitalWrite(capteur,LOW);//capteur
}

void loop() {
//  if(reponse utilisateur == "oui"){
//    reservoir.write(120);
//    delay(1000);
//    pince.write(1000);
//       if(digitalRead(capteur)==LOW){
//        engrenage.write(90);
//        pince.write(1500);
//      }
//      else{
//        engrenage.write(100);
//      }
//      engrenage.write(50);
//      
//      if(digitalRead(capteur)==LOW){
//        engrenage.write(90);
//      }
//  }
  Serial.println(analogRead(8));
  if ( digitalRead(capteur) ==LOW){
    Serial.println("engrenage actif"); 
    pince.write(1000);
    engrenage.write(90);
    reservoir.write(95);
  }
  else {
    Serial.println("Stopper engrenage + lachement de la balle");
    pince.write(1500);
    reservoir.write(100);
    engrenage.write(100);
  }
  
  
}
