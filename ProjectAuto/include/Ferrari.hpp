#ifndef FERRARI_H
#define FERRARI_H

#include "Carro.hpp"

namespace Carro {
    class Ferrari : CarroAbstrado{
        public:
            void start();
            void drive();
            void stop();
    };
}

#endif