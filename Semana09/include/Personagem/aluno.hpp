#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>
#include "persona.hpp"

using namespace std;

class Aluno : public Persona {
    public:
        int matricula;
        float calcularRSG();
};

void criaPersona();

#endif
