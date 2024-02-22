#include <iostream>

class TestObject {
    int atributo;

    public:
    TestObject (int valor) : atributo(valor) {}
    ~TestObject () { std::cout << "~TestObject " << atributo << std::endl; }
};


int main() {
   TestObject o1(1);
   TestObject* o2 = new TestObject(2);

   delete (o2);
   return 0;
}