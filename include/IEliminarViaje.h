#ifndef ICONTROL_ELIMINAR_VIAJE_H
#define ICONTROL_ELIMINAR_VIAJE_H

#include <set>
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"

class IEliminarViaje {
public:
    virtual std::set<DTListarViaje> listarViajes() = 0;
    virtual DTDetalleViaje detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
    virtual ~IEliminarViaje() = default;
};

#endif