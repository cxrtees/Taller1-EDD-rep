#pragma once
#include "Node.hpp"
#include "Cancion.hpp"

class List {
    private:
        Node* start;
    public:
        List();

        bool isEmpty();

        void insertFirst(Cancion dato);
        void insertLast(Cancion dato);

        Cancion getFirst();
        Cancion getLast();

        void clear();

        ~List();
};