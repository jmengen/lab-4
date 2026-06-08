#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Reserva;
class Usuario;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Reserva* reserva;
    Usuario* usuarioRealiza;
    Usuario* usuarioCalificado;
public:
    Calificacion(DTFecha fecha, int puntaje,Usuario* usuarioRealiza, Usuario*usuarioCalificado, Reserva* reserva);
    ~Calificacion();
    void eliminarCalificacion();
};

#endif
