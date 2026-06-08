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
    ManejadorViajes *m = ManejadorViajes::getInstance();
    Viaje* v = m->getViaje(codigo);
    this->codigoRecordado = codigo;
    return v->getDTDetalleViaje();
}

void ControlEliminarViaje::eliminarViaje(){
    if (this->codigoRecordado < 0) {
        return;
    }

    ManejadorViajes* m = ManejadorViajes::getInstance();
    Viaje* v = m->getViaje(this->codigoRecordado);
    if (v == nullptr) {
        this->codigoRecordado = -1;
        return;
    }

    v->eliminarViaje();
    m->quitarViaje(this->codigoRecordado);
    this->codigoRecordado = -1;
}

void ControlEliminarViaje::cancelarEliminarViaje(){
    this->codigoRecordado = -1;
}
