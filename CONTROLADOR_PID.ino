const int EchoPin = 5;
const int TriggerPin = 6;
const int PinRele = 4;
const int LedPinAzul = 12;
float distancia;
long tiempo;
int segundos = 0; 
int LABEL = 1;//para la comunicacion
void setup() {
   Serial.begin(9600); //velocidad de comunicacion
   pinMode(LedPinAzul, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(PinRele, OUTPUT);
   pinMode(EchoPin, INPUT);
   Serial.println("CLEARDATA");//reseteamos la comunicacion
   Serial.println("LABEL,hora,valor,segundos");//damos nombres a las columnas de excel
}
 
void loop() {
  segundos++;//incrementamos segundos
  digitalWrite(TriggerPin, HIGH);  //se envía un pulso para activar el sensor
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  // medimos el pulso de respuesta
  tiempo = (pulseIn(EchoPin, HIGH)/2);
 
  // dividido por 2 por que es el
  // tiempo que el sonido tarda
  // en ir y en volver
  // ahora calcularemos la distancia en cm
  // sabiendo que el espacio es igual a la velocidad por el tiempo
  // y que la velocidad del sonido es de 343m/s y que el tiempo lo
  // tenemos en millonesimas de segundo
 
  distancia = float(tiempo * 0.0343);

   //Serial.print("Distancia: "); // imprime la distancia en el Monitor Serie
   //Serial.println(distancia);
   //Serial.print("Segundos: ");
   //Serial.println(millis()/1000);
   Serial.print("DATA,TIME");
   Serial.print(",");
   Serial.print(distancia);
   Serial.print(",");
   Serial.println(segundos);
   
         if(distancia >=10){
         digitalWrite(LedPinAzul , HIGH);
         digitalWrite(PinRele , LOW);
        
} 

         else {
             digitalWrite(LedPinAzul , LOW);
             digitalWrite(PinRele , HIGH);
           }
        if(segundos >90){// limitamos caa cantidades delescturas que se haran
         segundos = 0;
        Serial.println("ROW,SET,2");//imprimimos los valores desde la posiscion 2 en ecxel
} 
         
delay(1000);// tiempo de muestreo

}
