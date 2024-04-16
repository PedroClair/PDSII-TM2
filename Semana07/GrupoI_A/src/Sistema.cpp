#include "Sistema.hpp"
#include "PrestadorDeServicos.hpp"
#include "Prestadores.hpp"
#include "auxiliares.hpp"
#include <string>
#include <iostream>


using namespace std;

Sistema::Sistema(){}

void Sistema::_cadastro(string nome, string endereco, string cpf, string telefone){
    Usuario usuario(nome, endereco, cpf, telefone);
    usuarios.push_back(usuario);
}

void Sistema::cadastro(){
    if (logado) {
        cout << "Erro! Usuário já logado.\n";
        return;
    }

    cout << " ---[ Sistema de Cadastro ]---\n\n";

    string nome, endereco, cpf, telefone;

    cout << "Digite seu nome completo: ";
    getline(cin, nome);

    cout << "Digite seu endereço: ";
    getline(cin, endereco);

    cout << "Digite seu cpf: ";
    getline(cin, cpf);

    cout << "Digite seu telefone: ";
    getline(cin, telefone);

    for (Usuario& usuario: usuarios){
        if(usuario.cpf == cpf){
            cout << "Erro! Usuário já existente!\n";
            return;
        }
    }

    Usuario usuario(nome, endereco, cpf, telefone);
    usuarios.push_back(usuario);

    usuario_atual = usuario;
    logado = true;

    cout << "Usuário cadastrado e logado com sucesso!\n";


}

void Sistema::deslogar(){
    if (!logado) {
        cout << "Usuário não está logado.\n";
        return;
    }

    logado = false;
    cout << "Usuário deslogado com sucesso!\n";
}

void Sistema::logar(){
    if (logado) {
        cout << "Usuário já logado.\n";
        return;
    }

    cout << "---[ Login ]---\n";

    string nome, cpf;

    cout << "Nome de usuário: ";
    getline(cin, nome);

    cout << "Cpf: ";
    getline(cin, cpf);

    for (Usuario& usuario: usuarios){
        if(usuario.cpf == cpf && usuario.nome == nome){
            usuario_atual = usuario;
            logado = true;
            cout << "Usuário logado com sucesso!\n";
            return;
        }
    }
    cout << "Erro, conta inexistente\n";
    return;
}

void Sistema::deletar_conta(){
    cout << "---[ Deletar ]---\n";

    if (!logado){
        cout << "Usuário não logado, erro!\n";
        return ;
    }

    int to_delete = -1;

    for (int i=0; i < (int)usuarios.size(); i++){
        if(usuarios[i].cpf == usuario_atual.cpf && usuarios[i].nome == usuario_atual.nome){
            to_delete = i;
        }
    }

    if (to_delete != -1){
        //Atualiza a lista de prestadores, removendo o usuário
        vector<PrestadorDeServicos> updated;
        for (auto& prestador: prestadores.prestadores){
            if (prestador.cpf != usuario_atual.cpf)
            updated.push_back(prestador);
        }
        prestadores.prestadores = updated;


        deslogar();
        usuarios.erase (usuarios.begin() + to_delete);
        cout << "Conta deletada com sucesso\n";

        return ;
    }

    cout << "Erro, conta inexistente\n";
    return ;
}

void Sistema::oferecer_servico() {
    if (!logado) {
        std::cout << "Faça login primeiro para oferecer serviços." << std::endl;
        return;
    }

    // Verifica se o usuário atual já é um prestador de serviços
    for (PrestadorDeServicos& prestador : prestadores.prestadores) {
        if (prestador.cpf == usuario_atual.cpf) {
            std::cout << "Você já é um prestador de serviços." << std::endl;
            return;
        }
    }

    std::string servico, valors, local;
    double valor;

    std::cout << "Digite o nome do serviço que deseja oferecer: ";
    getline(cin, servico);

    std::cout << "Digite o valor do serviço: ";
    getline(cin, valors);
    valor = stod(valors);

    std::cout << "Você o oferece em local fixo? [Ss/Nn]: ";
    getline(cin, local);
    local = upper(local);
   
    PrestadorDeServicos novoPrestador(usuario_atual.nome, usuario_atual.endereco, usuario_atual.cpf, usuario_atual.telefone, !(local == string("S")));
    novoPrestador.adicionar_servico(servico, valor);

    prestadores.prestadores.push_back(novoPrestador);

    std::cout << "Serviço oferecido com sucesso!" << std::endl;
}


void Sistema::pesquisar_servico(){
    if (!logado) {
        std::cout << "Faça login primeiro para buscar serviços." << std::endl;
        return;
    }

    std::string servico_buscado;

    std::cout << "Digite o nome do serviço: ";
    getline(cin, servico_buscado);
    Prestadores prestadoresProximos;

    for (PrestadorDeServicos& prestador : prestadores.prestadores) {
        for (auto& servico : prestador.servicos) {
            if(pesquisar(servico_buscado, servico.first) > 0){
                //Se ele achar mais de uma palavra que corresponda
                prestadoresProximos.prestadores.push_back(prestador);
            }
        }
    }

    vector<PrestadorDeServicos> resposta = prestadoresProximos.localizar_via_endereco(usuario_atual.endereco);

    cout << "Foram encontrados os seguintes serviços perto de você: \n";

    for (PrestadorDeServicos& prestador : resposta) {
        prestador.apresentacao();
        cout << endl;
    }
    
    if(resposta.size() == 0){
        cout << "\nNão foi encontrado nenhum serviço assim sendo oferecido no app :(\n\n";
    }

    string str;

    cout << "\nAperte [Enter] para sair: ";
    getline(cin, str);

    return ;
}

void Sistema::show_usuario(){
    if (!logado) {
        std::cout << "Faça login primeiro para consultar seu usuário." << std::endl;
        return;
    }

    usuario_atual.dados();

    for (PrestadorDeServicos& prestador : prestadores.prestadores) {
        if (prestador.cpf == usuario_atual.cpf) {
            cout << "\nComo prestador de serviço:\n\n";
            prestador.apresentacao();
        }
    }

    string str;

    cout << "\nAperte [Enter] para sair: ";
    getline(cin, str);
}