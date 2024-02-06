// Definición de pines
const int pinLEDs[] = { 2, 3, 4, 5, 6 };  // Pines para los LEDs
const int pinBoton = 7;                   // Pin para el pulsador

// Otros parámetros
const int delayTiempo = 500;  // Retardo de medio segundo
bool direccion = true;        // Dirección de la secuencia (true: izquierda a derecha, false: derecha a izquierda)

void setup() {
  // Inicialización de pines
  for (int i = 0; i < 5; i++) {
    pinMode(pinLEDs[i], OUTPUT);
  }
  pinMode(pinBoton, INPUT_PULLUP);  // Configuración del pulsador con pull-up interno
}

void loop() {
  // Verificar si el botón está presionado
  if (digitalRead(pinBoton) == LOW) {
    // Cambiar dirección de la secuencia
    direccion = !direccion;
    delay(500);  // Debounce
  }

  // Encender LEDs secuencialmente en la dirección deseada
  if (direccion) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(pinLEDs[i], HIGH);
      delay(delayTiempo);
      digitalWrite(pinLEDs[i], LOW);
    }
  } else {
    for (int i = 4; i >= 0; i--) {
      digitalWrite(pinLEDs[i], HIGH);
      delay(delayTiempo);
      digitalWrite(pinLEDs[i], LOW);
    }
  }
}
