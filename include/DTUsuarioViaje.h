#ifndef DT_USUARIO_VIAJE_H
#define DT_USUARIO_VIAJE_H

#include "TipoUsuario.h"
#include <string>

class DTUsuarioViaje {
private:
    std::string nickname;
    TipoUsuario tipo;
    int orden;

public:
    DTUsuarioViaje(std::string nickname, TipoUsuario tipo, int orden = 0);
    bool operator<(const DTUsuarioViaje& otra) const;

    std::string getNickname() const;
    TipoUsuario getTipo() const;
};

#endif
