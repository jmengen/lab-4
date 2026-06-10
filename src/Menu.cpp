#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/IControladorFechaActual.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include "../include/DTDetalleReserva.h"
#include "../include/DTDetalleVehiculo.h"
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <vector>

#include "../include/DTListarViaje.h"
#include "../include/Viaje.h"

#include "../include/ControlAltaUsuario.h"
#include "../include/ControlAltaViaje.h"
#include "../include/ControlGenerarReserva.h"
#include "../include/ControlCalificarUsuario.h"
#include "../include/ControlEliminarViaje.h"

#include "../include/ManejadorUsuarios.h"
#include "../include/ManejadorVehiculos.h"

void Menu::altaUsuario() {

    ControlAltaUsuario * controlador = ControlAltaUsuario::getInstance();

    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);


    bool usuarioOk = false;

    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci); //usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci)
    } else if (tipoUsuario == 2) {
        bool tieneMotoProfesional = false;
        bool tieneMotoAmateur = false;
        bool tieneAutoProfesional = false;
        bool tieneAutoAmateur = false;

        int cantLibretas = 0;
        int agregarLibreta = 1;

        while (agregarLibreta == 1 && cantLibretas < 4) {
            int tipoLibreta;
            std::cout << "\n=== Registrar Libreta ===\n";
            std::cout << "0. Moto (Profesional)\n";
            std::cout << "1. Moto (Amateur)\n";
            std::cout << "2. Auto (Profesional)\n";
            std::cout << "3. Auto (Amateur)\n";
            std::cout << "Seleccione el tipo de libreta: ";
            std::cin >> tipoLibreta;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool yaExiste = false;
            if (tipoLibreta == 0) {
                if (tieneMotoProfesional) {
                    yaExiste = true;
                } else {
                    tieneMotoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 1) {
                if (tieneMotoAmateur) {
                    yaExiste = true;
                } else {
                    tieneMotoAmateur = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 2) {
                if (tieneAutoProfesional) {
                    yaExiste = true;
                } else {
                    tieneAutoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 3) {
                if (tieneAutoAmateur) {
                    yaExiste = true;
                } else {
                    tieneAutoAmateur = true;
                    cantLibretas++;
                }
            } else {
                std::cout << "Opcion invalida.\n";
                continue;
            }

            if (yaExiste) {
                std::cout << "Esa libreta ya fue ingresada.\n";
            } else {
                std::cout << "Libreta agregada.\n";
            }

            if (cantLibretas < 4) {
                std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
                std::cin >> agregarLibreta;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cout << "Se ha alcanzado el limite maximo de libretas.\n";
            }
        }

        if (cantLibretas == 0) {
            std::cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
            return;
        }
        std::set<TipoLibreta> libretas;
        if (tieneMotoProfesional) {
            libretas.insert(TipoLibreta::MotoProfesional);
        }
        if (tieneMotoAmateur) {
            libretas.insert(TipoLibreta::MotoAmateur);
        }
        if (tieneAutoProfesional) {
            libretas.insert(TipoLibreta::AutoProfesional);
        }
        if (tieneAutoAmateur) {
            libretas.insert(TipoLibreta::AutoAmateur);
        }

        usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas); //usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas)
        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int resultadoRegistrarVehiculo = -3;

            TipoVehiculo v;
            if (tipo == 0){
                v = Auto;
            } else {
                v = Moto;
            }
            resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, v); //resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipo)
            
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    if (usuarioOk) {
        std::cout << "Usuario registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el usuario.\n";
    }
}

void Menu::altaViaje() {
    ControlAltaViaje * controlador = ControlAltaViaje::getInstance();

    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);
    std::set<DTVehiculosConductor> ColeccionDTVC = controlador->listarVehiculosConductor(nickname); //Coleccion de DTVehiculosConductor = controlador->listarVehiculosConductor(nickname)

    std::set<DTVehiculosConductor>::iterator it;
    for (it = ColeccionDTVC.begin(); it != ColeccionDTVC.end(); ++it){
        DTVehiculosConductor actual = *it;
        std::cout << "> Matricula: " << actual.getMatricula() << ", Modelo: " << actual.getModelo()  << ", Capacidad: " << actual.getCapacidad() << "\n";
        // Recorrer la coleccion y mostrar "> Matricula: xx, Modelo: yy, Capacidad: www"
    } 

    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);
    bool matriculaValida = false;

    ManejadorVehiculos* manejve = ManejadorVehiculos::getInstancia();
    if (manejve->existeVehiculo(matricula)){
        matriculaValida = true; //Validar matricula en listado
    }
    
    if (!matriculaValida) {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool viajeOk = false;
    viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio); //viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio)
    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
    ControlGenerarReserva * controlador = ControlGenerarReserva::getInstance();

    std::set<std::string> coleccionPasajeros = controlador->listarPasajeros(); //Colecion de String = controlador->listarPasajeros()
    std::set<std::string>::iterator it;
    for (it = coleccionPasajeros.begin(); it != coleccionPasajeros.end(); ++it){
        std::cout << "> " << *it << "\n"; //Recorrer la colección y mostrar "> xx"
    } 

    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    bool nicknameValido = false;

    ManejadorUsuarios* manejus = ManejadorUsuarios::getInstance();
    if (!manejus->existeUsuario(nickname)){
        nicknameValido = true; //Validar nickname en listado
    }

    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::list<DTConsultaViaje> coleccionDTCV = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);  //Coleccion de DTConsultaViaje = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos)
    
    std::list<DTConsultaViaje>::iterator it2;
    for (it2 = coleccionDTCV.begin(); it2 != coleccionDTCV.end(); ++it2){
        DTConsultaViaje actual = *it2;
        std::cout << "> Codigo: " << actual.getCodigo() << ", Marca: " << actual.getMarca() << ", Modelo: " << actual.getModelo() << ", Conductor: " << actual.getConductor() << ", CalificacionPromedio: " << actual.getCalificacionProm() << ", PrecioTotal: " << actual.getPrecioTotal();
        //Recorrer la coleccion y mostrar: "> Codigo: xx, Marca: yy, Modelo: zzz, Conductor: aaa, CalificacionPromedio: qqq, PrecioTotal: eee"
    } 

    bool hayViajes = !coleccionDTCV.empty(); //Validar coleccion vacía
    if (!hayViajes) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;

    for (it2 = coleccionDTCV.begin(); it2 != coleccionDTCV.end(); ++it2){
        DTConsultaViaje actual = *it2;
        if (actual.getCodigo() == codigo){
            codigoValido = true; //Validar codigo en listado
            break;
        }
    }

    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = controlador->generarReserva(nickname, codigo, asientos); //reservaOk = controlador->generarReserva(nickname, codigo, asientos)
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
    ControlCalificarUsuario * controlador = ControlCalificarUsuario::getInstance();
    std::set<DTUsuario> coleccionUs = controlador->listarUsuarios(); //Coleccion de DTUsuario = controlador->listarUsuarios()

    std::set<DTUsuario>::iterator it;
    for (it = coleccionUs.begin(); it != coleccionUs.end(); ++it){
        DTUsuario actual = *it;
        std::cout << "> Nickname: " << actual.getNickname() << ", Nombre: " << actual.getNombre() << "\n";
        //Recorrer la coleccion y mostrar "> Nickname: xx, Nombre: yyy"
    } 

    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    bool nicknameValido = false;
    ManejadorUsuarios* manejus = ManejadorUsuarios::getInstance();
    if (!manejus->existeUsuario(nickname)){
        nicknameValido = true; //Validar nickname en listado
    }
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    std::set<DTListarViaje> ColeccionDTLV = controlador->listarViajes(nickname); //Coleccion de DTListarViaje = controlador->listarViajes(nickname)

    std::set<DTListarViaje>::iterator it2;
    for (it2 = ColeccionDTLV.begin(); it2 != ColeccionDTLV.end(); ++it2){
        DTListarViaje actual = *it2;
        DTFecha fecha = actual.getFecha();
        std::cout << "> Codigo: " << actual.getCodigo() << ", Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << ", Origen: " << actual.getOrigen() << ", Destino: " << actual.getDestino() << ", Conductor: " << actual.getConductor() << "\n";
        //Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    } 
    
    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;

    ManejadorViajes* manejvia = ManejadorViajes::getInstance();
    if (!manejvia->existeViaje(codigo)){
        codigoValido = true; //Validar codigo en listado
    }

    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    std::set<DTUsuarioViaje> ColeccionDTUV = controlador->listarUsuariosViaje(codigo); // Coleccion de DTUsuarioViaje = Controlador->listarUsuariosViaje(codigo)

    std::set<DTUsuarioViaje>::iterator it3;
    for (it3 = ColeccionDTUV.begin(); it3 != ColeccionDTUV.end(); ++it3){
        DTUsuarioViaje actual = *it3;
        std::cout << "> Nickname: " << actual.getNickname() << ", Tipo: " << actual.getTipo() << "\n";
        //Recorrer la coleccion y mostrar "> Nickname: xx, Tipo: yyy"
    }

    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool nicknameCalificadoValido = false;

    if (!manejus->existeUsuario(nickname)){
        nicknameCalificadoValido = true; //Validar nickname en listado
    }

    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = false;
    calificacionOk = controlador->calificarUsuario(nicknameCalificado, calificacion);//calificacionOk = Controlador->calificarUsuario(nicknameCalificado, calificacion)
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {
    ControlEliminarViaje * controlador = ControlEliminarViaje::getInstance();
    std::set<DTListarViaje> ColeccionDTLV = controlador->listarViajes(); //Coleccion de DTListarViaje = controlador->listarViajes()

    std::set<DTListarViaje>::iterator it;
    for (it = ColeccionDTLV.begin(); it != ColeccionDTLV.end(); ++it){
        DTListarViaje actual = *it;
        DTFecha fecha = actual.getFecha();
        std::cout << "> Codigo: " << actual.getCodigo() << ", Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << ", Origen: " << actual.getOrigen() << ", Destino: " << actual.getDestino() << ", Conductor: " << actual.getConductor() << "\n";
        //Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    } 

    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    for (it = ColeccionDTLV.begin(); it != ColeccionDTLV.end(); it++) {
        if (it->getCodigo() == codigo) {
            codigoValido = true; // Validar codigo en listado
            break;
        }
    }

    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    DTDetalleViaje detalle = controlador->detalleViaje(codigo); //DTDetalleViaje = controlador->detalleViaje(codigo)

    DTDetalleVehiculo vehiculo = detalle.getVehiculo();
    std::vector<DTDetalleReserva> reservas = detalle.getReservas();
    DTFecha fechaViaje = detalle.getFecha();
    std::string tipoVehiculo;
    if (vehiculo.getTipo() == Auto){
        tipoVehiculo = "Auto";
    } else {
        tipoVehiculo = "Moto";
    }

    //Mostrar detalle del viaje siguiendo el formato
    std::cout << ">> Viaje <<\n";
    std::cout << "--- Matricula: " << vehiculo.getMatricula()
              << ", Fecha: " << fechaViaje.getDia() << "/" << fechaViaje.getMes() << "/" << fechaViaje.getAnio()
              << ", Origen: " << detalle.getOrigen()
              << ", Destino: " << detalle.getDestino()
              << ", Capacidad: " << detalle.getAsientosPublicados()
              << ", Precio por asiento: " << detalle.getPrecio() << "\n";
    std::cout << ">> Vehiculo <<\n";
    std::cout << "--- Matricula: " << vehiculo.getMatricula()
              << ", Capacidad: " << vehiculo.getCapacidad()
              << ", Marca: " << vehiculo.getMarca()
              << ", Modelo: " << vehiculo.getModelo()
              << ", Tipo: " << tipoVehiculo << "\n";
    std::cout << ">> Reservas <<\n";
    std::vector<DTDetalleReserva>::iterator resIt;
    for (resIt = reservas.begin(); resIt != reservas.end(); ++resIt) {
        DTDetalleReserva actual = *resIt;
        DTFecha fechaReserva = actual.getFecha();
        std::cout << "--- AsientosReservados: " << actual.getAsientosReservados()
                  << ", Fecha: " << fechaReserva.getDia() << "/" << fechaReserva.getMes() << "/" << fechaReserva.getAnio()
                  << ", Pasajero: " << actual.getPasajero() << "\n";
    }

    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        controlador->eliminarViaje(); //controlador->eliminarViaje()
        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
        controlador->cancelarEliminarViaje(); //controlador->cancelarEliminarViaje() 
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
