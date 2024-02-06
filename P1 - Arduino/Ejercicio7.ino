#include <AccelStepper.h>
#include <NewPing.h>

// Definir pines del motor paso a paso y del driver ULN2003
#define MOTOR_PIN_1 8
#define MOTOR_PIN_2 9
#define MOTOR_PIN_3 10
#define MOTOR_PIN_4 11

// Definir pines de los potenciómetros
#define POT_1_PIN A0
#define POT_2_PIN A1

// Definir pines del sensor de ultrasonidos
#define TRIG_PIN 2
#define ECHO_PIN 3

// Crear instancia del motor paso a paso
AccelStepper motor(AccelStepper::FULL4WIRE, MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_3, MOTOR_PIN_4);

// Crear instancia del sensor de ultrasonidos
NewPing ultrasonido(TRIG_PIN, ECHO_PIN);

void setup() {
  // Inicializar el motor con una velocidad máxima y aceleración
  motor.setMaxSpeed(1000);
  motor.setAcceleration(500);

  // Inicializar pines de entrada
  pinMode(POT_1_PIN, INPUT);
  pinMode(POT_2_PIN, INPUT);
}

void loop() {
  // Leer los valores de los potenciómetros
  int position = analogRead(POT_1_PIN);
  int speed = analogRead(POT_2_PIN);

  // Mapear los valores de los potenciómetros al rango adecuado
  int mappedPosition = map(position, 0, 1023, 0, 1000);
  int mappedSpeed = map(speed, 0, 1023, 0, 1000);

  // Establecer la velocidad del motor según el potenciómetro de velocidad
  motor.setSpeed(mappedSpeed);

  // Obtener la distancia medida por el sensor de ultrasonidos
  int distance = ultrasonido.ping_cm();

  // Si no hay obstáculos, mover el motor a la posición deseada
  if (distance > 10) {
    // Establecer la posición del motor según el potenciómetro de posición
    motor.runToNewPosition(mappedPosition);
  } else {
    // Detener el motor si hay un obstáculo
    motor.stop();
    motor.runToPosition(); // Necesario para actualizar la posición interna del motor
  }
}
