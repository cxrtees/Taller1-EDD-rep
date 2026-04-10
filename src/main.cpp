#include <iostream>
#include "../include/Cancion.hpp"
#include "../include/Node.hpp"
using namespace std;

int main() {
    Cancion cancion1(1, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 354, "/music/queen/bohemian_rhapsody.mp3");
    Cancion cancion2(2, "Imagine", "John Lennon", "Imagine", 1971, 183, "/music/john_lennon/imagine.mp3");

    Node* n1 = new Node(cancion1);
    Node* n2 = new Node(cancion2);

    n1->setNext(n2);

    cout << "Node 1: " << n1->getDato().getNombreCancion() << endl;
    cout << "Node 2: " << n1->getNext()->getDato().getNombreCancion() << endl;

    delete n1;
    delete n2;


    return 0;
}