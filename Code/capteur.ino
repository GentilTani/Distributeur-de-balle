//capteurs
int C1 = 11;

void setup() {
  Serial.begin(9600);
  pinMode(C1,INPUT);
  
  digitalWrite(C1,LOW);
  
  }

void loop() {

  if ( digitalRead(C1) ==LOW){
    Serial.println("engrenage actif"); 
  }
  
  else {
    Serial.println("Stopper engrenage + lachement de la balle");
  }
  
  
  

}
