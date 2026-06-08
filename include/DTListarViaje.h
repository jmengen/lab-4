#ifndef DT_LISTAR_VIAJE_H
#define DT_LISTAR_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTListarViaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    std::string conductor;

public:
    DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string conductor);

    int getCodigo() const;
    DTFecha getFecha() const;
    std::string getOrigen() const;
    std::string getDestino() const;
    std::string getConductor() const;
    bool operator<(const DTListarViaje& otro) const;

};

#endif
