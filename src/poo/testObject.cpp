#include "testObject.hpp"

TestObject::TestObject (int valor) : atributo(valor) {}
TestObject::~TestObject () { std::cout << "~TestObject: " << atributo << std::endl; }
void TestObject::testaDestrutores(){
    TestObject o1(1);
    TestObject* o2 = new TestObject(2);
    delete (o2);
}