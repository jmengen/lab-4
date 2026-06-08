#include "../include/ControlEliminarViaje.h"
#include "DTListarViaje.h"
#include <set>
#include "DTDetalleViaje.h"
#include "../include/ManejadorViaje.h"
#include "Viaje.h"

std::set<DTListarViaje> ControlEliminarViaje::listarViajes(){
    ManejadorViajes* m = ManejadorViajes::getInstance();
    return m->getDTListarViajes();
}

DTDetalleViaje ControlEliminarViaje::detalleViaje(int codigo){
    this->codigoRecordado = codigo;

    ManejadorViajes *m = ManejadorViajes::getInstance();
    Viaje* v = m->getViaje(codigo);
    return v->getDTDetalleViaje();
}

void ControlEliminarViaje::eliminarViaje(){
}

void ControlEliminarViaje::cancelarEliminarViaje(){
}
