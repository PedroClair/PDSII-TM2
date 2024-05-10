#include <iostream>
#include <string>

// Include.HPP ( O QUE É - USUÁRIO )
using namespace std;

class Pessoa {
  public:
    string nome;
    virtual void meuNome(){
      cout << "Nome da PESSOA" << endl;
    }
};

class Estudante : public Pessoa {
  public:
    int matricula;
    void meuNome() override {
        cout << "Nome da ESTUDANTE" << endl;
    }
};

class EstGrad : public Estudante {
  public:
    string curso;
};

class A {
  public:
    A() { cout << "A()" << endl;}
    ~A() { cout << "~A()" << endl;}
};

class B : public A {
  public:
    B() { cout << "B()" << endl;}
    ~B() { cout << "~B()" << endl;}
};

class C : public B {
  public:
    C() { cout << "C()" << endl;}
    ~C() { cout << "~C()" << endl;}
};

class A1 {
  int _a;
  public:
    A1(int a) : _a(a) {};
    void getAtributo() { cout << _a << endl; };
};
 
class B1 : public A1 {
  int _b;
  public:
    B1(int a, int b) : A1(a), _b(b) {};
};




//Métodos inclusos
void cumprimento();

//Execução principal
int main () {
  cumprimento();
  EstGrad *aluno = new EstGrad();
  aluno->nome = "Pedro";
  aluno->matricula = 2024123;
  aluno->curso = "Computation";

  cout << "Alocando B:" << endl;
  B b1;
 
  cout << "Alocando C:" << endl;
  C* c1 = new C();
 
  cout << "Deleting C:" << endl;
  delete c1;

  A1 objA(55);
 
  B1 objB(77, 99);
  objB.getAtributo();
 
  cout << "Quitting..." << endl;

  Pessoa p;
  p.meuNome();
 
  Estudante e;
  e.meuNome();
 
  Pessoa* p2 = new Estudante();
  p2->meuNome();
 
  //delete p2;

  return 0;
}

//Implementação do código
void cumprimento(){
  std::cout << "C tah baum?" << std::endl;
}