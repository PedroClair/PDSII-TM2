#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
    
    float calcularRSG() {
        // Fazer a conta necessaria
        return 0;
    }
};

int main() {
    Aluno aluno;
    aluno.nome = "Jose da Silva";
    aluno.matricula = 201812345;
    cout << aluno.nome << endl;
    return 0;
}