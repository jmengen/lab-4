#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include "TipoUsuario.h"
#include <string>

class DTUsuario {
private:
    std::string nickname;
    std::string nombre;
    TipoUsuario tipo;

public:
    DTUsuario(std::string nickname, std::string nombre, TipoUsuario tipo);
    bool operator<(const DTUsuario& otra) const;

    std::string getNickname() const;
    std::string getNombre() const;
};

#endif
