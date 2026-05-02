#pragma once 
#include "List.hpp"
#include "Cancion.hpp"
#include <string>

using namespace std;

class Reproductor {
private:
    List cancionesRegistradas;
    List listaReproduccionActual;
    List historial;

    Cancion cancionActual;
    bool hayCancionActual;

    string estadoReproduccion; // reproduciendo pausado detenido
    bool modoAleatorio;
    int modoRepeticion; // 0: sin repetición, 1: repetir canción, 2: repetir listaidk

public:
    Reproductor();

    bool tieneCancionActual();
    string getEstadoReproduccion();
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
}