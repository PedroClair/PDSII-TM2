#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main () {
    ifstream in(".doc/entrada.txt", fstream::in);
    ofstream out(".doc/saida.txt", fstream::out);
    string line;
    while (getline(in, line)){
        cout << "*" << line << "*" << endl;
        out << "[" << line << "]" << endl;
    }
    return 0;
}




/*
int main() {
	int x;

	do {
		cin >> x;
		cout << "[" << x << "]" << endl;
	} while (x!=0);

	return 0;
}


int main() {
  string nome;
  int idade;
  cout << "Digite o seu nome: ";
  cin >> nome;
  cout << "Digite sua idade: ";
  cin >> idade;
  cout << "Ola " << nome;
  cout << " voce tem " << idade; 
  cout << " anos." << endl;
  return 0;
}
*/

