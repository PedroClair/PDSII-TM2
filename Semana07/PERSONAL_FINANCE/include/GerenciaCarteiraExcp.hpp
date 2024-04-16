#ifndef GERENCIA_CARTEIRA_EXCP_H
#define GERENCIA_CARTEIRA_EXCP_H

#include <exception>
#include <string>

namespace gcexcp {
    class PerfilVazio : public std::exception {
        public:
            PerfilVazio();

            const char* what() const throw();
    };
}

#endif
