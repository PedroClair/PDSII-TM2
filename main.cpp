#include <iostream>

class TestObject {
    int atributo;
    public:
    TestObject (int valor) : atributo(valor) {}
    ~TestObject () { std::cout << "~TestObject " << atributo << std::endl; }
    void testaDestrutores(){
        TestObject o1(1);
        TestObject* o2 = new TestObject(2);
        delete (o2);
    }
};

int main() {
    std::cout << "Antes" << std::endl;
    int i = 0;
    while (i < 5){
        TestObject o(i);
        i++;
    }
    std::cout << "Depois" << std::endl;
    return 0;
}