#include <iostream>
#include <sqlite3.h>

int main(int argc, char **argv)
{
	sqlite3* DB;
	std::string sql = "CREATE TABLE PERSON("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "SURNAME 		 TEXT	 NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";
    int exit = 0;
    exit = sqlite3_open("example.db", &DB);
    char* messaggeError;
	if(exit)
	{
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return(-1);
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

	if(exit != SQLITE_OK)
	{
		std::cerr << "Error Create Table" << std::endl;
		sqlite3_free(messaggeError);
	}
	else
		std::cout << "Table created Successfully" << std::endl;

	sql = "INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);" \
	"INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);" \
	"INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);";

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if(exit != SQLITE_OK)
	{
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messaggeError);
	}
	else
		std::cout << "Records created Successfully!" << std::endl;


	sql = "DELETE FROM PERSON WHERE ID = 2;";
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if(exit != SQLITE_OK)
	{
		std::cerr << "Error DELETE" << std::endl;
		sqlite3_free(messaggeError);
	}
	else
		std::cout << "Record deleted Successfully!" << std::endl;


	sqlite3_close(DB);
	return(0);
}