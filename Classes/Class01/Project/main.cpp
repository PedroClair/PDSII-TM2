#include <iostream>
#include <string>
#include <vector>

class Revisao {
  private:
    int inteiro;
    float flutuante;
    double duploFlutuante;
    char caracter;
    bool simOuNao;
  
  public:
    void exemplo01();
    void exemplo02();
    void exemplo03();
    void exemplo04();
    void exemplo05();
    void exemplos();
};

int main() {
  Revisao code = Revisao();
  code.exemplos();
  return 0;
}

void Revisao::exemplo01(){
  std::cout << "Codigo 01" << std::endl;
  #include <stdio.h>
  printf("Oi mundo C!\n\n");
}

void Revisao::exemplo02(){
  std::cout << "Codigo 02" << std::endl;
  using namespace std;
  cout << "Oi mundo C++!\n" << endl; 
}

void Revisao::exemplo03(){
  std::cout << "Codigo 03" << std::endl;
  std::string curto = "Hello World";
  std::string longo = "Essa é uma string grande para o exemplo!";

  std::cout << curto << std::endl;
  std::cout << longo << std::endl;

  std::cout << longo.length() << std::endl;
  std::cout << std::endl; 
}

void Revisao::exemplo04(){
  std::cout << "Codigo 04" << std::endl;
  using namespace std; 
  string a;
  a = "123456";
  string b;
  b = "123456";
  bool igual = (a == b);
  cout << igual << endl;
  cout << a[0] << endl;
  cout << b[5] << endl;
  a[0] = '0';
  cout << a << endl;
  string c = a + b;
  cout << c << endl;
  cout << endl;
}

void Revisao::exemplo05(){
  std::cout << "Codigo 05" << std::endl; 
  using namespace std;
  string nome;
  int idade;
  cout << "Digite o seu nome: ";
  cin >> nome;
  cout << "Digite sua idade: ";
  cin >> idade;
  cout << "Ola " << nome << " voce tem " << idade << " anos." << endl;
}

void Revisao::exemplos(){
  Revisao r = Revisao();
  r.exemplo01();  r.exemplo02(); r.exemplo03(); r.exemplo04(); r.exemplo05();
}
