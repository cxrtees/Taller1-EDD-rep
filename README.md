# Taller 1 - Estructuras de Datos

## Descripción
Este proyecto corresponde al **Taller 1** de la asignatura **Estructuras de Datos**.

La aplicación consiste en un **reproductor de música por consola**, desarrollado en **C++**, que trabaja con estructuras de datos implementadas manualmente con **listas enlazadas, nodos y punteros**, sin utilizar contenedores STL. El sistema carga canciones registradas desde un archivo `music_source.txt` y maneja el estado del reproductor mediante `status.cfg`. :contentReference[oaicite:1]{index=1}

## Integrantes
- Benjamín Ismael Cortés Acuña
- Catalina Isidora Rojas Macaya

## Requisitos
Para compilar y ejecutar este proyecto se requiere:

- `g++`
- `mingw32-make` en Windows

## Estructura del proyecto
```text
Taller1-EDD-rep
│   README.md
│   Makefile
│   music_source.txt
│   status.cfg
│
├── include
│   ├── Cancion.hpp
│   ├── Node.hpp
│   ├── List.hpp
│   ├── Reproductor.hpp
│   └── FileManager.hpp
│
└── src
    ├── main.cpp
    ├── Cancion.cpp
    ├── Node.cpp
    ├── List.cpp
    ├── Reproductor.cpp
    └── FileManager.cpp
