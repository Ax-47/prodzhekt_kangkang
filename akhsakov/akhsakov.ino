#include <ESP32Servo.h>
const int pingPin = 13;
int inPin = 12;
int servopin =19;
Servo servo1;
void setup() {
  Serial.begin(9600);
}

void loop()
{
  
  long duration, cm;
  servo1.attach(servopin);
  pinMode(pingPin, OUTPUT);


  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (InRange(cm)){
    servo1.write(90);
  }else{
    servo1.write(180);
  }
  delay(100);
  
}

long microsecondsToCentimeters(long microseconds)
{

  return microseconds / 29 / 2;
}


bool InRange(long range) {
  return range > 20 && range < 50;
}
