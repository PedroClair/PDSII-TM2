#ifndef PONTO_H
#define PONTO_H

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

#endif