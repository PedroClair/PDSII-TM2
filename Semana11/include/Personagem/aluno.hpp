#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>
#include "persona.hpp"

using namespace std;

class Aluno : public Persona {
    private:
        int matricula;
    protected:
        float calcularRSG();
};

#endif
