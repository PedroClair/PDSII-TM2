#include <iostream>

class Ponto {
  private:
    double coordenadaHorizontalX;
    double coordenadaVerticalY;

  public:
    Ponto(double, double);
    void imprime(); 
    Ponto get();
    void set(double, double);
    void feature();
};

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

Ponto::Ponto(double x, double y) {
  coordenadaHorizontalX = x;
  coordenadaVerticalY = y;
}

void Ponto::imprime(){
  std::cout << "(" << coordenadaHorizontalX << ", " << coordenadaVerticalY << ")" << std::endl;
}

Ponto Ponto::get(){
  Ponto original = Ponto(coordenadaHorizontalX, coordenadaVerticalY);
  return original;
}

void Ponto::set(double x, double y){
  coordenadaHorizontalX = x;
  coordenadaVerticalY = y;
}

void Ponto::feature(){
  Ponto origem = Ponto(2.0, 3.0);
  origem.imprime();
  Ponto original = origem.get();
  original.imprime();
  original.set(4.0, 5.0);
  original.imprime();
}

void Revisao::exemplo01(){
  std::cout << "Codigo 01" << std::endl; 
}

void Revisao::exemplo02(){
  std::cout << "Codigo 02" << std::endl; 
}

void Revisao::exemplo03(){
  std::cout << "Codigo 03" << std::endl; 
}

void Revisao::exemplo04(){
  std::cout << "Codigo 04" << std::endl; 
}

void Revisao::exemplo05(){
  std::cout << "Codigo 05" << std::endl; 
}

void Revisao::exemplos(){
  Revisao r = Revisao();
  r.exemplo01();  r.exemplo02(); r.exemplo03(); r.exemplo04(); r.exemplo05();
}
