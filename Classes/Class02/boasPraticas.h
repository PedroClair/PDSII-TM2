#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

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

struct DtaRcrd {
    time_t cridmahms;
    time_t moddmahms;
    int pszqint = 102;
};

struct cliente {
    time_t dataHoraCriacao;
    time_t dataHoraModificacao;
    int idRegistro =102;
};

std::list<std::vector<int>> pegarValores(std::list<std::vector<int>> lista1);
void exampleFile(std::ifstream &arq, std::string arq_cam);
bool badIf (std::ifstream &arq, std::string arq_cam);
bool improveIf(std::ifstream &arq, std::string arq_cam);