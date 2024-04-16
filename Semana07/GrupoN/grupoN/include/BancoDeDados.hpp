#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <iostream>
#include <sqlite3.h>

class BancoDeDados {
private:
  sqlite3 *bd;   // Ponteiro para conexão SQLite
  char *zErrMsg; // Salva mensagens de erro
  int rc;
  std::string sql; // Comando SQL

  // Função callback
  static int callback(void *NotUsed, int argc, char **argv, char **azColName);
  void checaErroBD();

public:
  BancoDeDados();
  void destinos();
  void closeBD();
};

#endif