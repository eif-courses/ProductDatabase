#include <iostream>
#include "sqlite3.h"


// https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm


static int callback(void *data, int argc, char **argv, char **azColName){
  int i;
  fprintf(stderr, "%s: ", (const char*)data);

  for(i = 0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  // column name-value is not null
  printf("\n");
  return 0;
}

int main() {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc; // if connection successfull 1 if false 0

  rc = sqlite3_open("test.db", &db);
  if( rc ) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return(0);
  } else {
    fprintf(stderr, "Opened database successfully\n");
  }
//  /* Create SQL statement */
//  char *sql = "CREATE TABLE COMPANY("  \
//      "ID INT PRIMARY KEY     NOT NULL," \
//      "NAME           TEXT    NOT NULL," \
//      "AGE            INT     NOT NULL," \
//      "ADDRESS        CHAR(50)," \
//      "SALARY         REAL );";
//
//  rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);
//
//  if( rc != SQLITE_OK ){
//    fprintf(stderr, "SQL error: %s\n", zErrMsg);
//    sqlite3_free(zErrMsg);
//  } else {
//    fprintf(stdout, "Table created successfully\n");
//  }
  /* Create SQL statement */
//  char *sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
//         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
//         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
//         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
//         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
//         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
//         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
//         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
//
//  /* Execute SQL statement */
//  rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);
//
//  if( rc != SQLITE_OK ){
//    fprintf(stderr, "SQL error: %s\n", zErrMsg);
//    sqlite3_free(zErrMsg);
//  } else {
//    fprintf(stdout, "Records created successfully\n");
//  }
  const char* data = "Callback function called";
  /* Create SQL statement */
  char *sql = "select * from COMPANY";


  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

  if( rc != SQLITE_OK ) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Operation done successfully\n");
  }




  sqlite3_close(db);
  return 0;
}
void selectNames(){

}