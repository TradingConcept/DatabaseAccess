#include <iostream>

#include "DatabaseAccessLib.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Inicializando Servicio..." << std::endl;

    DatabaseAccessLib database;
    database.Run();

    std::cout << "Finalizando Servicio..." << std::endl;

    return 0;
}
