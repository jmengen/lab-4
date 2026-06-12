#ifndef CONTROLCALIFICARUSUARIO_H
#define CONTROLCALIFICARUSUARIO_H
#include "IControlCalificarUsuario.h"
#include "ManejadorUsuarios.h"
#include "ManejadorViajes.h"
#include "ManejadorCalificaciones.h"
#include "ManejadorReservas.h"
#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include <set>
using namespace std;

class ControlCalificarUsuario : public IControlCalificarUsuario{
    private:
        static ControlCalificarUsuario* instancia;
        ControlCalificarUsuario() = default;
        string nickRecordado;
        int codRecordado = -1;


    public:
        static ControlCalificarUsuario* getInstance();
        static void liberarInstancia();
        
        set<DTUsuario> listarUsuarios();
        set<DTListarViaje> listarViajes(string nickname);
        set<DTUsuarioViaje> listarUsuariosViaje(int codigo);
        bool calificarUsuario(string nicknameCalificado, int calificacion);


};

#endif
