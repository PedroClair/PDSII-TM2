#include <iostream>
#include <string>

struct EmployeeData {
    std::string Name;
    std::string Address;
    std::string Zipcode;
};

//Métodos inclusos
void cumprimento();
void declaracaoDePonteiros();
void difPonteiros();
void fill_data(EmployeeData *ptr, int N);
void funcionarios();

//Execução principal
int main() {
    funcionarios();
    return 0;
}

//Implementação do código
void cumprimento(){
  std::cout << "C tah baum?" << std::endl;
}

void declaracaoDePonteiros(){
    char* atv1;                    // ponteiro para char
    char** atv2;                   // ponteiro para ponteiro de char
    char* atv3[100];               // array de tamanho 100 de ponteiros para char
    int (*atv4)[100];              // ponteiro para um array de tamanho 100
    const int* atv5;               // ponteiro constante para um inteiro
    int const* atv6;               // ponteiro para um inteiro constante
}

void difPonteiros(){
    int escolha;
    do {
        std::cout << "Qual definição você deseja?" << std::endl;
        std::cout << "1 - Ponteiro constante" << std::endl;
        std::cout << "2 - Ponteiro para tipo constante" << std::endl;
        std::cout << "0 - Entendi agora!!!" << std::endl;
        std::cin >> escolha;
        switch (escolha){
            case 1:
                std::cout << "O ponteiro é constante, o que significa que o endereço que ele armazena não pode ser alterado após a inicialização. \nNo entanto, o valor para o qual ele aponta pode ser alterado." << std::endl;
                break;
            case 2:
                std::cout << "O ponteiro aponta para um tipo constante, o que significa que o valor para o qual ele aponta não pode ser alterado. \nNo entanto, o endereço que o ponteiro armazena pode ser alterado." << std::endl;
                break;
            case 0:
                continue;
            default:
                std::cout << "Escolha inválida!" << std::endl;
        }
    } while ( escolha != 0 );
}

void fill_data(EmployeeData *ptr, int N) {
    for (int i = 0; i < N; ++i) {
        std::cout << "Funcionario " << i + 1 << ":\n";
        std::cout << "Nome: ";
        std::getline(std::cin, ptr[i].Name);
        std::cout << "Endereco: ";
        std::getline(std::cin, ptr[i].Address);
        std::cout << "CEP: ";
        std::getline(std::cin, ptr[i].Zipcode);
    }
}
void funcionarios(){
    int N;
    // Recebendo o número total de funcionários
    std::cout << "Digite o total de funcionarios: ";
    std::cin >> N;
    std::cin.ignore(); // Limpa o buffer de entrada

    // Alocando memória para um array de funcionários
    EmployeeData* employees = new EmployeeData[N];

    // Preenchendo os dados dos funcionários
    fill_data(employees, N);

    // Imprimindo os dados dos funcionários
    std::cout << "\nDados dos funcionarios:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "Funcionario " << i + 1 << ":\n";
        std::cout << "Nome: " << employees[i].Name << "\n";
        std::cout << "Endereco: " << employees[i].Address << "\n";
        std::cout << "CEP: " << employees[i].Zipcode << "\n";
    }

    // Liberando a memória alocada
    delete[] employees;
}



















/* Refinamento do makefile
CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = program

BUILD = ./build

${TARGET}: 
	${CC} ${CFLAGS} ensaio.cpp -o ${BUILD}/${TARGET}
	${BUILD}/${TARGET}



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

