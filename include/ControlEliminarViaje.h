#ifndef CONTROL_ELIMINAR_VIAJE_H
#define CONTROL_ELIMINAR_VIAJE_H

#include "DTListarViaje.h"
#include <set>
#include "DTDetalleViaje.h"
#include "IEliminarViaje.h"

class ControlEliminarViaje : public IEliminarViaje {
    private:
        static ControlEliminarViaje* instancia;
        ControlEliminarViaje() = default;
        int codigoRecordado = -1;
    public:
        static ControlEliminarViaje* getInstance();

        std::set<DTListarViaje>listarViajes();
        DTDetalleViaje detalleViaje(int codigo);
        void eliminarViaje();
        void cancelarEliminarViaje();
};

#endif
