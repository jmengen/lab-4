#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include "Usuario.h"
#include "TipoLibreta.h"
#include "Vehiculo.h"
#include "TipoVehiculo.h"
#include <set>
#include <map>

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::map<std::string, Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    std::set<TipoLibreta> getLibretas() const;
    TipoUsuario getTipoUsuario() const;
    bool puedeManejar(TipoVehiculo tipo) const;
    void linkVehiculo(Vehiculo* v);

    ~Conductor();
};

#endif
