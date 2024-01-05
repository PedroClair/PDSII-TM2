#include <iostream>

using namespace std;

int main () {
    int *p = new int[5];

    for (int i=0; i<5; i++)
        p[i] = i;

    for (int i=0; i<5; i++)
        cout << p[i] << endl;

    delete p;

    return 0;
}








/*void manipulaArquivo (){
    ifstream in("entrada.txt", fstream::in);
    ofstream out("saida.txt", fstream::out);
    string line;
    while (getline(in, line)){
        cout << "*" << line << "*" << endl;
        out << "[" << line << "]" << endl;
    }

}*/