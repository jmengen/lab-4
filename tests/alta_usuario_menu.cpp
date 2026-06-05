#include "../include/ControlAltaUsuario.h"
#include "../include/ManejadorUsuarios.h"
#include "../include/ManejadorVehiculos.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoUsuario.h"
#include "../include/TipoVehiculo.h"

#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

struct UsuarioPrueba {
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    TipoUsuario tipo;
    std::string ci;
    std::set<TipoLibreta> libretas;
};

struct VehiculoPrueba {
    std::string conductor;
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
};

static std::map<std::string, UsuarioPrueba> usuariosRegistrados;
static std::map<std::string, VehiculoPrueba> vehiculosRegistrados;
static std::map<std::string, std::vector<std::string>> vehiculosPorConductor;

static void limpiarEntrada() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::string tipoUsuarioTexto(TipoUsuario tipo) {
    return tipo == TipoConductor ? "Conductor" : "Pasajero";
}

static std::string tipoVehiculoTexto(TipoVehiculo tipo) {
    return tipo == Auto ? "Auto" : "Moto";
}

static std::string libretaTexto(TipoLibreta libreta) {
    switch (libreta) {
        case AutoAmateur:
            return "Auto Amateur";
        case AutoProfesional:
            return "Auto Profesional";
        case MotoAmateur:
            return "Moto Amateur";
        case MotoProfesional:
            return "Moto Profesional";
    }

    return "Desconocida";
}

static void imprimirLibretas(const std::set<TipoLibreta>& libretas) {
    if (libretas.empty()) {
        std::cout << "sin libretas";
        return;
    }

    bool primera = true;
    for (TipoLibreta libreta : libretas) {
        if (!primera) std::cout << ", ";
        std::cout << libretaTexto(libreta);
        primera = false;
    }
}

static std::set<TipoLibreta> pedirLibretas() {
    std::set<TipoLibreta> libretas;
    int tiene = 0;

    std::cout << "Tiene libreta Auto Amateur? (1: Si, 0: No): ";
    std::cin >> tiene;
    if (tiene == 1) libretas.insert(AutoAmateur);

    std::cout << "Tiene libreta Auto Profesional? (1: Si, 0: No): ";
    std::cin >> tiene;
    if (tiene == 1) libretas.insert(AutoProfesional);

    std::cout << "Tiene libreta Moto Amateur? (1: Si, 0: No): ";
    std::cin >> tiene;
    if (tiene == 1) libretas.insert(MotoAmateur);

    std::cout << "Tiene libreta Moto Profesional? (1: Si, 0: No): ";
    std::cin >> tiene;
    if (tiene == 1) libretas.insert(MotoProfesional);

    limpiarEntrada();
    return libretas;
}

static void guardarPasajero(
    const std::string& nickname,
    const std::string& nombre,
    const std::string& contrasena,
    const std::string& email,
    const std::string& ci
) {
    usuariosRegistrados[nickname] = {
        nickname,
        nombre,
        contrasena,
        email,
        TipoPasajero,
        ci,
        {}
    };
}

static void guardarConductor(
    const std::string& nickname,
    const std::string& nombre,
    const std::string& contrasena,
    const std::string& email,
    const std::set<TipoLibreta>& libretas
) {
    usuariosRegistrados[nickname] = {
        nickname,
        nombre,
        contrasena,
        email,
        TipoConductor,
        "",
        libretas
    };
}

static void guardarVehiculo(
    const std::string& conductor,
    const std::string& matricula,
    int capacidad,
    const std::string& marca,
    const std::string& modelo,
    TipoVehiculo tipo
) {
    vehiculosRegistrados[matricula] = {
        conductor,
        matricula,
        capacidad,
        marca,
        modelo,
        tipo
    };
    vehiculosPorConductor[conductor].push_back(matricula);
}

