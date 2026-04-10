#include <iostream>
#include "../include/Cancion.hpp"
using namespace std;

int main() {
    Cancion cancion1(1, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 354, "/music/queen/bohemian_rhapsody.mp3");
    cout << "ID Interno: " << cancion1.getIdInterno() << endl;
    cout << "Nombre de la Canción: " << cancion1.getNombreCancion() << endl;
    cout << "Nombre del Artista: " << cancion1.getNombreArtista() << endl;
    cout << "Nombre del Álbum: " << cancion1.getNombreAlbum() << endl;
    cout << "Año: " << cancion1.getAnio() << endl;
    cout << "Duración en Segundos: " << cancion1.getDuracionSegundos() << endl;
    cout << "Ubicación del Archivo: " << cancion1.getUbicacionArchivo() << endl;

    return 0;
}