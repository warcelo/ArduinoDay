const int Trigger = 2; //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//iniciailzamos la comunicación serie
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

  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(500);          //Hacemos una pausa de 500ms
}
