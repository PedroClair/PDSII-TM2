#include <iostream>

double multiplyByTwo(double input) {
    double twice = input * 2.0;
    return twice;
}

void chamaMultipyByTwo (){
    double salary = 12345.67;
    double myList[3] = {1.2, 2.3, 3.4};

    for (int i = 0; i < 3; i++)
        myList[i] = multiplyByTwo(myList[i]);

    std::cout << multiplyByTwo(salary) << std::endl;
}

int main() {
    int i = 10;
    int *ponteiro = &i;
    int **ppp = &ponteiro;
    return 0;
}
