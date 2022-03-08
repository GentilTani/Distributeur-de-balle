#include<SoftwareSerial.h>
#include<Servo.h>
#define RX 10
#define TX 11

int C1= 9;

Servo reservoir;
Servo engrenage;
Servo pince;
SoftwareSerial BlueT(RX,TX);
int PWM=194;
char Data;


void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  pinMode(C1,INPUT);
  
  reservoir.attach(8); 
  engrenage.attach(7);
  pince.attach(6);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (BlueT.available()){
    Data=BlueT.read();
    if(Data=='A'){/* RESERVOIR DE BALLES*/
        PWM=BlueT.parseInt();
        Serial.println(PWM);
        Serial.println("reservoir actif"); 
        reservoir.write(100);}
      
    if (Data=='B'){/* ARRETER RESERVOIR DE BALLES*/
        Serial.println("arreter balle");
        reservoir.write(90);}
      
    if (Data=='C'){/* AVANCER LE BRAS MECANIQUE*/
        Serial.println("avancer bras");
        engrenage.write(130);} 

    if (Data=='E'){/* RECULER LE BRAS MECANIQUE*/
        Serial.println("reculer");
        engrenage.write(50);}
        
    if (Data=='F'){/*ARRETER LE BRAS MECANIQUE*/
        Serial.println("arret du bras");
        engrenage.write(90);    
    }
    
  }
      if ( digitalRead(C1)==HIGH){
      Serial.print("capte la marque noire");
      Serial.println("ouverture de la pince");
      pince.write(1000);
    }
    
    if ( digitalRead(C1)==LOW){
      Serial.println("Pas de marque");
    /* SI LE CAPTEUR VOIT DU BLANC*/
      Serial.println("fermer pince");
      pince.write(1500);
}
}
