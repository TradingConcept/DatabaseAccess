#include <tuple>
#include "DatabaseAccess.h"
#include "MarketData.hpp"

DatabaseAccessLib::DatabaseAccessLib(std::string DATABASE, std::string USERNAME, std::string PASSWORD, std::string HOST = "localhost", int PORT = 5432)
{
    std::cout << "Constructor con parámetros" << std::endl;

    auto ss = std::stringstream();
    ss << "host=" << HOST << " port=" << PORT << " dbname=" << DATABASE << " user=" << USERNAME << " password=" << PASSWORD;
    auto connection_string = ss.str();

    this->conn = new pqxx::connection(connection_string);
}

DatabaseAccessLib::~DatabaseAccessLib()
{
    if (this->conn != NULL)
    {
        std::cout << "Cerrando conexión con SQL" << std::endl;
        try
        {
            delete this->conn;
        }
        catch (const std::exception &e)
        {
            std::cerr << "DatabaseAccessLib::~DatabaseAccessLib - Exception - " << e.what() << '\n';
        }
    }
}

bool DatabaseAccessLib::TryExecuteCommand(const std::string &SQL, pqxx::result &result)
{
    try
    {
        pqxx::work work(*this->conn);
        result = work.exec(SQL);
        work.commit();
    }
    catch (const std::exception &e)
    {
        std::cerr << "DatabaseAccessLib::~DatabaseAccessLib - Exception - " << e.what() << '\n';
        return false;
    }
    return true ;
}

bool DatabaseAccessLib::ExecuteCommand(const std::string &SQL)
{
    pqxx::result result;
    if (this->TryExecuteCommand(SQL, result))
    {
        for (auto row : result)
        {
            MarketData::Emisoras emisora(row);
            std::cout << emisora.Emisora << "." << emisora.Serie << " " << emisora.Cupon << " " << emisora.Tipo_Valor << std::endl;
        }
        return true;
    }
    return false;
}

void DatabaseAccessLib::Run()
{
    DatabaseAccessLib database("MarketData", "hector", "burbuja");
    database.ExecuteCommand("SELECT * FROM emisoras;");
}
