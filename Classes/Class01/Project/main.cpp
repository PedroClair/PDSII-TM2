#include <iostream>

class Ponto {
  private:
    double _x;
    double _y;

  public:
    Ponto(double x, double y);
    void imprime() {
      std::cout << "(" << _x  << ", " << _y << ")" << std::endl;
    }
};

int main() {
  Ponto p = Ponto(2.0, 3.0);
  p.imprime();
  return 0;
}

Ponto::Ponto(double x, double y) {
  _x = x;
  _y = y;
}