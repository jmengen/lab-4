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

void ManejadorVehiculos::crearVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo){
    if (existeVehiculo(matricula))
        return;
    else{
        Vehiculo* ve = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
        this->vehiculos.insert({matricula,ve});
    }
}