#include "../include/ControlAltaUsuario.h"
using namespace std;

ControlAltaUsuario* ControlAltaUsuario::instancia = nullptr;

ControlAltaUsuario *ControlAltaUsuario::getInstance(){
    if(instancia == nullptr){
        instancia = new ControlAltaUsuario();
    }
    return instancia;
}

void ControlAltaUsuario::liberarInstancia() {
    delete instancia;
    instancia = nullptr;
}

bool ControlAltaUsuario::altaPasajero(string nickname, string nombre, string contrasena, string email, string ci){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    if (m->existeUsuario(nickname))
        return false;
    else{
        m->crearPasajero(nickname,nombre,contrasena,email,ci);
        return true;
    }
}

bool ControlAltaUsuario::altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libs){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    if (m->existeUsuario(nickname))
        return false;
    else{
        m->crearConductor(nickname,nombre,contrasena,email,libs);
        return true;
    }
}

int ControlAltaUsuario::registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    Conductor* c = m->getConductor(nickname);
    if (c == nullptr || capacidad <= 0) {
        return -2;
    }

    ManejadorVehiculos* v = ManejadorVehiculos::getInstancia();
    if (!v->existeVehiculo(matricula)){
        if (c->puedeManejar(tipo)){
            Vehiculo* ve = v->crearVehiculo(matricula, capacidad, marca, modelo, tipo);
            c->linkVehiculo(ve);
            ve->setConductor(c);
            return 0;
        }
        else 
            return (-2);
    }
    else return (-1);
}
