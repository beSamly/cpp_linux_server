#include "PostgresDB.h"
#include <iostream>
#include <pqxx/pqxx>
#include <string>

void PostgresDB::Init() {

    try {
        // Connect to the database
        pqxx::connection c(
                "user=postgres password=postgres host=localhost port=5432 dbname=postgres target_session_attrs=read-write");

        // Start a transaction
        pqxx::work w(c);
        pqxx::result rows = w.exec("SELECT * FROM Accounts;");
        for (int i = 0; i < rows.size(); i++) {

        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
}
