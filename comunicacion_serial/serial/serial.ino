const int ledAmarillo =8;
const int ledVerde = 10;


// Codigo inicial que se ejecuta una única vez
void setup() {

  randomSeed(millis());    // genera una semilla para aleatorio a partir de la función millis()

  //-----------------------------------------------------------------
  // Establecemos la salida para los leds
  //-----------------------------------------------------------------
  pinMode(ledAmarillo,OUTPUT);
  pinMode(ledVerde,OUTPUT);

  //-----------------------------------------------------------------
  //Inicializamos el puerto serial a 9600 baudios
  //-----------------------------------------------------------------
  Serial.begin(9600);

}


//-----------------------------------------------------------------
//Creamos las constantes globales
//-----------------------------------------------------------------
const int NUM_BYTE_MEDICION = 5;
const int DIVISOR = pow(10,NUM_BYTE_MEDICION-1);

int bytesMedicionPesoA[NUM_BYTE_MEDICION];
int bytesMedicionPesoB[NUM_BYTE_MEDICION];

 
// Codigo principal que se repetirá
void loop() {
  
  // Por ahora solo cuando recibamos una orden realizamos la medición
  
}


// Esta función solo se ejecuta cuando recibimos algun mensaje del puerto serial. Se comprueba en cada ejecucion de loop()
void serialEvent(){

  //Serial.println("Tenemos dato/s");

  //-----------------------------------------------------------------
  // Realizamos las mediciones 
  //-----------------------------------------------------------------
  float gramosPesoA = random(10000)/10.0;   // Obtenemos los gramos entre [0-1000]
  float gramosPesoB = random(10000)/10.0;   // Obtenemos los gramos entre [0-1000]
 
  //Serial.println("------");
  //Serial.println(gramosPesoA);
  //Serial.println(gramosPesoB);
  //Serial.println(" ");

  

  // Vaciamos el buffer antes de continuar
  while(Serial.available()){ 
    Serial.read();
    //Serial.println("Vaciando buffer...");
  }


  //-----------------------------------------------------------------
  // Pasamos las mediciones al formato esperado
  //-----------------------------------------------------------------
  int pesoAenEnterosConPrimerDecimal{gramosPesoA*10};
  int pesoBenEnterosConPrimerDecimal{gramosPesoB*10};

  for(int i = 0, divisor = DIVISOR; i < NUM_BYTE_MEDICION; i++, divisor /= 10){
    
    bytesMedicionPesoA[i] = pesoAenEnterosConPrimerDecimal / divisor;
    bytesMedicionPesoB[i] = pesoBenEnterosConPrimerDecimal / divisor;

    pesoAenEnterosConPrimerDecimal %= divisor;
    pesoBenEnterosConPrimerDecimal %= divisor;

    //Serial.println(bytesMedicionPesoA[i]);
    //Serial.println(bytesMedicionPesoB[i]);
  }

  
  //-----------------------------------------------------------------
  // Indicamos con el led verde que hemos leido un dato
  //-----------------------------------------------------------------
  digitalWrite(ledVerde, HIGH);
  delay(500);
  digitalWrite(ledVerde, LOW);


  //-----------------------------------------------------------------
  // Respondemos la petición de envio de datos
  //-----------------------------------------------------------------
  for(int i=0; i < NUM_BYTE_MEDICION; i++){
    Serial.write(bytesMedicionPesoA[i]);
  }
  
  for(int i=0; i < NUM_BYTE_MEDICION; i++){
    Serial.write(bytesMedicionPesoB[i]);
  }
    
}
