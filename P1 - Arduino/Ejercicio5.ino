#include <NewPing.h>
#include <TM1637Display.h>

#define TRIGGER_PIN 0
#define ECHO_PIN 1

#define LED1_PIN 8
#define LED2_PIN 9
#define LED3_PIN 10
#define LED4_PIN 11

#define CLK_PIN 7
#define DIO_PIN 4

// Configuración del sensor ultrasónico y el display de 7 segmentos
NewPing ultrasonido(TRIGGER_PIN, ECHO_PIN);
TM1637Display tm1637(CLK_PIN, DIO_PIN);

void setup() {
  Serial.begin(9600);

  // Configuración de pines de salida para los LEDs indicadores
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);

  // Configuración del brillo del display de 7 segmentos
  tm1637.setBrightness(7);
}

void loop() {
  // Medición de la distancia con el sensor ultrasónico
  unsigned int t = ultrasonido.ping();
  unsigned int d = t / US_ROUNDTRIP_CM;

  // Mostrar la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.println("cm");

  // Encender el LED principal y controlar LEDs adicionales según la distancia
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, d < 40 ? HIGH : LOW);
  digitalWrite(LED3_PIN, d < 30 ? HIGH : LOW);
  digitalWrite(LED4_PIN, d < 20 ? HIGH : LOW);

  // Mostrar la distancia en el display de 7 segmentos
  tm1637.showNumberDec(d);

  // Pequeña pausa para evitar lecturas demasiado frecuentes
  delay(100);
}
