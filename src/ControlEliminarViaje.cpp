#include "../include/ControlEliminarViaje.h"
#include "../include/DTListarViaje.h"
#include "../include/DTDetalleViaje.h"
#include "../include/ManejadorViajes.h"
#include "../include/Viaje.h"
#include <set>

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
    ManejadorViajes* m = ManejadorViajes::getInstance();
    Viaje*v = m->getViaje(this->codigoRecordado);
    v->eliminarViaje();
    m->quitarViaje(this->codigoRecordado);
}

void ControlEliminarViaje::cancelarEliminarViaje(){
    this->codigoRecordado = -1;
}
