# P1 - Arduino

`Ejercicio1.ino` controla una secuencia de LEDs que se encienden y apagan de manera secuencial en dos direcciones: de izquierda a derecha y de derecha a izquierda. También detecta si un botón está presionado para cambiar la dirección de la secuencia.

`Ejercicio2.ino` controla un juego para dos jugadores. Cada jugador tiene un botón, al presionarlo se incrementa su contador respectivo. Los contadores se muestran en un display de siete segmentos. Además, se utiliza una función para evitar rebotes en la lectura del botón.

`Ejercicio3.ino` lee la temperatura y la humedad del sensor DHT11. Luego, muestra la temperatura en un display de 7 segmentos y enciende un LED verde si la temperatura es inferior a 22°C, y un LED rojo en caso contrario.

`Ejercicio4.ino` controla un LED con un potenciómetro. La posición del potenciómetro determina la intensidad de luz del LED usando la modulación PWM.

`Ejercicio5.ino`  utiliza un sensor de ultrasonidos para medir la distancia a un objeto, mostrando el valor en cm en un display de 7 segmentos y controlando LEDs indicadores en función de la distancia medida.

`Ejercicio6.ino` mide la distancia con un sensor de ultrasonido, muestra la distancia en el monitor serial, enciende LEDs según la distancia y guarda la distancia medida en una tarjeta SD conectada en un archivo llamado "distances.txt".

`Ejercicio7.ino` controla un motor paso a paso usando potenciómetros para la posición y velocidad. Un sensor de ultrasonidos evita obstáculos. El motor se mueve a la posición deseada si no hay obstáculos, deteniéndose si los detecta.
