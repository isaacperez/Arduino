const int ledAmarillo =10;
const int ledRojo = 8;


void setup() {
  
  // put your setup code here, to run once:
  
  // Establecemos la salida para los leds
  pinMode(ledAmarillo,OUTPUT);
  pinMode(ledRojo,OUTPUT);

  //Inicializo el puerto serial a 9600 baudios
  Serial.begin(9600);

}


void loop() {
  
  // put your main code here, to run repeatedly:

  delay(1000);

  // Mientras que haya datos que leer los voy leyendo y parpadeo segun el número indicado
  while(Serial.available()){

    // Leemos el caracter actual
    char caracterActual = Serial.read();

    // Hacemos el procesamiento para el caracter
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    
  }
  
  if (Serial.available()) { //Si está disponible
      char c = Serial.read(); //Guardamos la lectura en una variable char
      if (c == 'H') { //Si es una 'H', enciendo el LED
         digitalWrite(led, HIGH);
      } else if (c == 'L') { //Si es una 'L', apago el LED
         digitalWrite(led, LOW);
      }
   }

}
