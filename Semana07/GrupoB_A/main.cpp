#include <iostream>
#include <string>
#include <fstream>
#include "produtos.hpp"



int main(){
    
    //Executavel
    PRODUTO produto0;
    produto0.ler_arquivo();                     //CATALOGAR OS PRODUTOS
    produto0.organizar_vetores();


    std::cout<<"Seja bem vindo(a) a nossa loja"<<std::endl;
    std::cout<<"Voce deseja ver os produtos em desconto?"<<std::endl;
    std::cout<<"[1]Sim"<<std::endl;
    std::cout<<"[2]Nao"<<std::endl;

    int escolha_desconto=0;
    std::cin>>escolha_desconto;

    if(escolha_desconto==1){
        produto0.imprimir_produto_com_desconto();
    }

    else{
        std::cout<<"Que tipo de produto voce busca?"<<std::endl;
        std::cout<<"[1]Eletrodomesticos"<<std::endl;
        std::cout<<"[2]Moveis"<<std::endl;
        std::cout<<"[3]Decoracoes"<<std::endl;

        int escolha_tipo=0;
        std::cin>>escolha_tipo;

        std::cout<<"Que faixa de preco voce deseja?"<<std::endl;
        std::cout<<"[1](1-50)"<<std::endl;
        std::cout<<"[2](51-100)"<<std::endl;
        std::cout<<"[3](101-150)"<<std::endl;
        std::cout<<"[4](150-200+)"<<std::endl;

        int escolha_preco=0;
        std::cin>>escolha_preco;

        produto0.imprimir_produto_sem_desconto(escolha_tipo,escolha_preco);
    }

    return 0;
    
}

