#include <iostream>
#include <sqlite3.h> 

using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; i++)
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    
    printf("\n");
    return 0;
}

int main(int argc, char* argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int  rc;
    string sql, sqlInsert, sqlSelect, sqlUpdate, sqlDelete;
    const char* data = "Callback function called";

    rc = sqlite3_open("test.db", &db);
    if( rc )
    {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return 0;
    }
    else
    {
        cout << "********************** Opened database successfully **********************" << endl;
    }

    sql = "CREATE TABLE COMPANY(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL,AGE INT NOT NULL, ADDRESS CHAR(50), SALARY REAL);";
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        cout << "SQL error: "<< zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "********************** Table created successfully ********************** \n");
    }

    sqlInsert = "INSERT INTO COMPANY(ID,NAME,AGE,ADDRESS,SALARY) VALUES (1, 'Paul', 32, 'California', 20000.00);​";
    rc = sqlite3_exec( db, sqlInsert.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "********************** Records created successfully ********************** \n");
    }

    sqlInsert = "INSERT INTO COMPANY(ID,NAME,AGE,ADDRESS,SALARY) VALUES (2, 'Allen', 25, 'Texas', 15000.00 );";
    rc = sqlite3_exec( db, sqlInsert.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "********************** Records created successfully **********************\n");
    }

    sqlInsert = "INSERT INTO COMPANY(ID,NAME,AGE,ADDRESS,SALARY) VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );";
    rc = sqlite3_exec( db, sqlInsert.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "********************** Records created successfully ********************** \n");
    }

    sqlInsert = "INSERT INTO COMPANY(ID,NAME,AGE,ADDRESS,SALARY) VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
    rc = sqlite3_exec( db, sqlInsert.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "********************** Records created successfully **********************\n");
    }

    sqlSelect = "SELECT * from COMPANY";
    rc = sqlite3_exec(db, sqlSelect.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "********************** SELECT Operation done successfully **********************\n");
    }

    sqlUpdate = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
        "SELECT * from COMPANY";
    rc = sqlite3_exec(db, sqlUpdate.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "********************** UPDATE Operation done successfully **********************\n");
    }

    sqlDelete = "DELETE from COMPANY where ID=2; " \
        "SELECT * from COMPANY";
    rc = sqlite3_exec(db, sqlDelete.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "DELETE Operation done successfully\n");
    }

    sqlite3_close(db);
    return 0;  
}