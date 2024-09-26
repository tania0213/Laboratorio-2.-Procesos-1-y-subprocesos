// Definimos los pines de los LEDs
#define LED1_RED 13
#define LED1_BLUE 12
#define LED1_GREEN 11

#define LED2_RED 10
#define LED2_BLUE 9
#define LED2_GREEN 8

#define LED3_RED 7
#define LED3_BLUE 6
#define LED3_GREEN 5


// Pin del SlideSwitch para encender y apagar el proceso
#define SLIDE_SWITCH 2

void setup() {
  // Configuración de los pines de los LEDs como salida
  digitalWrite(LED1_RED, OUTPUT);
  digitalWrite(LED1_GREEN, OUTPUT);
  digitalWrite(LED1_BLUE, OUTPUT);

  digitalWrite(LED2_RED, OUTPUT);
  digitalWrite(LED2_GREEN, OUTPUT);
  digitalWrite(LED2_BLUE, OUTPUT);

  digitalWrite(LED3_RED, OUTPUT);
  digitalWrite(LED3_GREEN, OUTPUT);
  digitalWrite(LED3_BLUE, OUTPUT);

  digitalWrite(SLIDE_SWITCH, OUTPUT);  // Configuramos el SlideSwitch como Salida

  Serial.begin(9600);  // Iniciar el monitor serial
}

void led1_colors(int r, int g, int b) {
  analogWrite(LED1_RED, r);
  analogWrite(LED1_GREEN, g);
  analogWrite(LED1_BLUE, b);
}

void led2_colors(int r, int g, int b) {
  analogWrite(LED2_RED, r);
  analogWrite(LED2_GREEN, g);
  analogWrite(LED2_BLUE, b);
}

void led3_colors(int r, int g, int b) {
  analogWrite(LED3_RED, r);
  analogWrite(LED3_GREEN, g);
  analogWrite(LED3_BLUE, b);
}

void loop() {
  int switchState = digitalRead(SLIDE_SWITCH);  // Leer el estado del SlideSwitch
  
  if (switchState == HIGH) {
    
  led1_colors(0, 255, 0);  // semaforo 1 verde
  led2_colors(255, 0, 0);  // Semáforo 2 rojo
  led3_colors(255, 0,0 );  // Semáforo 3 rojo
  delay(2000); //Esperar 2 seg
  
  led1_colors(255, 0, 0);  // semaforo 1 rojo
  led2_colors(0, 255, 0);  // Semáforo 2 verde
  led3_colors(255, 0, 0);  // Semáforo 3 rojo
  delay(2000); //Esperar 2 seg
  
  led1_colors(255, 0, 0);  // semaforo 1 rojo
  led2_colors(255, 0, 0);  // Semáforo 2 rojo
  led3_colors(0, 255,0);  // Semáforo 3 verde
  delay(2000); //Esperar 2 seg

  } else {
    // El proceso está apagado, los semáforos deben estar intermitentes en amarillo
    led1_colors(255, 255, 0);  // Semáforo 1 amarillo
    led2_colors(255, 255, 0);  // Semáforo 2 amarillo
    led3_colors(255, 255, 0);  // Semáforo 3 amarillo
    delay(500);  // Esperar 0.5 segundos

    led1_colors(0, 0, 0);  // Apagar Semáforo 1
    led2_colors(0, 0, 0);  // Apagar Semáforo 2
    led3_colors(0, 0, 0);  // Apagar Semáforo 3
    delay(500);  // Esperar 0.5 segundos
  }
}

