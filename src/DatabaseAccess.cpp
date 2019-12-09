#include <tuple>
#include "DatabaseAccess.h"

DatabaseAccessLib::DatabaseAccessLib(std::string DATABASE, std::string USERNAME, std::string PASSWORD, std::string HOST = "localhost", int PORT = 5432)
{
    std::cout << "Constructor con parámetros" << std::endl;

    auto ss = std::stringstream();
    ss << "host=" << HOST << " port=" << PORT << " dbname=" << DATABASE << " user=" << USERNAME << " password=" << PASSWORD;
    auto connection_string = ss.str();

    this->conn = new pqxx::connection(connection_string);
    this->work = new pqxx::work(*this->conn);
}

DatabaseAccessLib::~DatabaseAccessLib()
{
    if (this->conn != NULL)
    {
        std::cout << "Cerrando conexión con MySQL" << std::endl;
        try
        {
            delete this->work;
            delete this->conn;
        }
        catch (const std::exception &e)
        {
            std::cerr << "DatabaseAccessLib::~DatabaseAccessLib - Exception - " << e.what() << '\n';
        }
    }
}

bool DatabaseAccessLib::ExecuteCommand(const std::string SQL)
{

    try
    {
        pqxx::result result = this->work->exec(SQL);

        for (auto row : result)
        {
            for (auto col : row)
            {
                std::cout  << col << "," ;
            }
            std::cout  << std::endl ;
        }
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "DatabaseAccessLib::~DatabaseAccessLib - Exception - " << e.what() << '\n';
        return false;
    }
        
    return true;
}

void DatabaseAccessLib::Run()
{
    DatabaseAccessLib database("MarketData", "hector", "burbuja");
    database.ExecuteCommand("SELECT * FROM emisoras;");
}
