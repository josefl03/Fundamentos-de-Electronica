#include <DHT11.h>
#include <TM1637Display.h>

#define DHTPIN 0

#define GREEN_PIN 8
#define RED_PIN 11

#define CLK_PIN 7
#define DIO_PIN 4

TM1637Display tm1637(CLK_PIN, DIO_PIN);

DHT11 dht11(DHTPIN);

void setup() {
  Serial.begin(9600);

  // Configuración de pines para LEDs y ajuste del brillo del display
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  tm1637.setBrightness(7);
}

void loop() {
  // Lectura de temperatura del sensor DHT11
  float temp = dht11.readTemperature();

  // Impresión de la temperatura en el puerto serie
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print("°C");

  // Control de LEDs basado en la temperatura
  if (temp < 22.0f) {
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
  } else {
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
  }

  // Mostrar la temperatura en el display de 7 segmentos
  tm1637.showNumberDec(temp);

  // Breve pausa
  delay(500);

  // Lectura de la humedad del sensor DHT11
  float hum = dht11.readHumidity();

  // Impresión de la humedad en el puerto serie
  Serial.print(", Humedad: ");
  Serial.print(hum);
  Serial.println("%");

  // Breve pausa antes de repetir el bucle
  delay(500);
}
