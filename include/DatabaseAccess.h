
#pragma once
#include <pqxx/pqxx>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Ver https://code.visualstudio.com/docs/languages/cpp cuando haya problemas con paths

class DatabaseAccessLib
{
    pqxx::connection *conn;

    bool TryExecuteCommand(const std::string &SQL, pqxx::result &result);
    
public:

    DatabaseAccessLib(std::string DATABASE, std::string USERNAME, std::string PASSWORD, std::string HOST, int PORT);
    ~DatabaseAccessLib();
    
    bool ExecuteCommand(const std::string &SQL);

    static void Run();

    static int Test1() { return 1; }
    static int Test2() { return 2; }
};