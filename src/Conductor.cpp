#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

std::set<TipoLibreta> Conductor::getLibretas() const{
    return this->libretas;
}

TipoUsuario Conductor::getTipoUsuario() const {
    return TipoConductor;
}

bool Conductor::puedeManejar(TipoVehiculo tipo) const {
    if (tipo == Auto) {
        return this->libretas.count(AutoProfesional) > 0 || this->libretas.count(AutoAmateur) > 0;
    }

    if (tipo == Moto) {
        return this->libretas.count(MotoProfesional) > 0 || this->libretas.count(MotoAmateur) > 0;
    }

    return false;
}


void Conductor::linkVehiculo(Vehiculo* v){
    std::string matricula = v->getMatricula();
    this->vehiculos.insert({matricula,v});
}

Conductor::~Conductor() {}

std::set<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::set<DTVehiculosConductor> resultado;
    std::map<std::string, Vehiculo*>::iterator it;

    for (it = this->vehiculos.begin(); it != this->vehiculos.end(); it++) {
        Vehiculo* v = it->second;
        resultado.insert(DTVehiculosConductor(v->getMatricula(), v->getModelo(), v->getCapacidad()));
    }

    return resultado;
}