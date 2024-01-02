#ifndef PDS2_PONTO_H
#define PDS2_PONTO_H

/*
 * Representa um ponto em duas dimensões. Não faz muito
 * mais do que isso :-)
 */
class Ponto {
  private:
    double _x;
    double _y;
  public:
    /*
     * @brief Constutor do nosso ponto.
     */
    Ponto(double, double);

    /*
     * @brief Retorna o valor na coordenada x
     */
    double get_x();

    /*
     * @brief Retorna o valor na coordenada y
     */
    double get_y();
};
#endif