#ifndef FABRICA_H
#define FABRICA_H

#include "IControlAltaUsuario.h"
#include "IControladorFechaActual.h"
#include "IControlAltaViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();
public:
    static Fabrica* getInstance();
    IControlAltaUsuario* getIControlAltaUsuario();
    IControladorFechaActual* getIControladorFechaActual();
    IControlAltaViaje* getIControlAltaViaje();
};

#endif
