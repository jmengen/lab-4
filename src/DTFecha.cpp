#include "../include/DTFecha.h"

DTFecha::DTFecha() {
    this->dia = 1;
    this->mes = 1;
    this->anio = 1900;
}

DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTFecha::getDia() { return dia; }
int DTFecha::getMes() { return mes; }
int DTFecha::getAnio() { return anio; }

bool DTFecha::operator==(DTFecha other) {
    return (dia == other.dia && mes == other.mes && anio == other.anio);
}

bool DTFecha::operator<=(const DTFecha& other) const {
    if (anio != other.anio) {
        return anio < other.anio;
    }
    if (mes != other.mes) {
        return mes < other.mes;
    }
    return dia <= other.dia;
}

std::ostream& operator<<(std::ostream& os, DTFecha f) {
    os << f.getDia() << "/" << f.getMes() << "/" << f.getAnio();
    return os;
}
