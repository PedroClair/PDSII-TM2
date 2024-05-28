#ifndef PESSOA_H
#define PESSOA_H

#include "persona.hpp"

class Pessoa : public Persona {
    private: // Uma boa prática é transformar para private
        unsigned int _cpf;

    protected: // Uma boa prática é transformar para protected
        unsigned int getCpf();
        void setCpf(unsigned int novoCpf);
    
    public:
        Pessoa();
        Pessoa(std::string nome, unsigned int novoCpf);
        //Métodos inclusos
        void cumprimenta() override;
        ~Pessoa();
};

#endif //PERSONA_H