#include <iostream>
#include "modelagem.hpp"

int main () {
    int opcao;

    std::cout << "  ____________________________________________________" << std::endl;
    std::cout << " /                                                    \\" << std::endl;
    std::cout << "|        Sistema de Gerenciamento de Imóveis          |" << std::endl;
    std::cout << "|____________________________________________________ |" << std::endl;
    std::cout << "| 1. Exibir modelagem do sistema                      |" << std::endl;
    std::cout << "| 2. Cadastrar novo imóvel                            |" << std::endl;
    std::cout << "| 3. Cadastrar nova empresa                           |" << std::endl;
    std::cout << "| 4. Verificar compatibilidade                        |" << std::endl;
    std::cout << "| 5. Mostrar lista de imóveis cadastrados             |" << std::endl;
    std::cout << "| 6. Mostrar lista de empresas cadastradas            |" << std::endl;
    std::cout << "| 7. Pesquisar imóveis por critérios específicos      |" << std::endl;
    std::cout << "| 8. Pesquisar empresas por critérios específicos     |" << std::endl;
    std::cout << "| 9. Editar informações de imóvel                     |" << std::endl;
    std::cout << "| 10. Editar informações de empresa                   |" << std::endl;
    std::cout << "| 11. Remover imóvel                                  |" << std::endl;
    std::cout << "| 12. Remover empresa                                 |" << std::endl;
    std::cout << "| 13. Mostrar melhor combinação possível              |" << std::endl;
    std::cout << "| 0. Sair                                             |" << std::endl;
    std::cout << "|_____________________________________________________|" << std::endl;
    std::cout << "|                                                     |" << std::endl;
    std::cout << "| Escolha uma opção:                                  |" << std::endl;
    std::cout << "|_____________________________________________________|" << std::endl;

   do{
    switch (opcao) {
            case 1:
                std::cout << "O projeto presente neste repositório tem como seu principal objetivo replicar o funcionamento de um sistema em C++ para conectar donos de imóveis com empresas e pessoas que buscam espaços para realizar coworking. O sistema deve permitir que os donos cadastrem seus imóveis e as empresas respondam a um questionário para verificar se o local é compatível com suas necessidades. O sistema também deve ser capaz de encontrar a melhor combinação possível entre os imóveis disponíveis e as empresas interessadas. As funçionalidades implementadas estão listadas a seguir, existe uma historia de usuario para cada uma delas, escolha o numero para visualizar a historia de usuario correspondente." << std::endl;
                std::cout << "1 - Cadastro de empresa: Cadastro de empresa que está em busca de alugar um estabelecimento, sala, escritporio, etc..." << std::endl;
                std::cout << "2 - Cadastro de imóvel: Lançamento de imóvel para aluguel" << std::endl;
                std::cout << "3 - Avaliação de local: Espaço para avaliar locais publicados (um sistema de estrelas) e deixar comentários de ex-locadores" << std::endl;
                std::cout << "4 - Busca por imóvel: Função de filtro para fazer buscar um local com determinados padrões desejados" << std::endl;
                std::cout << "5 - Match  imóvel x empresa x empresa2: Indicador de se o espaço já tem empresa interessada, e dados para entrar em contato em busca de rachar o aluguel" << std::endl;
                std::cout << "Escolha uma historia de usuario (de 1 a 5): " << std::endl;

                int historias;
                std::cin >> historias;
                
                if(historias == 1){
                    historia1();
                }else if(historias == 2){
                    historia2();
                }else if(historias == 3){
                    historia3();
                }else if(historias == 4){
                    historia4();
                }else if(historias == 5){
                    historia5();
                }else{
                    std::cout << "Opção inválida!" << std::endl;
                }
                break;
            case 2:
                std::cout << "Cadastrando novo imóvel..." << std::endl;
                break;
            case 3:
                std::cout << "Cadastrando nova empresa..." << std::endl;
                break;
            case 4:
                std::cout << "Verificando compatibilidade..." << std::endl;
                break;
            case 5:
                std::cout << "Mostrando lista de imóveis cadastrados..." << std::endl;
                break;
            case 6:
                std::cout << "Mostrando lista de empresas cadastradas..." << std::endl;
                break;
            case 7:
                std::cout << "Pesquisando imóveis por critérios específicos..." << std::endl;
                break;
            case 8:
                std::cout << "Pesquisando empresas por critérios específicos..." << std::endl;
                break;
            case 9:
                std::cout << "Editando informações de imóvel..." << std::endl;
                break;
            case 10:
                std::cout << "Editando informações de empresa..." << std::endl;
                break;
            case 11:
                std::cout << "Removendo imóvel..." << std::endl;
                break;
            case 12:
                std::cout << "Removendo empresa..." << std::endl;
                break;
            case 13:
                std::cout << "Mostrando melhor combinação possível..." << std::endl;
                break;
            case 0:
                std::cout << "Saindo do programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }

   }while(opcao != 0);
        
    return 0;
}