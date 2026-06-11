#include "../include/ManejadorVehiculos.h"

ManejadorVehiculos* ManejadorVehiculos::instancia = nullptr;


ManejadorVehiculos *ManejadorVehiculos::getInstancia(){
    if (instancia == nullptr){
        instancia = new ManejadorVehiculos;
    }
    return instancia; 
}

bool ManejadorVehiculos::existeVehiculo(std::string matricula){
    return this->vehiculos.find(matricula) != this->vehiculos.end();
}

Vehiculo* ManejadorVehiculos::crearVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
    if (existeVehiculo(matricula))
        return nullptr;
    else{
        Vehiculo* ve = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
        this->vehiculos[matricula] = ve;
        return ve;
    }
}

Vehiculo* ManejadorVehiculos::getVehiculo(std::string matricula){
    std::map<std::string, Vehiculo*>::iterator it = this->vehiculos.find(matricula);
    if (it == this->vehiculos.end()) {
        return nullptr;
    }
    return it->second;
}
