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

void ControlCalificarUsuario::liberarInstancia() {
    delete instancia;
    instancia = nullptr;
}


set<DTUsuario> ControlCalificarUsuario::listarUsuarios(){
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
    if (U == nullptr) {
        this->nickRecordado = "";
        return {};
    }

    this->nickRecordado = nickname;
    return U->obtenerDTListarViaje();
}

set<DTUsuarioViaje> ControlCalificarUsuario::listarUsuariosViaje(int codigo){
    ManejadorViajes* m = ManejadorViajes::getInstance();
    Viaje* vi = m->getViaje(codigo);
    if (vi == nullptr || this->nickRecordado.empty()) {
        this->codRecordado = -1;
        return {};
    }

    this->codRecordado = codigo;
    return vi->obtenerParticipantes(this->nickRecordado);
}

bool ControlCalificarUsuario::calificarUsuario(string nicknameCalificado, int calificacion){
    if (calificacion < 1 || calificacion > 5 || this->nickRecordado.empty() || this->codRecordado < 0) {
        return false;
    }

    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    Usuario* uRealiza = m->getUsuario(this->nickRecordado);
    Usuario* uCalificado = m->getUsuario(nicknameCalificado);
    ManejadorViajes* v = ManejadorViajes::getInstance();
    Viaje* vi = v->getViaje(this->codRecordado);
    if (uRealiza == nullptr || uCalificado == nullptr || vi == nullptr || uRealiza == uCalificado) {
        return false;
    }

    set<DTUsuarioViaje> participantes = vi->obtenerParticipantes(this->nickRecordado);
    bool participaEnViaje = false;
    for (set<DTUsuarioViaje>::iterator it = participantes.begin(); it != participantes.end(); ++it) {
        if (it->getNickname() == nicknameCalificado) {
            participaEnViaje = true;
            break;
        }
    }
    if (!participaEnViaje) {
        return false;
    }

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
        if (r == nullptr) {
            return false;
        }

        c->crearCalificacion(fecha, calificacion, uRealiza, uCalificado, r);

        this->nickRecordado = "";
        this->codRecordado = -1;

        return true;
    }
}
