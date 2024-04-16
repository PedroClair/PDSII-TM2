#include "doctest.h"
#include "Transferencia.hpp"

#define BIG_NUMBER 1000000000000000000

TEST_CASE("Criar transferencia com valor negativo") {
    CHECK_THROWS_AS(Transferencia(-1, "10/10/2010", "c1", "o1", "d1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar transferencia com valor maior do que o PIB mundial") {
    CHECK_THROWS_AS(Transferencia(BIG_NUMBER, "10/10/2010", "c1", "o1", "d1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar transferencia com uma data invalida") {
    CHECK_THROWS_AS(Transferencia(1, "31/11/2010", "c1", "o1", "d1"), trsexcp::DataInvalida);
}

TEST_CASE("Criar transferencia para a mesma conta") {
    CHECK_THROWS_AS(Transferencia(1, "10/10/2010", "c1", "o1", "o1"), trsexcp::OrigemDestinoIguais);
}

TEST_CASE("Alterar origem") {
    Transferencia t1 = Transferencia(1, "10/10/2010", "c1", "o1", "d1");
    t1.alterarOrigem("o2");
    CHECK(t1.getOrigem() == "o2");
}

TEST_CASE("Alterar origem para nome igual ao antigo destino") {
    Transferencia t1 = Transferencia(1, "10/10/2010", "c1", "o1", "d1");
    CHECK_THROWS_AS(t1.alterarOrigem("d1"), trsexcp::OrigemDestinoIguais);
}

TEST_CASE("Alterar destino") {
    Transferencia t1 = Transferencia(1, "10/10/2010", "c1", "o1", "d1");
    t1.alterarDestino("d2");
    CHECK(t1.getDestino() == "d2");
}

TEST_CASE("Alterar destino para nome igual a antiga origem") {
    Transferencia t1 = Transferencia(1, "10/10/2010", "c1", "o1", "d1");
    CHECK_THROWS_AS(t1.alterarDestino("o1"), trsexcp::OrigemDestinoIguais);
}

TEST_CASE("Output") {
    Transferencia t1 = Transferencia(1, "10/10/2010", "c1", "o1", "d1");
    t1.imprimirInfo();
}
