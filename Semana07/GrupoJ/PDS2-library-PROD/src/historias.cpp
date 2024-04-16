#include "../include/historias.hpp"
#include <iostream>

void listarHistorias()
{
    cout << "1" << endl;
    cout << "Historia: \n: Como um novo membro da comunidade da biblioteca, desejo poder criar uma conta no sistema da biblioteca para acessar os serviços oferecidos como pesquisar e reservar livros." << endl;
    cout << "Cenário Teste:" << endl;
    cout << "Requisito1: O usuário deve ser capaz de conseguir registrar seu dados e ter um perfil." << endl;
    cout << "Requisito2: O usuário deve conseguir ver quais livros estão emprestados por ele naquele momento. " << endl;
    cout << "Requisito3: O usuário deve conseguir ver o histórico de livros emprestados." << endl;

    cout
        << "2" << endl;
    cout << "Historia: Como um adminstrador da biblioteca, desejo poder cadastrar novos livros no sistema para que eles estejam disponíveis para empréstimo. Eu gostaria de inserir informações como título, autor, gênero e número de cópias disponíveis." << endl;
    cout << "Cenário Teste: " << endl;
    cout << "Requisito1:Apenas o admistrador deve ser possível adicionar  novos livros ao catálogo do sistema. " << endl;
    cout << "3" << endl;
    cout << "Historia: Como um usuário da biblioteca, desejo poder pesquisar livros por título, autor ou gênero para encontrar rapidamente os materiais que estou interessado em ler. Eu gostaria que os resultados da pesquisa mostrassem informações detalhadas sobre cada livro, como disponibilidade e localização na biblioteca." << endl;
    cout << "Cenário Teste" << endl;
    cout << "Requisito1:O usuário deve ser capaz de pesquisar no catálogo da loja , por título. " << endl;

    cout << "4" << endl;
    cout << "Historia: Como um usuário da biblioteca, desejo poder reservar livros que não estão atualmente disponíveis para empréstimo. Eu gostaria de receber uma notificação quando o livro estiver disponível para retirada e de ter um prazo para buscá-lo antes que a reserva seja cancelada." << endl;
    cout << "Cenário Teste: " << endl;
    cout << "Requisito1: Um usuário após registrado deve poder reservar um livro. " << endl;
    cout << "5" << endl;
    cout << "Historia: Como usuário da biblioteca, desejo poder renovar o empréstimo de um livro online, para que possa estender o prazo de devolução sem precisar ir pessoalmente à biblioteca." << endl;
    cout
        << "Cenário Teste:" << endl;
    cout << "Requisito1: Um usuário logado na plataforma da biblioteca deseja renovar o empréstimo de um livro que está atualmente em seu nome " << endl;
    cout << "Requisito2: O usuário acessa a seção de  Renovação de Empréstimo  na interface da biblioteca online." << endl;
    cout << "Requisito3: O sistema exibe uma lista dos livros atualmente emprestados para o usuário, juntamente com as datas de devolução" << endl;
    cout << "Requisito4: O sistema da a opção do usuario escolher qual livro ele quer reservar novamente" << endl;
}