#pragma once
#include <sql.h>
#include <sqlext.h>

class DBConnection {

public:
    void Init();

    void CreateStatement();
    void AnotherExample();
    void ExtractError(std::string fn, SQLHANDLE handle, SQLSMALLINT type);
};

