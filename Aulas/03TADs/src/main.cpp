#include <iostream>
#include "Circunferencia.hpp"

using namespace std;

int main() {
    Circunferencia* circ = new Circunferencia(0, 0, 10);
    cout << circ->calcularArea() << endl;
    delete circ;
    return 0;
}
