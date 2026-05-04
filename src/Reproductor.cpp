#include "../include/Reproductor.hpp"
#include <iostream>
#include <cstdlib>
#include "../include/FileManager.hpp"

using namespace std;
//mecanismo para limpiar para 1 decim mass
void Reproductor::limpiarConsola() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Reproductor::run() {
}

string Reproductor::leerLinea() {
    string s;
    getline(cin, s);
    return s;
}

Reproductor::Reproductor() {
    this->hayCancionActual = false;
    this->estadoReproduccion = "detenido";
    this->modoAleatorio = false;
    this->modoRepeticion = 0;
}

bool Reproductor::tieneCancionActual() {
    return this->hayCancionActual;
}

string Reproductor::getEstadoReproduccion() {
    return this->estadoReproduccion;
}

bool Reproductor::getModoAleatorio() {
    return this->modoAleatorio;
}

int Reproductor::getModoRepeticion() {
    return this->modoRepeticion;
}

Cancion Reproductor::getCancionActual() {
    return this->cancionActual;
}

int Reproductor::getCantidadCancionesRegistradas() {
    return this->cancionesRegistradas.getSize();
}

int Reproductor::getCantidadCancionesEnListaActual() {
    return this->listaReproduccionActual.getSize();
}

Cancion Reproductor::getCancionRegistrada(int index) {
    return this->cancionesRegistradas.get(index);
}

Cancion Reproductor::getCancionEnListaActual(int index) {
    return this->listaReproduccionActual.get(index);
}

void Reproductor::agregarCancionAlRegistro(Cancion cancion) {
    this->cancionesRegistradas.insertLast(cancion);
}

void Reproductor::eliminarCancionDelRegistro(int index) {
    if (index < 0 || index >= this->cancionesRegistradas.getSize()) {
        return;
    }

    this->cancionesRegistradas.remove(index);
}

void Reproductor::reproducirCancionDelRegristro(int index) {
    if (index < 0 || index >= this->cancionesRegistradas.getSize()) {
        return;
    }
    if (this->hayCancionActual) {
        this->historial.insertFirst(this->cancionActual);
    }
    this->cancionActual = this->cancionesRegistradas.get(index);
    this->hayCancionActual = true;
    this->estadoReproduccion = "reproduciendo";
}

void Reproductor::agregarCancionAListaActual(int index) {
    if (index < 0 || index >= this->cancionesRegistradas.getSize()) {
        return;
    }
    this->listaReproduccionActual.insertLast(this->cancionesRegistradas.get(index));
}

void Reproductor::anterior() {
    if (this->cancionesRegistradas.isEmpty()) return;

    if (this->modoRepeticion == 1 && this->hayCancionActual) {
        this->estadoReproduccion = "reproduciendo";
        return;
    }

    if (this->historial.isEmpty()) return;

    if (this->hayCancionActual) {
        this->listaReproduccionActual.insertFirst(this->cancionActual);
    }

    this->cancionActual = this->historial.popFirst();
    this->hayCancionActual = true;
    this->estadoReproduccion = "reproduciendo";
}

void Reproductor::siguiente() {
    if (this->cancionesRegistradas.isEmpty()) return;

    if (this->modoRepeticion == 1 && this->hayCancionActual) {
        this->estadoReproduccion = "reproduciendo";
        return;
    }

    if (this->listaReproduccionActual.isEmpty()) {
        generarListaAleatoriaDesdeRegistro();

        if (this->modoRepeticion == 2 && this->modoAleatorio) {
            mezclarListaActual();
        }
    }
    if (this->listaReproduccionActual.isEmpty()) return;

    if (this->hayCancionActual) {
        this->historial.insertFirst(this->cancionActual);
    }

    this->cancionActual = this->listaReproduccionActual.popFirst();
    this->hayCancionActual = true;
    this->estadoReproduccion = "reproduciendo";
}

void Reproductor::cambiarModoAleatorio() {
    if (this->cancionesRegistradas.isEmpty()) return;

    bool antes = this->modoAleatorio;
    this->modoAleatorio = !this->modoAleatorio;

    if (!antes && this->modoAleatorio) {
        mezclarListaActual();
    }
}

void Reproductor::cambiarModoRepeticion() {
    this->modoRepeticion++;

    if (this->modoRepeticion > 2) {
        this->modoRepeticion = 0;
    }
}
void Reproductor::generarListaAleatoriaDesdeRegistro() {
    this->listaReproduccionActual.clear();

    int n = this->cancionesRegistradas.getSize();
    if (n == 0) return;


    List temp;
    for (int i = 0; i < n; i++) {
        temp.insertLast(this->cancionesRegistradas.get(i));
    }

    if (this->hayCancionActual) {
    
        for (int i = 0; i < temp.getSize(); i++) {
            if (temp.get(i).getIdInterno() == this->cancionActual.getIdInterno()) {
                temp.remove(i);
                break;
            }
        }
    }

    while (!temp.isEmpty()) {
        int len = temp.getSize();
        int k = rand() % len; 
        Cancion picked = temp.popAt(k);
        this->listaReproduccionActual.insertLast(picked);
    }
}

void Reproductor::mezclarListaActual() {
    if (this->listaReproduccionActual.getSize() <= 1) return;

    List temp;
    while (!this->listaReproduccionActual.isEmpty()) {
        temp.insertLast(this->listaReproduccionActual.popFirst());
    }

    while (!temp.isEmpty()) {
        int len = temp.getSize();
        int k = rand() % len;
        this->listaReproduccionActual.insertLast(temp.popAt(k));
    }
}
void Reproductor::setHayCancionActual(bool v) {
    this->hayCancionActual = v;
}

