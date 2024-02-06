#include <TM1637Display.h>

#define CLK_PIN 7
#define DIO_PIN 4

TM1637Display tm1637(CLK_PIN, DIO_PIN);

#define BOTON1_PIN 2 // Pulsador para jugador 1
#define BOTON2_PIN 3 // Pulsador para jugador 2

int contadorJugador1 = 0;
int contadorJugador2 = 0;

void setup() {
  pinMode(BOTON1_PIN, INPUT); // Configura el pin del botón del jugador 1 como entrada
  pinMode(BOTON2_PIN, INPUT); // Configura el pin del botón del jugador 2 como entrada

  tm1637.setBrightness(7); // Configura el brillo del display
}

void loop() {
  if (debounceButton(BOTON1_PIN)) // Incrementa el contador del jugador 1 al presionar el botón
    contadorJugador1++;

  if (debounceButton(BOTON2_PIN)) // Incrementa el contador del jugador 2 al presionar el botón
    contadorJugador2++;

  // Prepara los segmentos para mostrar en el display con los contadores de ambos jugadores
  uint8_t segments[] = {
    (uint8_t)((contadorJugador2 >> 8) & 0xFF),
    (uint8_t)(contadorJugador2 & 0xFF),
    (uint8_t)((contadorJugador1 >> 8) & 0xFF),
    (uint8_t)(contadorJugador1 & 0xFF)
  };

  tm1637.setSegments(segments); // Actualiza el display con los segmentos calculados

  delay(100); // Espera para evitar múltiples incrementos por un solo clic
}

// Función para debounce del botón
int debounceButton(int pin) {
  int state = digitalRead(pin);
  delay(10); // Ajustar este valor según sea necesario
  return state == digitalRead(pin);
}
