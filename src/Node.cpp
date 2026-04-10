#include "../include/Node.hpp"
using namespace std;

Node::Node(Cancion dato) {
    this->dato = dato;
    this->next = nullptr;
}

Cancion Node::getDato() {
    return this->dato;
}
Node* Node::getNext() {
    return this->next;
}
void Node::setDato(Cancion dato) {
    this->dato = dato;
}
void Node::setNext(Node* next) {
    this->next = next;
}

Node::~Node() {
}

