#include <Servo.h>
Servo myservo;  //Crear un objeto Servo para contrlar el servomotor

const int Trigger = 2; //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros
float ang;
 
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9); //conectamos el pin 9 al objeto Servo
  pinMode(Trigger, OUTPUT); //definir pin como salida
  pinMode(Echo, INPUT);  //definir pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

  ang = map(d, 0, 50, 0, 180); //Escalamos de 0 - 50cm a 0° - 180° 
  myservo.write(ang);
  delay(500);          //Hacemos una pausa de 500ms
}
