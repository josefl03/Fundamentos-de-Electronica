#define LED_PIN 3           // Define el pin al que está conectado el LED
#define POTENTIOMETER_PIN A0 // Define el pin al que está conectado el potenciómetro

void setup() {
  Serial.begin(9600);      // Inicia la comunicación serial para el monitoreo
  pinMode(LED_PIN, OUTPUT); // Configura el pin del LED como salida
}

void loop() {
  int potentiometerValue = analogRead(POTENTIOMETER_PIN); // Lee el valor del potenciómetro

  Serial.print("Valor potenciometro: ");
  Serial.println(potentiometerValue); // Imprime el valor del potenciómetro en el monitor serial

  analogWrite(LED_PIN, potentiometerValue / 4); // Ajusta la intensidad luminosa del LED con el valor del potenciómetro
  delay(100); // Espera para evitar cambios rápidos en la intensidad
}
