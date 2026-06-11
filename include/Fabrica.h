#ifndef FABRICA_H
#define FABRICA_H

#include "IControlAltaUsuario.h"
#include "IControlAltaViaje.h"
#include "IControlGenerarReserva.h"
#include "IControlCalificarUsuario.h"
#include "IEliminarViaje.h"
#include "IControladorFechaActual.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstance();

    IControlAltaUsuario* getIControlAltaUsuario();
    IControlAltaViaje* getIControlAltaViaje();
    IControlGenerarReserva* getIControlGenerarReserva();
    IControlCalificarUsuario* getIControlCalificarUsuario();
    IEliminarViaje* getIEliminarViaje();
    IControladorFechaActual* getIControladorFechaActual();
};

#endif