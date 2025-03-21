#include <Servo.h>
Servo myservo;  //Crear un objeto Servo para contrlar el servomotor

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9); //conectamos el pin 9 al objeto Servo
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
}
