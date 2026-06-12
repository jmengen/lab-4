#ifndef CONTROLALTAUSUARIO_H
#define CONTROLALTAUSUARIO_H
#include "IControlAltaUsuario.h"
#include "ManejadorUsuarios.h"
#include "ManejadorVehiculos.h"
#include <iostream>

class ControlAltaUsuario : public IControlAltaUsuario{
    private:
        static ControlAltaUsuario * instancia;
        ControlAltaUsuario() = default;

    public:
        static ControlAltaUsuario * getInstance();
        static void liberarInstancia();

        bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
        bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libs);
        int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo);
};

#endif
