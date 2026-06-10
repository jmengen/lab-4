#include "../include/CargaDatos.h"
#include "../include/ControlAltaUsuario.h"
#include "../include/ControlAltaViaje.h"
#include "../include/ControlGenerarReserva.h"
#include "../include/ControlCalificarUsuario.h"
#include "../include/ControladorFechaActual.h"
#include <iostream>
#include <set>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }

    std::cout << "Cargando datos harcodeados del sistema...\n";

    ControlAltaUsuario* cau = ControlAltaUsuario::getInstance();
    ControlAltaViaje* cav = ControlAltaViaje::getInstance();
    ControlGenerarReserva* cgr = ControlGenerarReserva::getInstance();
    ControlCalificarUsuario* ccu = ControlCalificarUsuario::getInstance();
    ControladorFechaActual* cfa = ControladorFechaActual::getInstance();

    std::set<TipoLibreta> libretas;

    libretas.insert(AutoAmateur);
    cau->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", libretas);
    libretas.clear();

    libretas.insert(AutoProfesional);
    cau->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", libretas);
    libretas.clear();

    libretas.insert(MotoAmateur);
    cau->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", libretas);
    libretas.clear();

    libretas.insert(MotoProfesional);
    cau->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", libretas);
    libretas.clear();

    libretas.insert(AutoProfesional);
    libretas.insert(MotoAmateur);
    cau->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", libretas);

    cau->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    cau->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    cau->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    cau->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    cau->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    cau->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", Auto);
    cau->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", Auto);
    cau->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", Auto);
    cau->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", Auto);
    cau->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", Moto);
    cau->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", Moto);
    cau->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", Auto);
    cau->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", Moto);

    cav->listarVehiculosConductor("matil92");
    cav->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);
    cav->listarVehiculosConductor("matil92");
    cav->altaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250);
    cav->listarVehiculosConductor("ana_silva");
    cav->altaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200);
    cav->listarVehiculosConductor("ana_silva");
    cav->altaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200);
    cav->listarVehiculosConductor("greg_m");
    cav->altaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300);
    cav->listarVehiculosConductor("lau_vaz");
    cav->altaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350);
    cav->listarVehiculosConductor("carlos_r");
    cav->altaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260);
    cav->listarVehiculosConductor("carlos_r");
    cav->altaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150);
    cav->listarVehiculosConductor("matil92");
    cav->altaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140);
    cav->listarVehiculosConductor("ana_silva");
    cav->altaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180);
    cav->listarVehiculosConductor("carlos_r");
    cav->altaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100);
    cav->listarVehiculosConductor("carlos_r");
    cav->altaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600);
    cav->listarVehiculosConductor("greg_m");
    cav->altaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250);

    cfa->setFecha(DTFecha(14, 3, 2026));
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(15, 3, 2026), "montevideo", "colonia", 2);
    cgr->generarReserva("santi_90", 9, 2);
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(15, 3, 2026), "montevideo", "colonia", 1);
    cgr->generarReserva("mari_b", 9, 1);
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(15, 3, 2026), "montevideo", "colonia", 5);
    cgr->generarReserva("nacho_f", 10, 5);
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(15, 3, 2026), "montevideo", "colonia", 3);
    cgr->generarReserva("valen_uy", 10, 3);
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(15, 3, 2026), "montevideo", "colonia", 1);
    cgr->generarReserva("joaco_r", 10, 1);

    cfa->setFecha(DTFecha(13, 3, 2026));
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(14, 3, 2026), "montevideo", "colonia", 1);
    cgr->generarReserva("mari_b", 12, 1);
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(14, 3, 2026), "montevideo", "colonia", 1);
    cgr->generarReserva("nacho_f", 12, 1);

    cfa->setFecha(DTFecha(1, 6, 2026));
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(21, 10, 2026), "montevideo", "mercedes", 2);
    cgr->generarReserva("mari_b", 1, 2);

    cfa->setFecha(DTFecha(13, 3, 2026));
    cgr->listarPasajeros();
    cgr->consultarViajes(DTFecha(15, 3, 2026), "montevideo", "colonia", 1);
    cgr->generarReserva("nacho_f", 9, 1);

    ccu->listarViajes("santi_90");
    ccu->listarUsuariosViaje(9);
    ccu->calificarUsuario("matil92", 4);

    ccu->listarViajes("mari_b");
    ccu->listarUsuariosViaje(9);
    ccu->calificarUsuario("matil92", 4);

    ccu->listarViajes("matil92");
    ccu->listarUsuariosViaje(9);
    ccu->calificarUsuario("mari_b", 3);

    ccu->listarViajes("ana_silva");
    ccu->listarUsuariosViaje(10);
    ccu->calificarUsuario("valen_uy", 5);

    ccu->listarViajes("ana_silva");
    ccu->listarUsuariosViaje(10);
    ccu->calificarUsuario("joaco_r", 5);

    ccu->listarViajes("mari_b");
    ccu->listarUsuariosViaje(12);
    ccu->calificarUsuario("carlos_r", 5);

    ccu->listarViajes("carlos_r");
    ccu->listarUsuariosViaje(12);
    ccu->calificarUsuario("nacho_f", 5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
