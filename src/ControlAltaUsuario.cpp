#include "../include/ControlAltaUsuario.h"
using namespace std;

bool ControlAltaUsuario::altaPasajero(string nickname, string nombre, string contrasena, string email, string ci){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    if (m->existeUsuario(nickname))
        return false;
    else{
        m->crearPasajero(nickname,nombre,contrasena,email,ci);
        return true;
    }
}

bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libs){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    if (m->existeUsuario(nickname))
        return false;
    else{
        m->crearConductor(nickname,nombre,contrasena,email,libs);
        return true;
    }
}

int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    Usuario* c = m->getUsuario(nickname);
    



}