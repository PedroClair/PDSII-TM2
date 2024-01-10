#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "boasPraticas.h"

int main() {
  Ponto origem = Ponto(0, 0);
  origem.feature();

  // Open the file for reading
  std::ifstream inputFile("entrada.txt", std::fstream::in);
  std::string name = "codigo";
  std::cout << badIf(inputFile, name) << std::endl;

    //Close the file
  inputFile.close();
  return 0;
}