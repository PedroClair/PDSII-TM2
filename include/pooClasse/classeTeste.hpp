#ifndef CLASSETESTE_H
#define CLASSETESTE_H
 
#include <iostream>
#include <string>
 
using namespace std;
 
class ClasseTeste {
 
  public:
    int     _atributo1;
    string  _atributo2;
 
    ClasseTeste();
    ClasseTeste(double, string);
 
    void metodoA();
    void metodoB(double);
 
};
 
#endif
