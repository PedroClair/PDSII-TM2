#include "../include/BancoDeDados.hpp"
#include <iostream>
#include <sqlite3.h>

int BancoDeDados::callback(void *NotUsed, int argc, char **argv,
                           char **azColName) {

  // int argc: número de resultados
  // (array) azColName: nome colunas
  // (array) argv: valores

  for (int i = 0; i < (argc - 1); i++) {

    std::cout << argv[i] << ": " << argv[i + 1] << std::endl;
  }
  return 0;
}
void BancoDeDados::checaErroBD() {
  if (rc) {
    std::cout << "DB Error: " << sqlite3_errmsg(bd) << std::endl;
    closeBD();
  }
}
BancoDeDados::BancoDeDados() {
  rc = sqlite3_open("./db/grupoN.db", &bd);
  checaErroBD();
}

void BancoDeDados::destinos() {
  sql =
      "SELECT DISTINCT aeroporto_o, cidade_o FROM Passagens WHERE pais_o='BR';";
  rc = sqlite3_exec(bd, sql.c_str(), callback, 0, &zErrMsg);
}

void BancoDeDados::closeBD() { sqlite3_close(bd); }
