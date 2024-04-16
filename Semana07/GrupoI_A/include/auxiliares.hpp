#ifndef AUX_H
#define AUX_H

#define LIMIT 4

using namespace std;

std::vector<std::string> tokenize(std::string, std::string);

std::map<int, std::vector<std::string>> swap(std::map<std::string, int> score);

std::vector<std::string> find_head(std::map<std::string, int> score);

int pesquisar(string servico_busca, string servico);

string upper(string);

#endif