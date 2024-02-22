#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <iostream>

class TestObject {
        int atributo;
    public:
        TestObject (int valor);
        ~TestObject ();
        void testaDestrutores();
};

#endif //TESTOBJECT_H
