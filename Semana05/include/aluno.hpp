#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
   
    float calcularRSG();
};

#endif
