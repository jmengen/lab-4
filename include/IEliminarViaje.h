#ifndef ICONTROL_ELIMINAR_VIAJE_H
#define ICONTROL_ELIMINAR_VIAJE_H

#include "DTListarViaje.h"
#include <set>
#include "DTDetalleViaje.h"

class IEliminarViaje {
    public:
    virtual std::set<DTListarViaje>listarViajes();
    virtual DTDetalleViaje detalleViaje(int codigo);
    virtual void eliminarViaje();
    virtual void cancelarEliminarViaje();
    virtual ~IEliminarViaje() {}
};


#endif