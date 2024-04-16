#include "PrestadorDeServicos.hpp"
#include "Prestadores.hpp"
#include "Usuario.hpp"
#include <vector>

using namespace std;

class Sistema {
public:
    vector<Usuario> usuarios;
    Prestadores prestadores;

    Usuario usuario_atual;

    bool logado;

    Sistema();

    void logar();
    void deslogar();
    void _cadastro(string, string, string, string);
    void cadastro();
    void oferecer_servico();
    void pesquisar_servico();
    void deletar_conta();
    void show_usuario();
};

/*
Historias de usuário:

Quero poder cadastrar meu usuário no app para poder acessar o serviço

Quero poder trocar minha conta de usuário para prestador de serviços também

Quero poder pesquisar por um nome de serviço e poder ver os prestadores mais próximos de mim

Quero poder deletar minha conta ou torná-la a ser somente um usuário.

Quero buscar um serviço e poder ver os valores
*/