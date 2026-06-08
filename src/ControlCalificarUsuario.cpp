#include "../include/ControlCalificarUsuario.h"
#include "../include/ControladorFechaActual.h"
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
    this->codRecordado = codigo;
    return vi->obtenerParticipantes(this->nickRecordado);
}

bool ControlCalificarUsuario::calificarUsuario(string nicknameCalificado, int calificacion){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    Usuario* uRealiza = m->getUsuario(this->nickRecordado);
    Usuario* uCalificado = m->getUsuario(nicknameCalificado);
    ManejadorViajes* v = ManejadorViajes::getInstance();
    Viaje* vi = v->getViaje(this->codRecordado);

    ManejadorCalificaciones* c = ManejadorCalificaciones::getInstance();
    bool cond = c->existeCalifEntre(uRealiza, uCalificado, vi->getCodigo());

    if (cond){
        return false;
    } else {
        ControladorFechaActual* f = ControladorFechaActual::getInstance();
        DTFecha fecha = f->getFecha();

        ManejadorReservas* mr = ManejadorReservas::getInstance();
        Reserva * r;
        if (uRealiza->getTipoUsuario() == TipoPasajero){
            r = mr->obtenerReservaEntre(static_cast<Pasajero*>(uRealiza), vi);
        } else {
            r = mr->obtenerReservaEntre(static_cast<Pasajero*>(uCalificado), vi);
        }

        Calificacion * PuntCalif = c->crearCalificacion(fecha, calificacion, uRealiza, uCalificado, r);

        this->nickRecordado = "";
        this->codRecordado = 0;

        return true;
    }
}