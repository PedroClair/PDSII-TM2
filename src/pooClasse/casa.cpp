#include "casa.hpp"

void Casa::testaInicio(){
    Casa c1;  
    c1.numero = 77;
    c1.cor = "Verde";
    Casa c2;
    c2.numero = 55;
    c2.cor = "Vermelha";
    Casa c3;
    c3.numero = 11;
    c3.cor = "amarelo";
    std::cout << "Casa 1, N:" << c1.numero << ", cor: " << c1.cor << std::endl;
    std::cout << "Casa 2, N:" << c2.numero << ", cor: " << c2.cor << std::endl;
    std::cout << "Casa 2, N:" << c3.numero << ", cor: " << c3.cor << std::endl;
}