static void imprimirUsuario(const std::string& nickname) {
    ManejadorUsuarios* manejador = ManejadorUsuarios::getInstance();
    Usuario* usuario = manejador->getUsuario(nickname);

    if (usuario == nullptr) {
        std::cout << "No existe usuario en el manejador.\n";
        return;
    }

    std::cout << "\nUsuario encontrado en manejador\n";
    std::cout << "Nickname: " << usuario->getNickname() << "\n";
    std::cout << "Nombre: " << usuario->getNombre() << "\n";
    std::cout << "Email: " << usuario->getEmail() << "\n";
    std::cout << "Tipo: " << tipoUsuarioTexto(usuario->getTipoUsuario()) << "\n";

    Pasajero* pasajero = manejador->getPasajero(nickname);
    if (pasajero != nullptr) {
        std::cout << "CI: " << pasajero->getCi() << "\n";
        return;
    }

    Conductor* conductor = manejador->getConductor(nickname);
    if (conductor != nullptr) {
        std::cout << "Libretas: ";
        imprimirLibretas(conductor->getLibretas());
        std::cout << "\n";
    }
}

static void imprimirUsuarioPorNickname() {
    std::string nickname;
    std::cout << "Nickname a imprimir: ";
    std::getline(std::cin, nickname);
    imprimirUsuario(nickname);
}

static void imprimirUsuariosRegistrados() {
    if (usuariosRegistrados.empty()) {
        std::cout << "Este menu de prueba todavia no registro usuarios.\n";
        return;
    }

    ManejadorUsuarios* manejador = ManejadorUsuarios::getInstance();
    std::cout << "\nUsuarios registrados desde este menu de prueba\n";

    for (const auto& par : usuariosRegistrados) {
        const UsuarioPrueba& usuario = par.second;
        bool existeEnManejador = manejador->getUsuario(usuario.nickname) != nullptr;

        std::cout << "- " << usuario.nickname << " | " << usuario.nombre
                  << " | " << usuario.email
                  << " | " << tipoUsuarioTexto(usuario.tipo)
                  << " | en manejador: " << (existeEnManejador ? "si" : "no");

        if (usuario.tipo == TipoPasajero) {
            std::cout << " | CI: " << usuario.ci;
        } else {
            std::cout << " | Libretas: ";
            imprimirLibretas(usuario.libretas);
        }

        std::cout << "\n";
    }
}

static void imprimirVehiculo(const VehiculoPrueba& vehiculo) {
    bool existeEnManejador = ManejadorVehiculos::getInstancia()->existeVehiculo(vehiculo.matricula);

    std::cout << "- Matricula: " << vehiculo.matricula
              << " | Conductor: " << vehiculo.conductor
              << " | Capacidad: " << vehiculo.capacidad
              << " | Marca: " << vehiculo.marca
              << " | Modelo: " << vehiculo.modelo
              << " | Tipo: " << tipoVehiculoTexto(vehiculo.tipo)
              << " | en manejador: " << (existeEnManejador ? "si" : "no")
              << "\n";
}

static void imprimirVehiculosRegistrados() {
    if (vehiculosRegistrados.empty()) {
        std::cout << "Este menu de prueba todavia no registro vehiculos.\n";
        return;
    }

    std::cout << "\nVehiculos registrados desde este menu de prueba\n";
    for (const auto& par : vehiculosRegistrados) {
        imprimirVehiculo(par.second);
    }
}

static void imprimirVehiculosDeConductor() {
    std::string nickname;
    std::cout << "Nickname del conductor: ";
    std::getline(std::cin, nickname);

    Conductor* conductor = ManejadorUsuarios::getInstance()->getConductor(nickname);
    if (conductor == nullptr) {
        std::cout << "No existe ese conductor en el manejador.\n";
        return;
    }

    auto it = vehiculosPorConductor.find(nickname);
    if (it == vehiculosPorConductor.end() || it->second.empty()) {
        std::cout << "Este menu de prueba no tiene vehiculos registrados para ese conductor.\n";
        return;
    }

    std::cout << "\nVehiculos registrados para " << nickname << "\n";
    for (const std::string& matricula : it->second) {
        auto vehiculo = vehiculosRegistrados.find(matricula);
        if (vehiculo != vehiculosRegistrados.end()) {
            imprimirVehiculo(vehiculo->second);
        }
    }
}

