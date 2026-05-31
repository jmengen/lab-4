#include "../include/ManejadorUsuarios.h"

ManejadorUsuarios* ManejadorUsuarios::instancia = nullptr;

    ManejadorUsuarios *ManejadorUsuarios::getInstance(){
        if(instancia == nullptr){
            instancia = new ManejadorUsuarios();
        }
        return instancia;
    }

    bool ManejadorUsuarios::existeUsuario(std::string nickname){
        return this->usuarios.find(nickname) != this->usuarios.end();
    }

    void ManejadorUsuarios::crearPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci){
        if (existeUsuario(nickname))
            return;

        else{
            Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);
            this->usuarios.insert ({nickname,p});

        }
    }

    void ManejadorUsuarios::crearConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs){
        if (existeUsuario(nickname))
            return;
        else{
            Conductor* c = new Conductor(nickname,nombre,contrasena,email,libs);
            this->usuarios.insert({nickname,c});
        }
    }

    Usuario* ManejadorUsuarios::getUsuario(std::string nickname){
        if (existeUsuario(nickname)){
            return this->usuarios[nickname];
        }
    }