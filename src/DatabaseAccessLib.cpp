#include <tuple>
#include "DatabaseAccessLib.hpp"

DatabaseAccessLib::DatabaseAccessLib(std::string HOSTNAME, std::string DATABASE, std::string USERNAME, std::string PASSWORD)
{
    std::cout << "Constructor con parámetros" << std::endl;
    this->HOSTNAME = HOSTNAME;
    this->DATABASE = DATABASE;
    this->USERNAME = USERNAME;
    this->PASSWORD = PASSWORD;
    this->SOCKET = NULL;
}

DatabaseAccessLib::DatabaseAccessLib() : HOSTNAME("localhost"), DATABASE("MarketData"), USERNAME("root"), PASSWORD("sourcefile"), SOCKET(NULL)
{
    std::cout << "Constructor por default" << std::endl;
}

DatabaseAccessLib::~DatabaseAccessLib()
{
    if (this->conn != NULL)
    {
        std::cout << "Cerrando conexión con MySQL" << std::endl;
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

bool DatabaseAccessLib::ExecuteCommand(const std::string SQL, std::vector<std::string> &data)
{
    if (mysql_query(this->conn, "SHOW TABLES"))
    {
        std::cerr << "DatabaseAccessLib::Run - mysql_query error - " << mysql_error(this->conn) << std::endl;
        return false;
    }
    else
    {
        std::cerr << "DatabaseAccessLib::Run - mysql_query OK" << std::endl;
    }

    auto result = mysql_use_result(this->conn);
    auto row = mysql_fetch_row(result);

    while (row != NULL)
    {
        data.push_back(row[0]);
        row = mysql_fetch_row(result);
    }

    mysql_free_result(result);

    return true;
    ;
}

void DatabaseAccessLib::Run()
{
    std::cout << "DatabaseAccess Run " << this->HOSTNAME << ":" << this->DATABASE << "@" << this->DATABASE << std::endl;

    this->conn = mysql_init(NULL);

    try
    {

        if (mysql_real_connect(this->conn, this->HOSTNAME.c_str(), this->USERNAME.c_str(), this->PASSWORD.c_str(), this->DATABASE.c_str(), this->PORT, this->SOCKET, 0))
        {
            std::cerr << "DatabaseAccessLib::Run - mysql_real_connect OK" << std::endl;
        }
        else
        {
            std::cerr << "DatabaseAccessLib::Run - mysql_real_connect error - " << mysql_error(this->conn) << std::endl;
            return;
        }

        std::vector<std::string> data;
        if (this->ExecuteCommand("SHOW TABLES", data))
        {
            for (auto variable : data)
            {
                std::cout << "  " << variable << std::endl;
            }
        }

        mysql_close(this->conn);
        this->conn = NULL;
    }
    catch (const std::exception &e)
    {
        std::cerr << "DatabaseAccessLib::Run - Exception - " << e.what() << '\n';
    }
}
