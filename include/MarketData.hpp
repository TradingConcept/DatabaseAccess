#pragma once
#include <string>
#include <pqxx/pqxx>

namespace MarketData
{

class Emisoras
{

public:
    std::string Emisora;
    std::string Serie;
    int Cupon;
    std::string Tipo_Valor;

    inline Emisoras(const std::string &emisora, const std::string &serie, int cupon, const std::string &tipo_valor) : Emisora(emisora), Serie(serie), Cupon(cupon), Tipo_Valor(tipo_valor){};
    inline Emisoras(const pqxx::row &row) : Emisora(row[0].c_str()), Serie(row[1].c_str()), Cupon(row[2].as<int>()), Tipo_Valor(row[3].c_str()){};    

}; // namespace MarketData

} // namespace MarketData