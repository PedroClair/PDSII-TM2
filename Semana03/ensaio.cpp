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

