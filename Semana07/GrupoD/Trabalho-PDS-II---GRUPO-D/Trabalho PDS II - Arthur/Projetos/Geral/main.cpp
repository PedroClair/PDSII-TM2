#include "historias.hpp"
#include <iostream>

int main() {
    bool emAndamento = true;
    while (emAndamento) {
        

        std::cout << "\nEscolha uma historia (digite um numero de 1 a 12 ou 13 para encerrar o programa):\n"<< std::endl;

        int escolha;
        cin >> escolha;

        switch(escolha){
            case 1:
                historia1();
                break;
            case 2:
                historia2();
                break;
            case 3:
                historia3();
                break;
            case 4:
                historia4();
                break;
            case 5:
                historia5();
                break;
            case 6:
                historia6();
                break;
            case 7:
                historia7();
                break;
            case 8:
                historia8();
                break;
            case 9:
                historia9();
                break;
            case 10:
                historia10();
                break;
            case 11:
                historia11();
                break;
            case 12:
                historia12();
                break;
            case 13:
            emAndamento = 0;
            break;
            default:
                std::cout << "\nOpcao invalida! Por favor, escolha de 1 a 12 (13 caso deseje encerrar o programa).\n"<< std::endl;
                break;
        }
    }
    return 0;
}
