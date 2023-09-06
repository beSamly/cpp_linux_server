//
// Created by admin on 4/09/2023.
//
#include <sql.h>
#include <iostream>
#include <sqlext.h>
#include <spdlog/spdlog.h>
#include "DBConnection.h"
#include <string>

#define MAX_PATH          260

using std::wstring;

void DBConnection::Init() {
    CreateStatement();
    AnotherExample();
}

void DBConnection::CreateStatement() {

}

void DBConnection::AnotherExample() {

}

void DBConnection::ExtractError(
        std::string fn,
        SQLHANDLE handle,
        SQLSMALLINT type

) {

}
