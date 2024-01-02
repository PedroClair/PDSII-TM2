#include <iostream>
#include "./include/ponto.hpp"

int main (){
    Ponto origem = Ponto(2.0, 3.0);
    std::cout << "(" << origem.get_x() << ", " << origem.get_y() << ")" << std::endl;
    return 0;
}