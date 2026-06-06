#ifndef USUARIO_H
#define USUARIO_H
#include "TipoUsuario.h"
#include "Calificacion.h"
#include "DTUsuario.h"
#include "DTListarViaje.h"
#include <string>
#include <set>

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    float calificacionPromedio;

    std::set<Calificacion> realiza;
    std::set<Calificacion> califica;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual TipoUsuario getTipoUsuario() const = 0;
    std::string getNickname() const; 
    std::string getNombre() const;
    std::string getContrasena() const;
    std::string getEmail() const;
    float getCalificacion();

    DTUsuario getDTUsuario() const;
    virtual std::set<DTListarViaje> obtenerDTListarViaje() = 0;
    
    virtual ~Usuario();
};

#endif
