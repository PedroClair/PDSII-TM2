#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "auxiliares.hpp"

std::vector<std::string> tokenize(std::string s, std::string del = " ")
{
    std::vector<std::string> output;

    int start, end = -1 * del.size();
    do
    {
        start = end + del.size();
        end = s.find(del, start);
        output.push_back(s.substr(start, end - start));
    } while (end != -1);

    return output;
}

//Função auxiliar para localização de serviços via endereço
std::map<int, std::vector<std::string>> swap(std::map<std::string, int> score){
    std::map<int, std::vector<std::string>> output;

    for (std::pair<std::string, int> p: score){
        output[p.second].push_back(p.first);
    }

    return output;
}

//Função auxiliar para localização de serviços via endereço
std::vector<std::string> find_head(std::map<std::string, int> score){
    std::map<int, std::vector<std::string>> swaped = swap(score);

    std::vector<std::string> output;

    std::vector<int> indices;

    for (std::pair<int,  std::vector<std::string>> p : swaped){
        indices.push_back(p.first);
    }

    std::sort(indices.begin(), indices.end());

    for (int i=indices.size()-1 ; i>=0; i--){
        while(swaped[indices[i]].size() > 0 && output.size() < LIMIT){
            output.push_back(swaped[indices[i]].back());
            swaped[indices[i]].pop_back();
        }   
    }

    return output;
    
}

string upper(string input){
    for (auto & c: input) c = toupper(c); // Passa a string para maiúsculo
    return input;
}

int pesquisar(string palavra_busca, string servico){

    palavra_busca = upper(palavra_busca);
    servico = upper(servico);

    int score=0;

    std::vector<std::string> palavras_pesquisa = tokenize(palavra_busca, " ");

    for (std::string &palavra : palavras_pesquisa)
    {
        if (servico.find(palavra) != std::string::npos){
            score++;
        }
    }

    return score;
}
