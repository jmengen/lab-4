#include "../include/ManejadorUsuarios.h"

ManejadorUsuarios* ManejadorUsuarios::instancia = nullptr;

ManejadorUsuarios *ManejadorUsuarios::getInstance(){
    if(instancia == nullptr){
        instancia = new ManejadorUsuarios();
    }
    return instancia;
}

void ManejadorUsuarios::liberarInstancia() {
    delete instancia;
    instancia = nullptr;
}

ManejadorUsuarios::~ManejadorUsuarios() {
    for (std::map<std::string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
}

bool ManejadorUsuarios::existeUsuario(std::string nickname){
    return this->usuarios.find(nickname) != this->usuarios.end();
}

void ManejadorUsuarios::crearPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci){
    if (existeUsuario(nickname))
        return;
    else{
        Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);
        this->usuarios[nickname] = p;
    }
}

void ManejadorUsuarios::crearConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs){
    if (existeUsuario(nickname))
        return;
    else{
        Conductor* c = new Conductor(nickname,nombre,contrasena,email,libs);
        this->usuarios[nickname] = c;
    }
}

Usuario* ManejadorUsuarios::getUsuario(std::string nickname){
    if (existeUsuario(nickname))
        return this->usuarios[nickname];
    else 
        return nullptr;
}

std::set<Pasajero*> ManejadorUsuarios::getPasajeros(){
    std::set<Pasajero*> ret;
    std::map <std::string, Usuario*>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it){
        Usuario * puntus = it->second;
        if (puntus->getTipoUsuario() == TipoPasajero){
            ret.insert(static_cast<Pasajero*>(puntus)); 
        }
    }

    return ret;
}

Pasajero* ManejadorUsuarios::getPasajero(std::string nickname){
    Usuario* u = getUsuario(nickname);
    if (u==nullptr)
        return nullptr;
    else if (u->getTipoUsuario() == TipoPasajero)
        return static_cast<Pasajero*>(u);
    else 
        return nullptr;
}

Conductor* ManejadorUsuarios::getConductor(std::string nickname){
    Usuario* u = getUsuario(nickname);
    if (u==nullptr)
        return nullptr;
    else if (u->getTipoUsuario() == TipoConductor)
        return static_cast<Conductor*>(u);
    else 
        return nullptr;
}

std::set<Usuario*> ManejadorUsuarios::getUsuarios(){
    std::set<Usuario*> ret;
    std::map <std::string, Usuario*>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it){
        Usuario * puntus = it->second;
        ret.insert(puntus); 
    }
    return ret;
}
        
