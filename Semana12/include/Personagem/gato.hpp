#ifndef GATO_H
#define GATO_H

#include "animal.hpp"

class Gato :public Animal {
	public:
		void fale() {
			std::cout << "Miau!";
		}
};

#endif //GATO_H