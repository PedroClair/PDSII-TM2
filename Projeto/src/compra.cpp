#include <iostream>
#include "compra.hpp"

using namespace std;

int numeroDeParcelas(const float custoInicial, const float jurosAoAno, const float parcelaMensal){
    const float jurosAoMes = jurosAoAno/12;
    float dividaAtual = custoInicial;
    
    int count = 0;
    while (dividaAtual > 0) {
        dividaAtual = montanteMensal(dividaAtual, jurosAoMes, parcelaMensal);
        count = count + 1;
    };

    return count;
}

float montanteMensal(float dividaAtual, const float jurosAoMes, const float parcelaMensal){
    return dividaAtual + (dividaAtual * jurosAoMes) - parcelaMensal;
}