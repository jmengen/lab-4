#include "../include/ManejadorViajes.h"

ManejadorViajes* ManejadorViajes::instancia = nullptr;

ManejadorViajes *ManejadorViajes::getInstance(){
    if(instancia == nullptr){
        instancia = new ManejadorViajes();
    }
    return instancia;
}

std::set<Viaje> ManejadorViajes::getViajes(){
    return this->viajes;
}

bool ManejadorViajes::existeViaje(int codigo){
        return this->mapViajes.find(codigo) != this->mapViajes.end();
}

Viaje* ManejadorViajes::getViaje(int codigo){
    if (existeViaje(codigo))
        return this->mapViajes[codigo];
    else 
        return nullptr;
}
