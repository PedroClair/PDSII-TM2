#ifndef CARRO_H
#define CARRO_H

namespace Carro {
    class CarroAbstrado{
        public:
            virtual void start() = 0;
            virtual void drive() = 0;
            virtual void stop() = 0;
    };
}

#endif