#include <SD.h>
#include <SPI.h>
#include <NewPing.h>

#define CHIP_SELECT 4 // El pin CS del módulo de tarjeta SD

#define TRIGGER_PIN 0
#define ECHO_PIN 1 // Pin de trigger del sensor de ultrasonidos

#define TRIGGER_PIN 0
#define ECHO_PIN 1 // Pin de eco del sensor de ultrasonidos

#define LED1_PIN 7
#define LED2_PIN 8
#define LED3_PIN 9
#define LED4_PIN 10

NewPing ultrasonido(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);

  if (!SD.begin(CHIP_SELECT)) {
    Serial.println("Error al inicializar la tarjeta SD.");
    return;
  }
  Serial.println("Tarjeta SD inicializada correctamente.");
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

  // Abrir el archivo en modo escritura
  File dataFile = SD.open("distances.txt", FILE_WRITE);

  // Escribir la distancia medida en el archivo
  dataFile.print("Distancia: ");
  dataFile.println(d);

  // Cerrar el archivo
  dataFile.close();

  delay(1000); // Esperar un segundo antes de realizar la siguiente medición
}
