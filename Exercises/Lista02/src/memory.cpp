#include <iostream>
#include "memory.hpp"

using namespace std;

void questao1Declaracoes(){ 
// 1. Escreva, em c++, as declaraçoes simples de ponteiro a seguir:
    //(a) Declare uma variável atv1 como um ponteiro para char
    char a = 'a';
    char *atv1; 
    atv1 = &a;
    cout << "Atv1: " << *atv1 << endl;
    //(b) Declare uma variável atv2 como um ponteiro para ponteiro de char
    int **atv2; cout << "Atv2: " << &atv2 << endl;
    //(c) Declare uma variável atv3 como array de tamanho 100 de ponteiros para char
    char *atv3 [100]; cout << "Atv3: " << atv3 << endl;
    // (d) Declare uma variável atv4 como um ponteiro para um array de tamanho 100
    int *atv4[100]; cout << "Atv4: " << atv4 << endl;
    // (e) Declare uma variável atv5 como um ponteiro constante para um inteiro.
    int maior{ 100 };
    int menor{ 66 };
    const int* atv5{ &maior };
    cout << "Atv5: " << *atv5 << " \\ ";
    atv5 = &menor;
    cout << "Atv5: " << *atv5 << "\n";
    // (f) Declare uma variável atv6 como um ponteiro para um inteiro constante.
    int num2 = 10;
    int* const atv6 = &num2; 
    cout << "Atv6: " << atv6 << endl;
}

void questao2PonteiroParaConstantes(){ 
    //2. "Dê uma explicação sucinta sobre a diferenca entre um ponteiro constante e um ponteiro para um tipo constante."
    const int *ptr1; //O tipo é constante, o que significa que não pode ser modificado o valor da variável.
    int x1 = 10, y1 = 20;
    ptr1 = &x1; // OK, inicializando o ponteiro
    ptr1 = &y1; // OK, modifica o ponteiro para outro endereço
    cout << *ptr1 << endl;
    // *ptr1 = 30; // Erro, não pode modificar o valor apontado pelo ponteiro
    
    int num = 10; // Necessário para inicializar o ponteiro que aponta para um tipo constante.
    int *const ptr2 = &num; // O ponteiro aponta para um tipo constante, ou seja, não pode ser modificado para apontar para outro tipo após a inicialização.
    *ptr2 = 20; // OK, pode modificar o valor apontado pelo ponteiro
    //ptr2 = &y1; // Erro, não pode modificar o ponteiro para apontar para outro endereço
}