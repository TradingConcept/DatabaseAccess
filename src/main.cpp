#include <iostream>

#include "DatabaseAccess.h"

int main(int argc, char *argv[])
{
    std::cout << "Inicializando Servicio..." << std::endl;
    
    DatabaseAccessLib::Run();

    std::cout << "Finalizando Servicio..." << std::endl;

    return 0;
}
