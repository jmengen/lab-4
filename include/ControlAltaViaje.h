#ifndef CONTROL_ALTA_VIAJE_H
#define CONTROL_ALTA_VIAJE_H
#include "IControlAltaViaje.h"
#include "DTVehiculosConductor.h"
#include "DTFecha.h"
#include <string>
#include <set>
#include "ManejadorVehiculos.h"
#include "ManejadorViajes.h"

class ControlAltaViaje : public IControlAltaViaje {
    private:
        static ControlAltaViaje * instancia;
        ControlAltaViaje() = default;

    public:
        static ControlAltaViaje * getInstance();

        std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
        bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino , int asientos, float precio);
};
#endif
