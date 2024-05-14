#include <iostream>
#include <string>

// Include.HPP ( O QUE É - USUÁRIO )
//PERSONA
class Persona{
  private:
    std::string mensagem;
  protected:
    std::string getMensagem();
    void setMensagem(std::string);
  public:
    Persona();
    Persona(std::string);
    void cumprimento();
    ~Persona();
};

//Execução principal
int main () {
  Persona oi("Baum? Ou baum dimais?");
  oi.cumprimento();
  return 0;
}

//Implementação do código 
//Persona
Persona::Persona(){
  this->mensagem = "";
}

Persona::Persona(std::string msg){
  this->mensagem = msg;
}

std::string Persona::getMensagem(){
  return this->mensagem;
}

void Persona::setMensagem(std::string newMsg){
  this->mensagem = newMsg;
}

void Persona::cumprimento(){
  std::cout << this->mensagem << std::endl; 
}

Persona::~Persona(){}
