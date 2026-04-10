#pragma once
#include "Cancion.hpp"
#include <string>
using namespace std;

class Node { 
private:
    Cancion dato;
    Node* next;
public:
    Node(Cancion dato);

    Cancion getDato();
    Node* getNext();

    void setDato(Cancion dato);
    void setNext(Node* next);

    ~Node();

};