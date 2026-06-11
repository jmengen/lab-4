#include "../include/Fabrica.h"
#include "../include/ControlAltaUsuario.h"
#include "../include/ControlAltaViaje.h"
#include "../include/ControlGenerarReserva.h"
#include "../include/ControlCalificarUsuario.h"
#include "../include/ControlEliminarViaje.h"
#include "../include/ControladorFechaActual.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControlAltaUsuario* Fabrica::getIControlAltaUsuario() {
    return ControlAltaUsuario::getInstance();
}

IControlAltaViaje* Fabrica::getIControlAltaViaje() {
    return ControlAltaViaje::getInstance();
}

IControlGenerarReserva* Fabrica::getIControlGenerarReserva() {
    return ControlGenerarReserva::getInstance();
}

IControlCalificarUsuario* Fabrica::getIControlCalificarUsuario() {
    return ControlCalificarUsuario::getInstance();
}

IEliminarViaje* Fabrica::getIEliminarViaje() {
    return ControlEliminarViaje::getInstance();
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}