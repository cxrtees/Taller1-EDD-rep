#include <iostream>
#include "../include/Cancion.hpp"
#include "../include/Node.hpp"
#include "../include/List.hpp"
using namespace std;

int main() {
    Cancion c1(1, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 354, "/music/queen/bohemian_rhapsody.mp3");
    Cancion c2(2, "Imagine", "John Lennon", "Imagine", 1971, 183, "/music/john_lennon/imagine.mp3");
    Cancion c3(3, "Ghost Rule", "DECO*27", "Album", 2016, 200, "C:/musica/ghost_rule.mp3"); 
    
    List lista;

    cout << "Lista vacia? " << lista.isEmpty() << endl;

    lista.insertFirst(c1);
    lista.insertLast(c2);
    lista.insertLast(c3);

    cout << "Lista vacia? " << lista.isEmpty() << endl;
    cout << "Primera: " << lista.getFirst().getNombreCancion() << endl;
    cout << "Ultima: " << lista.getLast().getNombreCancion() << endl;

    lista.clear();

    cout << "Lista vacia despues de clear? " << lista.isEmpty() << endl;


    return 0;
}