#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class PRODUTO{
    //IMPLEMENTAÇÃO
    
    private:
        std::string nome;
        int tipo=0;                                             //1=eletrodomesticos,2=movel,3=decoracao
        int faixa_preco=0;
        int estoque=0;
        int desconto=0;                                         //1=Sim,0=Nao

        std::vector<PRODUTO> produtos;                          //Vetor de produtos

        std::vector<PRODUTO> vetor_descontos;
        std::vector<PRODUTO> vetor_eletrodomesticos;            
        std::vector<PRODUTO> vetor_moveis;                      //Vetores de cada tipo
        std::vector<PRODUTO> vetor_decoracao;

    public:
    //INTERFACE

        //ABRIR ARQUIVO PARA LEITURA E MANIPULAR O VETOR <produtos>
        void ler_arquivo(){
            std::ifstream arq("catalogo.txt");      //CRIADA DE UM OBJETO DA CLASSE IFSTREAM
            if(!arq){
                std::cout<<"ERRO AO ABRIR O ARQUIVO!"<<std::endl;       
            }
        
            //LEITURA 
            else{
                PRODUTO temp;
                while(arq>>temp.nome>>temp.tipo>>temp.faixa_preco>>temp.estoque>>temp.desconto){  //Enquanto ler, atribuir a temp
                    produtos.push_back(temp);                                      //Aqui, ele coloca cada objeto dentro de um vetor <produtos>
                }
            
                arq.close();           //FECHA O ARQUIVO

                /*for(int i=0;i<produtos.size();i++){          //PARA TESTES
                    std::cout<<produtos[i].nome<<" "<<produtos[i].estoque<<std::endl;
                }*/
            }
        }

        //CRIAR UM VETOR PARA CADA TIPO DE PRODUTO
        void organizar_vetores(){
                
                //VETOR DE DESCONTOS
                for(int i=0;i<produtos.size();i++){                                
                    if(produtos[i].desconto==1){
                        PRODUTO temp;
                        temp = produtos[i];
                        vetor_descontos.push_back(temp);
                    } 

                }

                //VETOR DE ELETRODOMESTICOS
                for(int i=0;i<produtos.size();i++){                                
                    if(produtos[i].tipo==1){
                        PRODUTO temp;
                        temp = produtos[i];
                        vetor_eletrodomesticos.push_back(temp);
                    } 

                }

                //VETOR DE MOVEIS
                for(int i=0;i<produtos.size();i++){                                
                    if(produtos[i].tipo==2){
                        PRODUTO temp;
                        temp = produtos[i];
                        vetor_moveis.push_back(temp);
                    }
                }

                //VETOR DE DECORAÇÕES
                for(int i=0;i<produtos.size();i++){                                
                    if(produtos[i].tipo==3){
                        PRODUTO temp;
                        temp = produtos[i];
                        vetor_decoracao.push_back(temp);
                    }
                }
        }
        
        //IMPRIMIR ESCOLHA
        void imprimir_produto_sem_desconto(int tipo,int preco){
            if(tipo==1){
                for(int i=0;i<vetor_eletrodomesticos.size();i++){
                    if(vetor_eletrodomesticos[i].faixa_preco==preco){
                        std::cout<<vetor_eletrodomesticos[i].nome<<"   Quantidade no estoque: "<<vetor_eletrodomesticos[i].estoque<<std::endl;
                    }
                }
            }

            else if(tipo==2){
                for(int i=0;i<vetor_moveis.size();i++){
                    if(vetor_moveis[i].faixa_preco==preco){
                        std::cout<<vetor_moveis[i].nome<<"   Quantidade no estoque: "<<vetor_moveis[i].estoque<<std::endl;
                    }
                }
            }

            else if(tipo==3){
                for(int i=0;i<vetor_decoracao.size();i++){
                    if(vetor_decoracao[i].faixa_preco==preco){
                        std::cout<<vetor_decoracao[i].nome<<"   Quantidade no estoque: "<<vetor_decoracao[i].estoque<<std::endl;
                    }
                }
            }
        }

        void imprimir_produto_com_desconto(){
                for(int i=0;i<vetor_descontos.size();i++){
                    if(vetor_descontos[i].desconto==1){
                        std::cout<<vetor_descontos[i].nome<<"   Quantidade no estoque: "<<vetor_descontos[i].estoque<<std::endl;
                    }
        }
    }

};