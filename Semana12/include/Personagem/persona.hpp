#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

class Persona {
    private: // Uma boa prática é transformar para private
        std::string _nome;

    protected: // Uma boa prática é transformar para protected
        std::string getName();
        void setName(std::string novoNome);
    
    public:
        Persona();
        Persona(std::string nome);
        //Métodos inclusos
        virtual void cumprimenta() = 0;
        ~Persona();
};

#endif //PERSONA_H