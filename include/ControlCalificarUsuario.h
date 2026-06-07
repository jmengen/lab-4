#ifndef CONTROLCALIFICARUSUARIO_H
#define CONTROLCALIFCARUSUARIO_H
#include "IControlCalificarUsuario.h"
#include "ManejadorUsuarios.h"
#include "ManejadorViajes.h"
#include "ManejadorCalificaciones.h"
#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include <set>
using namespace std;

class ControlCalificarUsuario{
    private:
        static ControlCalificarUsuario * instancia;
        ControlCalificarUsuario() = default;

    public:
        static ControlCalificarUsuario * getInstancia();
        set<DTUsuario> ListarUsuarios();
        set<DTListarViaje> ListarViajes(string nickname);
        set<DTUsuarioViaje> listarUsuariosViaje(int codigo);
        bool calificarUsuario(string nicknameCalificado, int calificacion);


};

#endif