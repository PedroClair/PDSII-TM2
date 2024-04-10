#include "ola.hpp"
#include "circunferencia.hpp"
#include "aluno.hpp"
#include <iostream>

//Execução principal
int main () {
  bool realidadeVirtual = true;
  while(realidadeVirtual){
    std::cout << "Bem vindo a realidade virtual" << std::endl;
    std::cout << "O que voce deseja?" << std::endl;
    std::cout << "1 - Criar persona" << std::endl;
    std::cout << "2 - Calcular distancia ate a proxima missal" << std::endl;
    std::cout << "3 - Cumprimentar o colega" << std::endl;
    std::cout << "0 - Sair da realidade virtual" << std::endl;

    int escolha;
    cin >> escolha;

    switch (escolha){
      case 1:
        criaPersona(); //Historia 03 
        break;
      case 2:
        calculaLocal(); //Historia 02
        break;
      case 3:
        cumprimento(); //Historia 01
        break;
      case 0:
        realidadeVirtual = false;
        break;
      default:
        std::cout << "Opcao invalida" << std::endl;
        break;
    }
  }
  return 0;
}