#include "./include/BancoDeDados.hpp"

using namespace std;

int main() {
  BancoDeDados BD;
  BD.destinos();
  return 0;
}

/*#include <iostream>
#include <sqlite3.h>

using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  for (int i = 0; i < argc; i++)
    cout << azColName[i] << ": " << argv[i] << endl;
  return 0;
}

int main() {
  sqlite3 *bd;
  char *zErrMsg = 0;
  string sql;

  int rc = sqlite3_open("./db/grupoN.db", &bd);
  if (rc) {
    cerr << sqlite3_errmsg(bd) << endl;
    sqlite3_close(bd);
    return (-1);
  }
  sql =
      "SELECT DISTINCT aeroporto_o, cidade_o FROM Passagens WHERE pais_o='BR';";
  rc = sqlite3_exec(bd, sql.c_str(), callback, 0, &zErrMsg);
  sqlite3_close(bd);

  return 0;
}
*/