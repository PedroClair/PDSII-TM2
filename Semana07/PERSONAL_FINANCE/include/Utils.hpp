#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

enum Foreground {
    f_black = 30,
    f_red,
    f_green,
    f_yellow,
    f_blue,
    f_magenta,
    f_cyan,
    f_white
};

enum Background {
    b_black = 40,
    b_red,
    b_green,
    b_yellow,
    b_blue,
    b_magenta,
    b_cyan,
    b_white
};

enum Efeitos {
    reset = 0,
    bold_bright = 1,
    underline = 4,
    inverse = 7,
    bold_bright_off = 21,
    underline_off = 24,
    inverse_off = 27
};

class Utils {
    public:
        static void printColor(int color1, int color2, std::string texto);

        static void printColor(int color, std::string texto);

        static void printColorNoLine(int color, std::string texto);

        static void printColorNoLine(int color1, int color2, std::string texto);

        static void limparConsole();

        static void selecionarData(std::string& data);
};

#endif