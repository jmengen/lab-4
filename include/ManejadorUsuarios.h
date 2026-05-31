#ifndef MANEJADORUSUARIOS_H
#define MANEJADORUSUARIOS_H
#include <iostream>
#include "Usuario.h"
#include "Pasajero.h"
#include "Conductor.h"
#include <string>
#include <map>
#include <set>


class ManejadorUsuarios {
    private:
        static ManejadorUsuarios* instancia;
        std::map <std::string, Usuario*> usuarios;
        ManejadorUsuarios() = default;

    public:
        static ManejadorUsuarios* getInstance();

        bool existeUsuario(std::string nickname);
        void crearPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
        void crearConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
        Usuario* getUsuario(std::string nickname);
};

#endif