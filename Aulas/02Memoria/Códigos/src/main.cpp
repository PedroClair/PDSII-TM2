#include <iostream>

using namespace std;

void exemplo3bom();
void exemplo3ruim();


int main() {
    exemplo3bom();
    exemplo3ruim();
    return 0;
}

void exemplo3bom(){
    int *a = nullptr;
    int b = 10;
    a = new int;
    *a = 20;
    delete a;
    a = &b;
    *a = 30;
    cout << "Bom => " << "*a: " << *a << " b: " << b << endl;
}

void exemplo3ruim(){
    int *a, b;
    b = 10;
    a = new int;
    *a = 20;
    a = &b;
    *a = 30;
    cout << "Ruim => " << "*a: " << *a << " b: " << b << endl;
}

void exemplo2 (){
    int *p1, *p2;
    p1 = new int;
    *p1 = 42;
    p2 = p1;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;
    *p2 = 53;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;
    p1 = new int;
    *p1 = 88;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;
}


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