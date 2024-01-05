#include <iostream>
#include <fstream>
#include <string>

struct DtaRcrd {
    time_t cridmahms;
    time_t cridmahms;
    int pszqint = 102;
};

struct cliente {
    time_t dataHoraCriacao;
    time_t dataHoraModificacao;
    int idRegistro =102;
};




void exampleFile(std::ifstream &arq, std::string arq_cam);
bool badIf (std::ifstream &arq, std::string arq_cam);
bool improveIf(std::ifstream &arq, std::string arq_cam);


int main () {
    // Open the file for reading
    std::ifstream inputFile("entrada.txt", std::fstream::in);
    std::string name = "codigo";
    std::cout << badIf(inputFile, name) << std::endl;

    //Close the file
    inputFile.close();
    return 0;
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

