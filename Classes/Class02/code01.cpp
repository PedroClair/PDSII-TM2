#include <iostream>
#include <fstream>
#include <string>

bool badIf (std::ifstream &arq, std::string arq_cam);
void exampleFile(std::ifstream &arq, std::string arq_cam);

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
                //std::cout << linha.find("importe") << std::endl;
                if (linha.find("importante") != std::string::npos){
                    //std::cout << arq_cam << std::endl;
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

