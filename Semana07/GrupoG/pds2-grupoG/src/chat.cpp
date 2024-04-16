#include "chat.hpp"
#include <iostream>

using namespace std;

namespace ChatOnline {
    string responderDuvida(const string& pergunta) {
        if (pergunta.find("como alugar um livro") != string::npos ||
            pergunta.find("como locar um livro") != string::npos) {
            return "Para alugar um livro, voce pode visitar nossa biblioteca pessoalmente ou fazer uma reserva online.";
        } else {
            return "Desculpe, nao entendi sua pergunta. Por favor, tente novamente ou entre em contato conosco.";
        }
    }
}

