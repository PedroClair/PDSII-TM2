
#include "historia1.hpp"
#include "historia2.hpp"
#include "historia3.hpp"
#include "historia4.hpp"
#include "historia5.hpp"
#include <iostream>

int main () {
    bool historia_desejada = true;
  while(historia_desejada){
    std::cout << "Escolha a historia de usuario:" << std::endl;
    std::cout << "1 - Historia 01" << std::endl;
    std::cout << "2 - Historia 02" << std::endl;
    std::cout << "3 - Historia 03" << std::endl;
    std::cout << "4 - Historia 04" << std::endl;
    std::cout << "5 - Historia 05" << std::endl;

    int escolha;
    std::cin >> escolha;

    switch (escolha){
      case 1:
        catalogo(); //Historia 01 
        break;
      case 2:
        grafico(); //Historia 02
        break;
      case 3:
        classes_ativos(); //Historia 03
        break;
      case 4:
        alertas(); //Historia 04
        break;
      case 5:
        analise(); //Historia 05
        break;
      case 0:
        historia_desejada = false;
        break;
      default:
        std::cout << "Opcao invalida" << std::endl;
        break;
    }
  }
  return 0;
}