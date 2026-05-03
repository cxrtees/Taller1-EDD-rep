#pragma once
#include "List.hpp"
#include "Cancion.hpp"
#include <string>

class Reproductor {
private:
    List cancionesRegistradas;
    List listaReproduccionActual;
    List historial;

    Cancion cancionActual;
    bool hayCancionActual;

    std::string estadoReproduccion; // "reproduciendo", "en pausa", "detenido"
    bool modoAleatorio;
    int modoRepeticion; // 0: off, 1: repetir una, 2: repetir todas

public:
    Reproductor();

    bool tieneCancionActual();
    std::string getEstadoReproduccion();
    bool getModoAleatorio();
    int getModoRepeticion();

    Cancion getCancionActual();

    int getCantidadCancionesRegistradas();
    int getCantidadCancionesEnListaActual();

    Cancion getCancionRegistrada(int index);
    Cancion getCancionEnListaActual(int index);

    void agregarCancionAlRegistro(Cancion cancion);
    void eliminarCancionDelRegistro(int index);

    void reproducirCancionDelRegristro(int index);
    void agregarCancionAListaActual(int index);

    void togglePlayPause();
    void siguiente();
    void anterior();

    void cambiarModoAleatorio();
    void cambiarModoRepeticion();

    void generarListaAleatoriaDesdeRegistro();
    void mezclarListaActual();

      void setHayCancionActual(bool v);
    void setEstadoReproduccion(const std::string& e);
    void setModoAleatorio(bool v);
    void setModoRepeticion(int r);
    void setCancionActual(Cancion c);

    void clearListaActual();
    void appendListaActual(Cancion c);

    void clearRegistro();

};