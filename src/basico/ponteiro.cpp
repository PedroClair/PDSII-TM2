#include "ponteiro.hpp"

void function01(int &i) {
    int j = 10;
    j++;
    //i = &j; !OK  Error a value of type "int *" cannot be assigned to an entity of type "int" C/C++(513)
}

void function02(int *i) {
    int j = 10;
    i = &j;
}

void chamaPointerEReferencia(){
    int a = 0;
    cout << "Antes: " << a << endl;
    addOneValue(a); 
    addOnePointer(&a);
    cout << "Depois: " << a << endl;
}

void addOneValue(int &x) {
    x = x + 1;
}

void addOnePointer(int *x) {
    *x = (*x) + 1;
}

void addOneStaticValue(int x) {
    x = x + 1;
}

void chamaAddOneStaticValue() {
    int a = 0;
    cout << "Antes: " << a << endl;
    addOneStaticValue(a);
    cout << "Depois: " << a << endl;
}

void ponteiroBoaPratica() {
    int *ptr_a = nullptr;
    ptr_a = new int;

    if (ptr_a == nullptr) {
        cout << "Memoria insuficiente!" << endl;
        exit(1);
    }
    
    cout << "Endereco de ptr_a: " << ptr_a << endl;
    *ptr_a = 90;
    cout << "Conteudo de ptr_a: " << *ptr_a << endl;
    delete ptr_a;
}

void ponteiroParaStruct(){
    struct data {int dia; int mes; int ano;};
    struct data d1;
    struct data *ptr = &d1;

    (*ptr).dia = 8;
    (*ptr).mes = 3;
    (*ptr).ano = 2012;
    ptr->dia = 8;
    ptr->mes = 3;
    ptr->ano = 2012;
}

void ponteiroParaVoid(){
    int i = 10;
    int *int_ptr;
    void *void_ptr;
    double *double_ptr{nullptr};
    int_ptr = &i;
    void_ptr = &int_ptr; // OK
    //double_ptr = int_ptr; // Error: a value of type "int *" cannot be assigned to an entity of type "double *" C/C++(513)
    //double_ptr = void_ptr; // Error: a value of type "void *" cannot be assigned to an entity of type "double *"C/C++(513)
    void_ptr = double_ptr; // OK
    void_ptr = &i;
    i = sizeof(void_ptr);
}

void alocacaoDeVetor(){
    int *p = new int[10];
    p[0] = 99;
    delete[] p;
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