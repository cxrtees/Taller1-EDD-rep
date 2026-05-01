#pragma once
#include "Node.hpp"
#include "Cancion.hpp"

class List {
private:
    Node* start;
    int size;

public:
    List();

    bool isEmpty();
    int getSize();

    void insertFirst(Cancion dato);
    void insertLast(Cancion dato);

    Cancion getFirst();
    Cancion getLast();
    Cancion get(int index);

    void removeFirst();
    void remove(int index);

    void clear();

    ~List();
};