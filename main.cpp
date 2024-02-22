#include "testObject.hpp"

int main() {
    std::cout << "Antes!" << std::endl;
    int i = 0;
    while (i < 5){
        TestObject o(i);
        i++;
    }
    std::cout << "Depois!" << std::endl;
    return 0;
}