#include <iostream>
#include <string>

// Include.HPP ( O QUE É - USUÁRIO )
class Ola{
  private:
    std::string mensagem;
  protected:
    std::string getMensagem();
    void setMensagem(std::string);
  public:
    Ola();
    Ola(std::string);
    void cumprimento();
    ~Ola();
};

//Execução principal
int main () {
  Ola oi("Baum? Ou baum dimais?");
  oi.cumprimento();
  return 0;
}

//Implementação do código
Ola::Ola(){
  this->mensagem = "";
}

Ola::Ola(std::string msg){
  this->mensagem = msg;
}

std::string Ola::getMensagem(){
  return this->mensagem;
}

void Ola::setMensagem(std::string newMsg){
  this->mensagem = newMsg;
}

void Ola::cumprimento(){
  std::cout << this->mensagem << std::endl; 
}

Ola::~Ola(){}
