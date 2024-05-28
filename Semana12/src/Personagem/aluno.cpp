#include "aluno.hpp"

//Aluno::Aluno(std::string nome, int matricula, Curso *curso) : Persona(nome), _matricula(matricula), _curso(curso) { }
Aluno::Aluno(std::string nome, unsigned cpf, int matricula, Curso curso) : Pessoa(nome, cpf), _matricula(matricula), _curso(&curso) {}

void Aluno::cumprimenta(){
    std::cout << "Sou aprendiz lalaia laia!" << std::endl;
}