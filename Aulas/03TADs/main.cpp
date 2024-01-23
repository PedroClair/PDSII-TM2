#include <iostream>
#include "Circunferencia.hpp"

using namespace std;

struct TriangRetangulo {
    float base, altura;
};

struct TriangRetangulo {
    float base, hipot, ang;
};

int main() {
    Circunferencia* circ = new Circunferencia(0, 0, 10);
    cout << circ->calcularArea() << endl;
    delete circ;
    return 0;
}