static void altaPasajero(IControlAltaUsuario* controlador) {
    std::string nickname, nombre, contrasena, email, ci;

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "CI: ";
    std::getline(std::cin, ci);

    if (controlador->altaPasajero(nickname, nombre, contrasena, email, ci)) {
        guardarPasajero(nickname, nombre, contrasena, email, ci);
        std::cout << "Pasajero registrado.\n";
        imprimirUsuario(nickname);
    } else {
        std::cout << "Ya existe un usuario con ese nickname.\n";
    }
}

static void altaConductor(IControlAltaUsuario* controlador) {
    std::string nickname, nombre, contrasena, email;

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::set<TipoLibreta> libretas = pedirLibretas();

    if (controlador->altaConductor(nickname, nombre, contrasena, email, libretas)) {
        guardarConductor(nickname, nombre, contrasena, email, libretas);
        std::cout << "Conductor registrado.\n";
        imprimirUsuario(nickname);
    } else {
        std::cout << "Ya existe un usuario con ese nickname.\n";
    }
}

static void registrarVehiculo(IControlAltaUsuario* controlador) {
    std::string nickname, matricula, marca, modelo;
    int capacidad = 0;
    int tipo = 0;

    std::cout << "Nickname del conductor: ";
    std::getline(std::cin, nickname);
    std::cout << "Matricula: ";
    std::getline(std::cin, matricula);
    std::cout << "Capacidad: ";
    std::cin >> capacidad;
    limpiarEntrada();
    std::cout << "Marca: ";
    std::getline(std::cin, marca);
    std::cout << "Modelo: ";
    std::getline(std::cin, modelo);
    std::cout << "Tipo (0: Auto, 1: Moto): ";
    std::cin >> tipo;
    limpiarEntrada();

    if (tipo != 0 && tipo != 1) {
        std::cout << "Tipo invalido.\n";
        return;
    }

    TipoVehiculo tipoVehiculo = (tipo == 0) ? Auto : Moto;
    int resultado = controlador->registrarVehiculo(
        nickname, matricula, capacidad, marca, modelo, tipoVehiculo
    );

    if (resultado == 0) {
        guardarVehiculo(nickname, matricula, capacidad, marca, modelo, tipoVehiculo);
        std::cout << "Vehiculo registrado.\n";
        imprimirVehiculo(vehiculosRegistrados[matricula]);
    } else if (resultado == -1) {
        std::cout << "Ya existe un vehiculo con esa matricula.\n";
    } else if (resultado == -2) {
        std::cout << "El conductor no tiene libreta compatible.\n";
    } else {
        std::cout << "El usuario no existe o no es conductor.\n";
    }
}

static bool esperar(bool condicion, const std::string& nombre) {
    std::cout << (condicion ? "[OK] " : "[FAIL] ") << nombre << "\n";
    return condicion;
}

