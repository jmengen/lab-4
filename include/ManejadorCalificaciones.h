#ifndef MANEJADORCALIFICACIONES_H
#define MANEJADORCALIFICACIONES_H
#include "Calificacion.h"
#include "Reserva.h"
#include "DTFecha.h"
#include <map>
#include <list>
using namespace std;

class ManejadorCalificaciones
{
private:
    static ManejadorCalificaciones *instancia;
    map<string, list<Calificacion*>> CalificacionRecibidas;
    ManejadorCalificaciones() = default;
    
public:
    static ManejadorCalificaciones* getInstance();
    Calificacion * crearCalificacion(DTFecha fecha, int puntaje, Usuario* uRealiza, Usuario* uCalificado, Reserva* r);
    bool existeCalifEntre(Usuario* uRealiza, Usuario* uCalificado, int codigoViaje);

    ~ManejadorCalificaciones();
};

#endif 