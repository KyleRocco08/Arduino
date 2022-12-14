/*
 * Programmer: Kyle Rocco
 * Date: 12.12.22
 * Program: Ultrasonic Sercurity System
 * 
 * Resource:https://create.arduino.cc/projecthub/Krepak/ultrasonic-security-system-3afe13?ref=search&ref_id=red%20green%20yellow%20light%20echo%20sensor&offset=1
 */


int trigPin = 2;
int echoPin = 3;
int LEDlampRed = 4;
int LEDlampYellow = 5;
int LEDlampGreen = 6; 
int soundbuzzer = 7;
int sound = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow, OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 11) {
      digitalWrite(LEDlampGreen, HIGH);
}
  else {
      digitalWrite(LEDlampGreen, LOW);
  }
  
  if (distanceincm < 7) {
    digitalWrite(LEDlampYellow, HIGH);
}
  else {
    digitalWrite(LEDlampYellow,LOW);
  }
  if (distanceincm < 4) {
    digitalWrite(LEDlampRed, HIGH);
    tone(soundbuzzer, sound);
}
  else {
    digitalWrite(LEDlampRed,LOW);
     noTone(soundbuzzer);
  }
 
  if (distanceincm > 10 || distanceincm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println(" cm");
    
  }
  
  delay(300);
}
