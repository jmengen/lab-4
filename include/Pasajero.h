#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>
#include "../include/Reserva.h"
#include <set>

class Pasajero : public Usuario {
private:
    std::string ci;
    std::set<Reserva> *reservas;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    std::string getCi() const;
    TipoUsuario getTipoUsuario() const override;
    void asociarReserva(Reserva* res);

    std::set<DTListarViaje> obtenerDTListarViaje() override;
    
    ~Pasajero();
};
#endif
