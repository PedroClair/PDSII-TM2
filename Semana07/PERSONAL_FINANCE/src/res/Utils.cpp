#include "Utils.hpp"

void Utils::printColor(int color1, int color2, std::string texto) {
    std::cout << "\033["
              << color1 << ';'
              << color2 << 'm'
              << texto
              << "\033[0m"
              << std::endl;
}

void Utils::printColor(int color, std::string texto) {
    std::cout << "\033["
              << "1;"
              << color << 'm'
              << texto
              << "\033[0m"
              << std::endl;
}

void Utils::printColorNoLine(int color, std::string texto) {
    std::cout << "\033["
              << "1;"
              << color << 'm'
              << texto
              << "\033[0m";
}

void Utils::printColorNoLine(int color1, int color2, std::string texto) {
    std::cout << "\033["
              << color1 << ';'
              << color2 << 'm'
              << texto
              << "\033[0m";             
}


void Utils::limparConsole() {
    std::cout << u8"\033[2J\033[1;1H";
}

void Utils::selecionarData(std::string &data) {
    Utils::printColorNoLine(Efeitos::bold_bright, "DESEJA COLOCAR A DATA DE HOJE? [s/n]: ");
    char resposta;
    std::cin >> resposta;

    if (resposta == 's' || resposta == 'S') {
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%d/%m/%Y");
        data = oss.str();
        Utils::printColorNoLine(Efeitos::bold_bright, "A DATA DE HOJE É: ");
        std::cout << data << std::endl;
    }
    else {
        Utils::printColorNoLine(Efeitos::bold_bright, "DIGITE A DATA DESEJADA: ");
        std::cin >> data;
    }
}
