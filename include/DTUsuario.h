#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <string>

class DTUsuario {
private:
    std::string nickname;
    std::string nombre;

public:
    DTUsuario(std::string nickname, std::string nombre);
    bool operator<(const DTUsuario& otra) const;

    std::string getNickname();
    std::string getNombre();
};

#endif
