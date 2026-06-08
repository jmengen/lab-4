#ifndef CONTROL_ELIMINAR_VIAJE_H
#define CONTROL_ELIMINAR_VIAJE_H

#include "DTListarViaje.h"
#include <set>
#include "DTDetalleViaje.h"

class ControlEliminarViaje {
    private:
        int codigoRecordado = -1;
    public:
        std::set<DTListarViaje>listarViajes();
        DTDetalleViaje detalleViaje(int codigo);
        void eliminarViaje();
        void cancelarEliminarViaje();
};

#endif
