#ifndef CACHORRO_H
#define CACHORRO_H

#include "animal.hpp"

class Cachorro : public Animal {
    public:
      void fale() {
        std::cout << "Au Au!";
      }
};

#endif //CACHORRO_H