#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <string>

#include "DTFecha.h"

class Usuario;
class Reserva;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* usuarioRealiza;
    Usuario* usuarioCalificado;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int puntaje, Usuario* uCalificado, Usuario* uRealiza, Reserva* Reserva);
    int getPuntaje() const;
    bool esCalif(std::string uRealiza, std::string uCalificado);

    bool esCalifEntre(Usuario* uRealiza, Usuario* uCalificado, int codigoViaje);

    ~Calificacion();
    void eliminarCalificacion();
};

#endif
