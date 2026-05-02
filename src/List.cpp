#include "../include/List.hpp"

List::List() {
    this->start = nullptr;
    this->size = 0; 
}

bool List::isEmpty() {
    return this->start == nullptr;
}

int List::getSize() {
    return this->size;
}

void List::insertFirst(Cancion dato) {
    Node* nuevo = new Node(dato);
    nuevo->setNext(this->start);
    this->start = nuevo;
    this->size++; // IMPORTANTE
}

void List::insertLast(Cancion dato) {
    if (this->start == nullptr) {
        this->start = new Node(dato);
        this->size++; // IMPORTANTE
        return;
    }

    Node* cursor = this->start;
    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }
    cursor->setNext(new Node(dato));
    this->size++; // IMPORTANTE
}

Cancion List::getFirst() {
    if (this->start == nullptr) {
        return Cancion();
    }
    return this->start->getDato();
}

Cancion List::getLast() {
    if (this->start == nullptr) {
        return Cancion();
    }
    Node* cursor = this->start;
    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }
    return cursor->getDato();
}

Cancion List::get(int index) {
    if (index < 0 || index >= this->size) {
        return Cancion();
    }
    Node* cursor = this->start;
    int posicion = 0;

    while (posicion < index) {
        cursor = cursor->getNext();
        posicion++;
    }
    return cursor->getDato();
}

void List::removeFirst() {
    if (this->start == nullptr) {
        return;
    }
    Node* temp = this->start;
    this->start = this->start->getNext();
    delete temp;
    this->size--;
}

void List::remove(int index) {
    if (index < 0 || index >= this->size) {
        return;
    }
    if (index == 0) {
        removeFirst();
        return;
    }

    Node* anterior = this->start;
    int posicion = 0;

    while (posicion < index - 1) {
        anterior = anterior->getNext();
        posicion++;
    }

    Node* temp = anterior->getNext();
    anterior->setNext(temp->getNext());
    delete temp;
    this->size--;
}

void List::clear() {
    while (this->start != nullptr) {
        Node* temp = this->start->getNext();
        delete this->start;
        this->start = temp;
    }
    this->size = 0; 
}

List::~List() {
    clear();
}