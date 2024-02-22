#include <iostream>
#include "intro.hpp"

void lista1Cap1 (){
    const float precoDeHorasTrabalhadas = 16.78, taxaHoraExtra = 1.5, horasSemanaisPadrao = 40; 
    const float descontoPrevidencia = 0.06, impostoDeRenda = 0.14, impostosEstatuais = 0.05, seguroSaude = 35;

    int horasTrabalhadas, numDependentes;
    std::cout << "Forneca as horas trabalhadas e o numero de dependentes." << std::endl;
    std::cin >> horasTrabalhadas >> numDependentes;

    float valorBruto;
    if (horasTrabalhadas <= horasSemanaisPadrao){
        valorBruto = horasTrabalhadas*precoDeHorasTrabalhadas;
    } else {
        valorBruto = horasSemanaisPadrao*precoDeHorasTrabalhadas + 
        (horasTrabalhadas - horasSemanaisPadrao)*precoDeHorasTrabalhadas*taxaHoraExtra;
    }

    if (numDependentes > 2)
        valorBruto = valorBruto - seguroSaude;

    // Pagamento bruto
    std::cout << "Valor bruto: " << valorBruto << std::endl;
    
    // Valor dos impostos
    std::cout << "Desconto da previdencia: " << valorBruto*descontoPrevidencia << std::endl;
    std::cout << "Imposto de renda: " << valorBruto*impostoDeRenda << std::endl;
    std::cout << "Imposto estatual: " << valorBruto*impostosEstatuais << std::endl;
}