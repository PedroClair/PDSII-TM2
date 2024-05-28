#ifndef ALUNO_H
#define ALUNO_H

#include "pessoa.hpp"
#include "curso.hpp"

class Aluno : public Pessoa {
 
  private:
    int _matricula;
    Curso* _curso; // Tem a composição curso por referenciamento
 
  public:
    Aluno(std::string _nome, unsigned cpf, int matricula, Curso curso);
    void cumprimenta() override;
 
};


#endif
