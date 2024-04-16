#include "aluno.hpp"

float Aluno::calcularRSG() {
    cout << "O aluno nao tem RSG" << endl;
    return 0;
}

void criaPersona(){
  Aluno aluno;
  aluno.nome = "Jose da Silva";
  aluno.matricula = 201812345;
  cout << aluno.nome << endl;
}
