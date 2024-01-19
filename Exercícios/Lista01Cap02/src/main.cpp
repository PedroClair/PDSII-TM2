#include <iostream>
#include "compra.hpp"

int main (){
    std::cout << "Quantidade de parcelas = " << numeroDeParcelas(1000.00, 0.18, 50) << std::endl;
    return 0;
}