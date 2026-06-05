#ifndef MANEJADORVEHICULOS_H
#define MANEJADORVEHICULOS_H
#include <iostream>
#include <string>
#include "Vehiculo.h"
#include <map>

class ManejadorVehiculos
{
private:
    static ManejadorVehiculos* instancia;
    std::map <std::string, Vehiculo*> vehiculos;
    ManejadorVehiculos() = default;
public:
    static ManejadorVehiculos* getInstancia();

    bool existeVehiculo(std::string matricula);
    Vehiculo* crearVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);

};


#endif