#include "../include/Reproductor.hpp"

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

void Reproductor::togglePlayPause() {
    if (!this->hayCancionActual) {
        return;
    }
    if (this->estadoReproduccion == "reproduciendo") {
        this->estadoReproduccion = "en pausa";
    } else if (this->estadoReproduccion == "en pausa") {
        this->estadoReproduccion = "reproduciendo";
    }
}

void Reproductor::siguiente() {
    if (!this->hayCancionActual && this->listaReproduccionActual.isEmpty()) {
        return;
    }
    if (this->modoRepeticion == 1 && this->hayCancionActual) {
        this->estadoReproduccion = "reproduciendo";
        return;
    }

    if (this->listaReproduccionActual.isEmpty()) {
        return;
    }

    if (this->hayCancionActual) {
        this->historial.insertFirst(this->cancionActual);
    }

    this->cancionActual = this->listaReproduccionActual.getFirst();
    this->listaReproduccionActual.removeFirst();
    this->hayCancionActual = true;
    this->estadoReproduccion = "reproduciendo";
}

void Reproductor::anterior() {
    if (this->historial.isEmpty()) {
        return;
    }
    if (this->hayCancionActual){
        this->listaReproduccionActual.insertFirst(this->cancionActual);
    }

    this->cancionActual = this->historial.getFirst();
    this->historial.removeFirst();
    this->hayCancionActual = true;
    this->estadoReproduccion = "reproduciendo";
}

void Reproductor::cambiarModoAleatorio() {
    this->modoAleatorio = !this->modoAleatorio;
}

void Reproductor::cambiarModoRepeticion() {
    this->modoRepeticion++;

    if (this->modoRepeticion > 2) {
        this->modoRepeticion = 0;
    }
}