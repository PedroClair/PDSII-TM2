#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

class Persona {
    private:
        std::string nome;

    protected:
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