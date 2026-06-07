#include "../include/ControlCalificarUsuario.h"
using namespace std;


ControlCalificarUsuario* ControlCalificarUsuario::instancia = nullptr;

ControlCalificarUsuario * ControlCalificarUsuario::getInstance(){
    if(instancia == nullptr){
        instancia = new ControlCalificarUsuario();
    }
    return instancia;
}


set<DTUsuario> ControlCalificarUsuario::ListarUsuarios(){
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    set<Usuario*> usuarios = mu->getUsuarios();
    set<Usuario*>::iterator it;
    set<DTUsuario> res;
    for (it = usuarios.begin(); it != usuarios.end(); ++it){
        Usuario* actual = *it;
        res.insert(actual->getDTUsuario());
    }    
    return res;
}

set<DTListarViaje> ControlCalificarUsuario::listarViajes(string nickname){
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    Usuario* U = mu->getUsuario(nickname);
    this->nickRecordado = nickname;
    return U->obtenerDTListarViaje();
}

set<DTUsuarioViaje> ControlCalificarUsuario::listarUsuariosViaje(int codigo){
    ManejadorViajes* m = ManejadorViajes::getInstance();
    Viaje* vi = m->getViaje(codigo);
    return vi->obtenerParticipantes(this->nickRecordado);
}

bool calificarUsuario(string nicknameCalificado, int calificacion){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    Usuario* uCalificado = m->getUsuario(nicknameCalificado);
    return false;
    //falta terminarlo
}