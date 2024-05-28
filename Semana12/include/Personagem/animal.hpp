#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
	public:
		virtual void fale() {
			std::cout << "Fale Padrao" << std::endl;
		}
    Animal(){}
};

#endif //ANIMAL_H