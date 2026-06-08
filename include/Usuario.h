#ifndef USUARIO_H
#define USUARIO_H
#include "TipoUsuario.h"
#include <string>
#include <set>

class Calificacion;

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::set<Calificacion*> calificacion;
public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual TipoUsuario getTipoUsuario() const = 0;
    std::string getNickname() const; 
    std::string getNombre() const;
    std::string getContrasena() const;
    std::string getEmail() const;
    
    virtual ~Usuario();
    void quitarCalificacion(Calificacion* c);
};

#endif