static void pruebasAutomaticas(IControlAltaUsuario* controlador) {
    static int corrida = 1;
    int fallos = 0;
    std::string sufijo = "_auto_" + std::to_string(corrida++);

    std::string pas = "pas" + sufijo;
    std::string condAuto = "cond_auto" + sufijo;
    std::string condMoto = "cond_moto" + sufijo;
    std::string matAuto = "AUTO" + sufijo;
    std::string matMoto = "MOTO" + sufijo;
    std::string matBad = "BAD" + sufijo;

    auto check = [&](bool condicion, const std::string& nombre) {
        if (!esperar(condicion, nombre)) ++fallos;
    };

    bool pasajeroOk = controlador->altaPasajero(pas, "Pas Test", "123", pas + "@test.com", "111");
    if (pasajeroOk) guardarPasajero(pas, "Pas Test", "123", pas + "@test.com", "111");
    check(pasajeroOk, "alta pasajero nuevo");
    check(!controlador->altaPasajero(pas, "Otro", "123", "otro@test.com", "222"), "alta pasajero duplicado");
    check(ManejadorUsuarios::getInstance()->getPasajero(pas) != nullptr, "pasajero recuperable por manejador");
    check(ManejadorUsuarios::getInstance()->getConductor(pas) == nullptr, "pasajero no es conductor");

    bool conductorOk = controlador->altaConductor(condAuto, "Cond Auto", "123", condAuto + "@test.com", {AutoAmateur});
    if (conductorOk) guardarConductor(condAuto, "Cond Auto", "123", condAuto + "@test.com", {AutoAmateur});
    check(conductorOk, "alta conductor nuevo");
    check(!controlador->altaConductor(condAuto, "Otro", "123", "otro@test.com", {MotoAmateur}), "alta conductor duplicado");
    check(ManejadorUsuarios::getInstance()->getConductor(condAuto) != nullptr, "conductor recuperable por manejador");
    check(ManejadorUsuarios::getInstance()->getPasajero(condAuto) == nullptr, "conductor no es pasajero");

    int autoValido = controlador->registrarVehiculo(condAuto, matAuto, 4, "Toyota", "Corolla", Auto);
    if (autoValido == 0) guardarVehiculo(condAuto, matAuto, 4, "Toyota", "Corolla", Auto);
    check(autoValido == 0, "registrar auto valido");
    check(ManejadorVehiculos::getInstancia()->existeVehiculo(matAuto), "auto valido existe en manejador");
    check(controlador->registrarVehiculo(condAuto, matAuto, 4, "Toyota", "Corolla", Auto) == -1, "matricula duplicada");

    bool conductorMotoOk = controlador->altaConductor(condMoto, "Cond Moto", "123", condMoto + "@test.com", {MotoAmateur});
    if (conductorMotoOk) guardarConductor(condMoto, "Cond Moto", "123", condMoto + "@test.com", {MotoAmateur});
    check(conductorMotoOk, "alta conductor con libreta moto");

    int motoValida = controlador->registrarVehiculo(condMoto, matMoto, 2, "Honda", "Wave", Moto);
    if (motoValida == 0) guardarVehiculo(condMoto, matMoto, 2, "Honda", "Wave", Moto);
    check(motoValida == 0, "registrar moto valida");
    check(ManejadorVehiculos::getInstancia()->existeVehiculo(matMoto), "moto valida existe en manejador");

    check(controlador->registrarVehiculo(condMoto, matBad, 4, "Fiat", "Cronos", Auto) == -2, "rechaza auto sin libreta de auto");
    check(!ManejadorVehiculos::getInstancia()->existeVehiculo(matBad), "vehiculo rechazado no queda registrado");
    check(controlador->registrarVehiculo(pas, "PAS" + sufijo, 4, "Marca", "Modelo", Auto) == 67, "pasajero no puede registrar vehiculo");
    check(controlador->registrarVehiculo("nadie" + sufijo, "NONE" + sufijo, 4, "Marca", "Modelo", Auto) == 67, "usuario inexistente no registra vehiculo");

    std::cout << "Fallos automaticos: " << fallos << "\n";
}

int main() {
    ControlAltaUsuario controladorReal;
    IControlAltaUsuario* controlador = &controladorReal;
    int opcion = 0;

    while (opcion != 9) {
        std::cout << "\n=== Menu de prueba Alta Usuario ===\n";
        std::cout << "1. Alta pasajero\n";
        std::cout << "2. Alta conductor\n";
        std::cout << "3. Registrar vehiculo\n";
        std::cout << "4. Imprimir usuario por nickname\n";
        std::cout << "5. Imprimir usuarios registrados\n";
        std::cout << "6. Imprimir vehiculos de conductor\n";
        std::cout << "7. Imprimir todos los vehiculos registrados\n";
        std::cout << "8. Pruebas automaticas\n";
        std::cout << "9. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        limpiarEntrada();

        switch (opcion) {
            case 1:
                altaPasajero(controlador);
                break;
            case 2:
                altaConductor(controlador);
                break;
            case 3:
                registrarVehiculo(controlador);
                break;
            case 4:
                imprimirUsuarioPorNickname();
                break;
            case 5:
                imprimirUsuariosRegistrados();
                break;
            case 6:
                imprimirVehiculosDeConductor();
                break;
            case 7:
                imprimirVehiculosRegistrados();
                break;
            case 8:
                pruebasAutomaticas(controlador);
                break;
            case 9:
                break;
            default:
                std::cout << "Opcion invalida.\n";
                break;
        }
    }

    return 0;
}
