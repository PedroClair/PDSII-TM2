#include <iostream>

struct Rectangle {
    double length;
    double width;

    double calculatePerimeter(const Rectangle& rect);
    double calculateArea(const Rectangle& rect);
    void setLength(Rectangle& rect, double l);
    void setWidth(Rectangle& rect, double w);
    double getLength(const Rectangle& rect);
    double getWidth(const Rectangle& rect);
};

void mainQuestaoPonteiros();

int main() {
    // Exemplo de uso da estrutura Rectangle
    Rectangle rectangle = {5.0, 4.0};

    std::cout << "Perímetro do retângulo: " << rectangle.calculatePerimeter(rectangle) << std::endl;
    std::cout << "Área do retângulo: " << rectangle.calculateArea(rectangle) << std::endl;

    // Atualizar os atributos
    rectangle.setLength(rectangle, 7.0);
    rectangle.setWidth(rectangle, 3.0);

    std::cout << "Novo comprimento do retângulo: " << rectangle.getLength(rectangle) << std::endl;
    std::cout << "Nova largura do retângulo: " << rectangle.getWidth(rectangle) << std::endl;

    mainQuestaoPonteiros();

    return 0;
}

// Funções para calcular perímetro e área
double Rectangle::calculatePerimeter(const Rectangle& rect) {
    return 2 * (rect.length + rect.width);
}

double Rectangle::calculateArea(const Rectangle& rect) {
    return rect.length * rect.width;
}

// Funções para atualizar e ler os atributos length e width
void Rectangle::setLength(Rectangle& rect, double l) {
    if (l > 0.0 && l < 20.0)
        rect.length = l;
    else
        std::cerr << "Comprimento inválido!\n";
}

void Rectangle::setWidth(Rectangle& rect, double w) {
    if (w > 0.0 && w < 20.0)
        rect.width = w;
    else
        std::cerr << "Largura inválida!\n";
}

double Rectangle::getLength(const Rectangle& rect) {
    return rect.length;
}

double Rectangle::getWidth(const Rectangle& rect) {
    return rect.width;
}

void mainQuestaoPonteiros(){
  long value1 = 200000;
  long value2;

  long *longPtr; // Declaração (A) 
  longPtr = &value1; // inicialização (B) de longPtr com o endereço de value1
  std::cout << "Valor apontado por longPtr: " << *longPtr << std::endl; // Imprime o valor apontado por longPtr (C)
  value2 = *longPtr; // Atribui o valor apontado por longPtr à variável value2 (D)
  std::cout << "Valor de value2: " << value2 << std::endl; // Imprime o valor de value2 (E)
  std::cout << "Endereço de value1: " << &value1 << std::endl; // Imprime o endereço de value1 (F)
  std::cout << "Endereço armazenado em longPtr: " << longPtr << std::endl; // Imprime o endereço armazenado em longPtr (G)
}