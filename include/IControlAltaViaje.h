#ifndef ICONTROL_ALTA_VIAJE_H
#define ICONTROL_ALTA_VIAJE_H

#include <set>
#include <string>
#include "DTFecha.h"
#include "DTVehiculosConductor.h"

class IControlAltaViaje {
public:
    virtual std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname) = 0;
    virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0;
    virtual ~IControlAltaViaje() {}
};

#endif