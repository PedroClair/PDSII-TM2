#ifndef PONTEIRO_H
#define PONTEIRO_H

#include <iostream>

using namespace std;

void exemplo3bom();
void exemplo3ruim();
void alocacaoDeVetor();
void ponteiroParaVoid();
void ponteiroParaStruct();
void ponteiroBoaPratica();
void chamaAddOneStaticValue();
void addOneStaticValue(int x);
void addOneValue(int &x); // não pode ser null
void addOnePointer(int *x); // pode ser null
void chamaPointerEReferencia();
void function01(int &i);
void function02(int *i);

#endif