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
      
    if (Data=='C'){
      Serial.println("avancer bras");
      engrenage.write(180);} 

    if (Data=='E'){/* RECULER LE BRAS MECANIQUE*/
        Serial.println("reculer");
        engrenage.write(0);}
        
        
  }
      if ( digitalRead(C1)==LOW){
      Serial.print("capte pas");
    }
    if ( digitalRead(C1)==HIGH){
      Serial.println("Capte");
    /* SI LE CAPTEUR VOIT DU BLANC*/
      Serial.println("arrete");
      engrenage.write(90);
      
      Serial.println("ouvrir pince");
      pince.write(1500);
      
      Serial.println("fermer pince");
      pince.write(1000);}
}
