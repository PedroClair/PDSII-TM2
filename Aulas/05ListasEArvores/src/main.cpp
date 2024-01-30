#include "List.hpp"

int main() {
    Node a;
    Node b;

    a.data = 99;
    a.next = &b;

    b.data = 123;

    cout << a.data << endl;
    cout << a.next->data << endl;
}
