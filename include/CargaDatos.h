#ifndef CARGA_DATOS_H
#define CARGA_DATOS_H

class CargaDatos {
private:
    static CargaDatos* instancia;
    bool datosCargados;

    CargaDatos();

public:
    static CargaDatos* getInstance();
    static void liberarInstancia();
    void cargarDatos();
};

#endif
