#ifndef IALTAUSUARIO_H
#define IALTAUSUARIO_H
#include <iostream>
#include <string>
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include <set>
using namespace std;




class IAltaUsuario{
    public:
        virtual bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) = 0;
        virtual bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libs) = 0;
        virtual int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo) = 0;
        virtual ~IAltaUsuario() = default;
};


#endif