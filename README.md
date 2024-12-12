# Ping Pong Game

## Descripción
Este proyecto es una implementación del clásico juego de Ping Pong utilizando **C++** y la biblioteca **SFML**. Es un juego para dos jugadores en el que cada jugador controla una raqueta para golpear la pelota. El objetivo es evitar que la pelota pase más allá de tu raqueta mientras intentas anotar puntos contra tu oponente.

### Características
- Juego en tiempo real para dos jugadores.
- Incremento progresivo de la velocidad de la pelota.
- Interfaz gráfica sencilla y funcional.
- Detección de colisiones precisa.
- Mensajes de victoria al alcanzar 5 puntos.

---

## Requisitos del sistema

### Software
- Compilador **MinGW** (Windows).
- Biblioteca **SFML** (Simple and Fast Multimedia Library).

### Instalación de SFMLPing Pong Game
Descripción
Este proyecto es una implementación del clásico juego de Ping Pong utilizando C++ y la biblioteca SFML. Es un juego para dos jugadores en el que cada jugador controla una raqueta para golpear la pelota. El objetivo es evitar que la pelota pase más allá de tu raqueta mientras intentas anotar puntos contra tu oponente.

Características
Juego en tiempo real para dos jugadores.
Incremento progresivo de la velocidad de la pelota.
Interfaz gráfica sencilla y funcional.
Detección de colisiones precisa.
Mensajes de victoria visuales con imágenes de los jugadores.
Música de fondo y efectos de sonido para una mejor experiencia.
Mensajes de victoria al alcanzar 5 puntos.
Requisitos del sistema
Software
Compilador MinGW (Windows).
Biblioteca SFML (Simple and Fast Multimedia Library).
Instalación de SFML
Descarga SFML desde su sitio oficial.
Sigue las instrucciones de instalación para configurarlo con MinGW.
Estructura del Proyecto
makefile
Copiar código
Proyecto/
├── bin/         # Archivos compilados
├── docs/        # Documentación
├── data/        # Recursos como fuentes e imágenes
├── include/     # Archivos .hpp
│   ├── Ball.hpp
│   ├── Paddle.hpp
│   └── Score.hpp
├── src/         # Archivos .cpp
│   ├── main.cpp
│   ├── Ball.cpp
│   ├── Paddle.cpp
│   └── Score.cpp
└── Makefile     # Archivo para compilar el proyecto
Compilación y Ejecución
Usando el Makefile
Abre una terminal en la carpeta del proyecto.
Ejecuta:
bash
Copiar código
make rungame
Esto generará el archivo ejecutable en la carpeta bin.
Ejecuta el juego con:
bash
Copiar código
./bin/pingpong
Limpieza
Para limpiar los archivos generados:

bash
Copiar código
make clean
Controles
Jugador 1: Usa las teclas W (arriba) y S (abajo).
Jugador 2: Usa las flechas del teclado ↑ (arriba) y ↓ (abajo).
Capturas de Pantalla
Pantalla de Juego


Mensaje de Victoria


Diagrama de Clases


Mejoras Futuras
Agregar soporte para un jugador contra IA.
Efectos de sonido y música de fondo.
Menú principal para iniciar o pausar el juego.
Ajuste de dificultad dinámico.
Mejoras en la interfaz visual, como animaciones de victoria más avanzadas.
Autor
Proyecto desarrollado por Angel Jaramillo.
1. Descarga SFML desde su [sitio oficial](https://www.sfml-dev.org/).
2. Sigue las instrucciones de instalación para configurarlo con MinGW.

---

## Estructura del Proyecto
```
Proyecto/
├── include/
│   ├── Ball.hpp
│   ├── Paddle.hpp
│   ├── Score.hpp
│   ├── ImageManager.hpp
│   └── SoundManager.hpp
├── src/
│   ├── Ball.cpp
│   ├── Paddle.cpp
│   ├── Score.cpp
│   ├── ImageManager.cpp
│   └── SoundManager.cpp

└── Makefile     # Archivo para compilar el proyecto
```

---

## Compilación y Ejecución

### Usando el Makefile
1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta:
   ```bash
   make rungame
   ```
   Esto generará el archivo ejecutable en la carpeta `bin`.
3. Ejecuta el juego con:
   ```bash
   ./bin/pingpong
   ```

### Limpieza
Para limpiar los archivos generados:
```bash
make clean
```

---

## Controles

- **Jugador 1**: Usa las teclas `W` (arriba) y `S` (abajo).
- **Jugador 2**: Usa las flechas del teclado `↑` (arriba) y `↓` (abajo).

---


## Mejoras Futuras
- Agregar soporte para un jugador contra IA..
- Menú principal para iniciar o pausar el juego.
- Ajuste de dificultad dinámico.

---

## Autor
Proyecto desarrollado por Angel Jaramillo.

