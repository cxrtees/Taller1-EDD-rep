#pragma once
#include <string>
using namespace std;

class Cancion { 
private:
    int idInterno;
    string nombreCancion;
    string nombreArtista;
    string nombreAlbum;
    int anio;
    int duracionSegundos;
    string ubicacionArchivo;

public:
    Cancion();
    Cancion(int idInterno, string nombreCancion, string nombreArtista, string nombreAlbum, int anio, int duracionSegundos, string ubicacionArchivo);
    int getIdInterno();
    string getNombreCancion();
    string getNombreArtista();
    string getNombreAlbum();
    int getAnio();
    int getDuracionSegundos();
    string getUbicacionArchivo();

    void setIdInterno(int idInterno);
    void setNombreCancion(string nombreCancion);
    void setNombreArtista(string nombreArtista);
    void setNombreAlbum(string nombreAlbum);
    void setAAnio(int anio);
    void setDuracionSegundos(int duracionSegundos);
    void setUbicacionArchivo(string ubicacionArchivo);

    ~Cancion();

};