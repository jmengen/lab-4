#ifndef MENU_H
#define MENU_H

#include "IControlAltaUsuario.h"
#include "IControlAltaViaje.h"
#include "IControlGenerarReserva.h"
#include "IControlCalificarUsuario.h"
#include "IEliminarViaje.h"
#include "IControladorFechaActual.h"

class Menu {
private:
    IControlAltaUsuario* controlAltaUsuario;
    IControlAltaViaje* controlAltaViaje;
    IControlGenerarReserva* controlGenerarReserva;
    IControlCalificarUsuario* controlCalificarUsuario;
    IEliminarViaje* controlEliminarViaje;
    IControladorFechaActual* controlFechaActual;

    void altaUsuario();
    void altaViaje();
    void generarReserva();
    void calificarUsuario();
    void eliminarViaje();
    void administrarFechaActual();
    void cargarDatos();

public:
    Menu(
        IControlAltaUsuario* controlAltaUsuario,
        IControlAltaViaje* controlAltaViaje,
        IControlGenerarReserva* controlGenerarReserva,
        IControlCalificarUsuario* controlCalificarUsuario,
        IEliminarViaje* controlEliminarViaje,
        IControladorFechaActual* controlFechaActual
    );

    void mostrarMenu();
};

#endif
