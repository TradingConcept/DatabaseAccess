#pragma once
#include <mysql.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Ver https://code.visualstudio.com/docs/languages/cpp cuando haya problemas con paths

class DatabaseAccessLib
{

    std::string HOSTNAME;
    std::string DATABASE;
    std::string USERNAME;
    std::string PASSWORD;
    const char* SOCKET;

    const int PORT = 3306;
    const int OPT = 0;

    MYSQL *conn;

public:
    DatabaseAccessLib(std::string, std::string, std::string, std::string);
    DatabaseAccessLib();
    ~DatabaseAccessLib();

    void Run();
    bool ExecuteCommand(const std::string, std::vector<std::string>&);

    static int Test1() { return 1; }
    static int Test2() { return 2; }
};