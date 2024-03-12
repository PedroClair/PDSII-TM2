#include <iostream>

using namespace std;

//Métodos inclusos
void cumprimento();
void folhaDePagamento();

int main() {
    //cumprimento();
    folhaDePagamento();
    return 0;
}

//Implementação do código
void cumprimento(){
  cout << "C tah baum?!!!" << endl;
}

void folhaDePagamento() {
    float salarioHora = 16.78;
    float horasTrabalhadas, salarioBruto, salarioLiquido;
    int numDependentes;

    cout << "Digite o número de horas trabalhadas na semana: ";
    cin >> horasTrabalhadas;

    cout << "Digite o número de dependentes: ";
    cin >> numDependentes;

    salarioBruto = horasTrabalhadas * salarioHora;

    // Calcula hora extra (se houver)
    if (horasTrabalhadas > 40) {
        float horasExtras = horasTrabalhadas - 40;
        salarioBruto += horasExtras * salarioHora * 0.5;
    }

    // Adicional por dependente (se houver 3 ou mais)
    if (numDependentes >= 3) {
        salarioBruto += 35;
    }

    // Cálculo dos descontos
    float descontoPrevidencia = salarioBruto * 0.06;
    float descontoImpostoRenda = salarioBruto * 0.14;
    float descontoEstadual = salarioBruto * 0.05;
    float descontoSindicato = 10;

    salarioLiquido = salarioBruto - descontoPrevidencia - descontoImpostoRenda - descontoEstadual - descontoSindicato;

    // Exibir resultados
    cout << "\nSalário Bruto: R$ " << salarioBruto << endl;
    cout << "Desconto Previdência: R$ " << descontoPrevidencia << endl;
    cout << "Desconto Imposto de Renda: R$ " << descontoImpostoRenda << endl;
    cout << "Desconto Impostos Estaduais: R$ " << descontoEstadual << endl;
    cout << "Desconto Sindicato: R$ " << descontoSindicato << endl;
    cout << "Salário Líquido: R$ " << salarioLiquido << endl;
}