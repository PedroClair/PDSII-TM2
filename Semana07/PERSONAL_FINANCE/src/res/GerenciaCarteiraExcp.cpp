#include "GerenciaCarteiraExcp.hpp"

// --------------------------------------------- Métodos para PerfilVazio ----------------------------------------------

gcexcp::PerfilVazio::PerfilVazio() {}

const char* gcexcp::PerfilVazio::what() const throw() {
    return "ERRO 🕵️: AINDA NÃO EXISTEM CARTEIRAS CADASTRADAS";
}