void Reproductor::setEstadoReproduccion(const std::string& e) {
    this->estadoReproduccion = e;
}

void Reproductor::setModoAleatorio(bool v) {
    this->modoAleatorio = v;
}

void Reproductor::setModoRepeticion(int r) {
    this->modoRepeticion = r;
    if (this->modoRepeticion < 0) this->modoRepeticion = 0;
    if (this->modoRepeticion > 2) this->modoRepeticion = 2;
}

void Reproductor::setCancionActual(Cancion c) {
    this->cancionActual = c;
}

void Reproductor::clearListaActual() {
    this->listaReproduccionActual.clear();
}

void Reproductor::appendListaActual(Cancion c) {
    this->listaReproduccionActual.insertLast(c);
}

void Reproductor::clearRegistro() {
    this->cancionesRegistradas.clear();
}
void Reproductor::mostrarLineaActual() {
    if (!this->hayCancionActual) {
        cout << "Reproduccion Detenida\n";
        return;
    }

    string state = this->estadoReproduccion;
    if (state == "detenido") state = "Reproduccion Detenida";

    string flags = "";
    if (this->modoAleatorio) flags += "S";
    if (this->modoRepeticion == 1) {
        if (!flags.empty()) flags += "-";
        flags += "R1";
    } else if (this->modoRepeticion == 2) {
        if (!flags.empty()) flags += "-";
        flags += "RA";
    }

    if (!flags.empty())
        cout << state << " (" << flags << "): " << this->cancionActual.getNombreCancion() << "\n";
    else
        cout << state << ": " << this->cancionActual.getNombreCancion() << "\n";

    cout << "Artista: " << this->cancionActual.getNombreArtista() << "\n";
    cout << "Album: " << this->cancionActual.getNombreAlbum() << " [" << this->cancionActual.getAnio() << "]"<< endl;
}

void Reproductor::mostrarPantallaPrincipal() {
    mostrarLineaActual();
    cout << "Opciones:\n";
    cout << "W - Reproducir/Pausar\n";
    if (this->historial.getSize() > 0) cout << "Q - Pista Anterior\n";
    cout << "E - Pista Siguiente\n";
    cout << "S - Activar/Desactivar modo aleatorio\n";
    cout << "R - Repeticion (Desactivado/Repetir una/Repetir todas)\n";
    cout << "A - Ver lista de reproduccion actual\n";
    cout << "L - Listado de canciones\n";
    cout << "X - Salir\n";
    cout << "Ingrese Opcion: ";
}
void Reproductor::togglePlayPause() {
    if (this->cancionesRegistradas.isEmpty()) return;

    if (!this->hayCancionActual) {
    
        if (this->listaReproduccionActual.isEmpty()) {
            generarListaAleatoriaDesdeRegistro();
        }
        if (!this->listaReproduccionActual.isEmpty()) {
            this->cancionActual = this->listaReproduccionActual.popFirst();
            this->hayCancionActual = true;
            this->estadoReproduccion = "reproduciendo";
        }
        return;
    }

    if (this->estadoReproduccion == "reproduciendo") {
        this->estadoReproduccion = "en pausa";
    } else if (this->estadoReproduccion == "en pausa") {
        this->estadoReproduccion = "reproduciendo";
    } else {
        
        this->estadoReproduccion = "reproduciendo";
    }

}
void Reproductor::menuListaActual() {
    if (this->cancionesRegistradas.isEmpty()) return;

    while (true) {
        limpiarConsola();

        
        if (this->hayCancionActual) {
            cout << "Actual: " << this->cancionActual.getNombreCancion()
                 << " - " << this->cancionActual.getNombreArtista() << "\n";
        } else {
            cout << "Actual: (sin pista)\n";
        }

        cout << "Lista de reproduccion actual:\n";

        if (this->listaReproduccionActual.isEmpty()) {
            cout << "Vacia\n";
            cout << "Opciones:\n";
            cout << "V - Volver al menu principal\n";
            cout << "Ingrese Opcion: ";
            string op = leerLinea();
            if (!op.empty() && (op[0] == 'V' || op[0] == 'v')) return;
            continue;
        }

        // Mostrar pendientes (1..n)
        for (int i = 0; i < this->listaReproduccionActual.getSize(); i++) {
            Cancion c = this->listaReproduccionActual.get(i);
            cout << (i + 1) << ". " << c.getNombreCancion() << " - " << c.getNombreArtista() << "\n";
        }

        cout << "Opciones:\n";
        cout << "S<num> - Saltar a la cancion seleccionada\n";
        cout << "V - Volver al menu principal\n";
        cout << "Ingrese Opcion: ";

        string op = leerLinea();
        if (op.empty()) continue;

        if (op[0] == 'V' || op[0] == 'v') return;

        if (op[0] == 'S' || op[0] == 's') {
            
            int pos = 0;
            for (size_t i = 1; i < op.size(); i++) {
                if (op[i] < '0' || op[i] > '9') { pos = 0; break; }
                pos = pos * 10 + (op[i] - '0');
            }
            if (pos <= 0 || pos > this->listaReproduccionActual.getSize()) continue;

        
            if (this->hayCancionActual) {
                this->historial.insertFirst(this->cancionActual);
            }

        
            for (int i = 1; i < pos; i++) {
                this->listaReproduccionActual.popFirst();
            }

    
            this->cancionActual = this->listaReproduccionActual.popFirst();
            this->hayCancionActual = true;
            this->estadoReproduccion = "reproduciendo";

            return; 
        }
    }
}