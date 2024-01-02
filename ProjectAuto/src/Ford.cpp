#include <iostream>
//#include "Ferrari.hpp" 
#include "../include/Ford.hpp"

namespace Carro {
    void Carro::Ford::start(){
        std::cout << "Starting a Ford\n";
    }

    void Carro::Ford::drive(){
        std::cout << "Driving a Ford\n";
    }

    void Carro::Ford::stop(){
        std::cout << "Stopping a Ford\n";
    }
}