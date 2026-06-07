#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <string>

#include "DTFecha.h"
class Usuario;
class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* usuarioRealiza;
    Usuario* usuarioCalificado;

public:
    Calificacion(DTFecha fecha, int puntaje, Usuario* uCalificado,Usuario* uRealiza);
    int getPuntaje() const;
    bool esCalif(std::string uRealiza, std::string uCalificado);
    ~Calificacion();
};

#endif
