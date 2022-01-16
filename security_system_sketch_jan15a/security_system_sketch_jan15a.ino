#define trigPin 7
#define echoPin 6
#define LEDlampRed 9
#define LEDlampYellow 10
#define LEDlampGreen 11
#define soundbuzzer 3
int sound = 15;

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

digitalWrite(LEDlampGreen, HIGH);
digitalWrite(LEDlampYellow, HIGH);
digitalWrite(LEDlampRed, HIGH);


if (distanceincm < 50) {
digitalWrite(LEDlampGreen, HIGH);
//sound = 50;
}

else {
digitalWrite(LEDlampGreen, LOW);
}

/*
if (distanceincm > 50 || distanceincm <= 35){
Serial.println("Outside the permissible range of distances");
noTone(soundbuzzer);
}
else {
Serial.print(distanceincm);
Serial.println(" cm");
//tone(soundbuzzer, sound);
//delay(300);
}
*/

if (distanceincm < 35) {
digitalWrite(LEDlampYellow, HIGH);
sound = 500;
}
else {
digitalWrite(LEDlampYellow,LOW);
}

if (distanceincm > 35 || distanceincm <= 20){
Serial.println("Outside the permissible range of distances");
noTone(soundbuzzer);
}
else {
Serial.print(distanceincm);
Serial.println(" cm");
tone(soundbuzzer, sound);
delay(300);
}



if (distanceincm < 20) {
digitalWrite(LEDlampRed, HIGH);
sound = 1500;
}
else {
digitalWrite(LEDlampRed,LOW);
}

if (distanceincm > 20 || distanceincm <= 0){
Serial.println("Outside the permissible range of distances");
noTone(soundbuzzer);
}
else {
Serial.print(distanceincm);
Serial.println(" cm");
tone(soundbuzzer, sound);
}

delay(300);
}
