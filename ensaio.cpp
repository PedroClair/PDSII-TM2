#include <iostream>

using namespace std;

//Métodos inclusos
void cumprimento();

//Execução principal
int main () {

  cumprimento();

  return 0;
}

//Implementação do código
void cumprimento(){
  cout << "C tah baum?" << endl;
}






















/*
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main () {
    ifstream in(".doc/entrada.txt", fstream::in);
    ofstream out(".doc/saida.txt", fstream::out);
    string line;
    while (getline(in, line)){
        cout << "*" << line << "*" << endl;
        out << "[" << line << "]" << endl;
    }
    return 0;
}

int main() {
	int x;

	do {
		cin >> x;
		cout << "[" << x << "]" << endl;
	} while (x!=0);

	return 0;
}

int main() {
  string nome;
  int idade;
  cout << "Digite o seu nome: ";
  cin >> nome;
  cout << "Digite sua idade: ";
  cin >> idade;
  cout << "Ola " << nome;
  cout << " voce tem " << idade; 
  cout << " anos." << endl;
  return 0;
}

#include <iostream>
using namespace std;

int main() {
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

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    float valorAparelho = 1000.0;
    float jurosMensal = 0.015; // 1.5% ao mês
    float prestacaoMensal = 50.0;
    float debito = valorAparelho;
    int meses = 0;
    float totalJuros = 0.0;

    while (debito > 0) {
        // Calcular juros do mês
        float juros = debito * jurosMensal;

        // Atualizar débito considerando o pagamento da prestação
        debito -= (prestacaoMensal - juros);
        totalJuros += juros;

        // Verificar se o último pagamento será menor que a prestação
        if (debito < prestacaoMensal) {
            prestacaoMensal = debito + juros; // Último pagamento considera os juros
            debito = 0; // Finaliza o pagamento
        }

        meses++;
    }

    cout << "Número de meses necessários: " << meses << endl;
    cout << "Soma total paga em juros: R$ " << totalJuros << endl;

    return 0;
}


#include <iostream>

using namespace std;

//Métodos inclusos
void baum();
void folhaSalarial();
void prestacoes();

//Execução principal
int main() {
    //baum();
    //folhaSalarial();
    prestacoes();
    return 0;
}

//Implementação do código
void baum(){
  cout << "C tah baum?" << endl;
}
void folhaSalarial(){
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
void prestacoes() {
    float valorAparelho = 1000.0;
    float jurosMensal = 0.015; // 1.5% ao mês
    float prestacaoMensal = 50.0;
    float debito = valorAparelho;
    int meses = 0;
    float totalJuros = 0.0;

    while (debito > 0) {
        // Calcular juros do mês
        float juros = debito * jurosMensal;

        // Atualizar débito considerando o pagamento da prestação
        debito -= (prestacaoMensal - juros);
        totalJuros += juros;

        // Verificar se o último pagamento será menor que a prestação
        if (debito < prestacaoMensal) {
            prestacaoMensal = debito + juros; // Último pagamento considera os juros
            debito = 0; // Finaliza o pagamento
        }

        meses++;
    }

    cout << "Número de meses necessários: " << meses << endl;
    cout << "Soma total paga em juros: R$ " << totalJuros << endl;
}
*/

