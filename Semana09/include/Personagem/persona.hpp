#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <list>

class Persona {
    public: // Uma boa prática é transformar para private
        std::string nome;
        std::list<std::string> telefone;

    public: // Uma boa prática é transformar para protected
        std::string getName();
        void setName(std::string novoNome);
    
    public:
        Persona();
        Persona(std::string);
        //Métodos inclusos
        void cumprimento();
        ~Persona();
};

#endif //PERSONA_H