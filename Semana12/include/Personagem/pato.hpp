#ifndef PATO_H
#define PATO_H

#include "animal.hpp"

class Pato : public Animal {
  public:
    void fale(){
      std::cout << "Qua Qua";
    }
};

#endif //PATO_H