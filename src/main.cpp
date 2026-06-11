#include "../include/Menu.h"
#include "../include/Fabrica.h"

int main() {
    Fabrica* fabrica = Fabrica::getInstance();
    Menu menu(
        fabrica->getIControlAltaUsuario(),
        fabrica->getIControlAltaViaje(),
        fabrica->getIControlGenerarReserva(),
        fabrica->getIControlCalificarUsuario(),
        fabrica->getIEliminarViaje(),
        fabrica->getIControladorFechaActual()
    );
    menu.mostrarMenu();
    return 0;
}
