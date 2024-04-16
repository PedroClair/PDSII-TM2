#include <iostream>
#include <cstdlib>
#include "Prestadores.hpp"
#include "Usuario.hpp"
#include "PrestadorDeServicos.hpp"
#include "Sistema.hpp"

#define CLEAR_COMAND "clear"

//#define WINDOWS 
//unconment if you are compiling to windows

#define STOP_TIME 1 
//Quantidade de segundos de espera entre uma tela e outra

#ifndef WINDOWS 
#include <unistd.h> 
#else
#include <windows.h>
#endif

using namespace std;

int main()
{
    Sistema sistema;
    bool running = true;
    while (running){
        string acao;

        system(CLEAR_COMAND);

        cout << "Ações possíveis: \n";
        cout << "(0) Cadastrar um novo usuario\n";
        cout << "(1) Logar na sua conta de usuário\n";
        cout << "(2) Passar a prestar um serviço\n";
        cout << "(3) Pesquisar serviço\n";
        cout << "(4) Deletar conta\n";
        cout << "(5) Meu usuário\n";
        cout << "(6) Deslogar\n";
        cout << "(7) Sair do sistema\n";

        cout << "Digite o numero correspondente à ação a ser executada: ";
        getline(cin, acao);

        system(CLEAR_COMAND);

        switch (stoi(acao))
        {
        case 0:
            sistema.cadastro();
            break;
        
        case 1:
            sistema.logar();
            break;
        
        case 2:
            sistema.oferecer_servico();
            break;
        
        case 3:
            sistema.pesquisar_servico();
            break;
        
        case 4:
            sistema.deletar_conta();
            break;

        case 5:
            sistema.show_usuario();
            break;

        case 6:
            sistema.deslogar();
            break;
        case 7:
            running = false;
            cout << "\nFoi um prazer, e volte sempre :)\n\n";
        
        default:
            break;
        }

        sleep(STOP_TIME);

    }
    

    return 0;
}
