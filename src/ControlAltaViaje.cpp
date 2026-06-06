#include "../include/ControlAltaViaje.h"
#include "../include/Usuario.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/DTVehiculosConductor.h"
#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include <set>

ControlAltaViaje* ControlAltaViaje::instancia = nullptr;

ControlAltaViaje * ControlAltaViaje::getInstance(){
    if(instancia == nullptr){
        instancia = new ControlAltaViaje();
    }
    return instancia;
}

std::set<DTVehiculosConductor> ControlAltaViaje::listarVehiculosConductor(std::string nickname){
    std::set<DTVehiculosConductor> res ;
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    Conductor* c = m->getConductor(nickname);
    if (c != nullptr){
        res = c->listarVehiculos();
    }
    return res;
}

bool ControlAltaViaje::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
    ManejadorVehiculos* mvh = ManejadorVehiculos::getInstancia();
    Vehiculo* v = mvh->getVehiculo(matricula);

    if (v == nullptr) {
        return false;
    }

    if (v->getCapacidad() < asientos) {
        return false;
    }

    if (v->hayViajesConductor(fecha)) {
        return false;
    }

    ManejadorViajes* cvi = ManejadorViajes::getInstance();
    Viaje* viaje = cvi->crearViaje(fecha, origen, destino, asientos, precio, v);

    v->asociarViaje(viaje);

    return true;
}


