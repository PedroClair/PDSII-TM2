#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>

using namespace std;

class Aluno {
    public:
        string nome;
        int matricula;
    
        float calcularRSG();
};

void criaPersona();

#endif
