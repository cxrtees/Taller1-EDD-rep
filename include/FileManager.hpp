#pragma once
#include <string>
#include "Reproductor.hpp"

using namespace std;

class FileManager {
public:
    static void cargarCanciones(const string& nombreArchivo, Reproductor& reproductor);
    static void guardarCanciones(const string& nombreArchivo, Reproductor& reproductor);

};