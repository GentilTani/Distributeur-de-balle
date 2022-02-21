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
    if(Data=='A'){
      PWM=BlueT.parseInt();
      Serial.println(PWM);
      Serial.println("reservoir actif"); 
      
      reservoir.write(100);
      
    }
    if (Data=='B'){
        Serial.println("arreter balle");
        reservoir.write(90);}
    
    if (Data=='C'){
        Serial.println("avancer bras");
        engrenage.write(180);}
    if(Data=='D'){
      Serial.println("arrete");
      engrenage.write(90);
    }

    if (Data=='E'){
        Serial.println("reculer");
        engrenage.write(0);}
    if (Data=='F'){
        Serial.println("ouvrir pince");
        pince.write(1500);}
        
   if (Data=='G'){
        Serial.println("fermer pince");
        pince.write(1000);}
   
    
  }
}
