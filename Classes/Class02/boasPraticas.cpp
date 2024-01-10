#include "boasPraticas.hpp"

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

void exampleFile(std::ifstream &inputFile, std::string arq_cam){
    std::cout << arq_cam << std::endl;
    // Check if the file is successfully opened
    if (!inputFile.is_open()){
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    // Read and print each line from the file
    std::string line;
    while (std::getline(inputFile, line)){
        std::cout << line << std::endl;
        // using the find() function, checking if the given substring is present in the main string or not
        bool isFound = line.find("importante") != std::string::npos;
        std::cout << isFound << std::endl;
    }
}

bool badIf (std::ifstream &arq, std::string arq_cam){
    std::string linha;
    if (arq_cam != ""){
        if (arq.is_open()) {
            if (std::getline(arq, linha)){
                if (linha.find("importante")){
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return false;
}

bool improveIf(std::ifstream &arq, std::string arq_cam){
    std::string linha;
    if (arq_cam != "")
        return false;

    if (!arq.is_open())
        return false;

    bool encontrou = false;
    if (getline(arq, linha)){
        if (linha.find("importante") != std::string::npos){
            return encontrou;
        }
    }
    return encontrou;
}

