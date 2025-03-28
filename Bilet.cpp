#include "Entities.h"
#include <cstring >
Bilet::Bilet() {
    this->cod = 0;
    this->destinatie = nullptr;
    this->pret = 0;
}

Bilet::Bilet(int cod, char *destinatie, int pret) {
    this->cod = cod;
    this->destinatie = new char[strlen(destinatie) + 1];
    strcpy(this->destinatie, destinatie);
    this->pret = pret;
}

Bilet::Bilet(const Bilet &bilet) {
    this->cod = bilet.cod;
    this->pret = bilet.pret;
    this->destinatie = new char[strlen(bilet.destinatie) + 1];
    strcpy(this->destinatie, bilet.destinatie);
}

Bilet::~Bilet() {
    delete[] destinatie;
}

void Bilet::setPret(int pret) {
    this->pret=pret;
}

int Bilet::getPret() {
    return this->pret;
}

void Bilet::setCod(int cod) {
    this->cod=cod;
}

int Bilet::getCod() {
    return this->cod;
}

void  Bilet::setDestinatie(char *destinatie) {
    this->destinatie = new char[strlen(destinatie) + 1];
    strcpy(this->destinatie,destinatie);
}

char *Bilet::getDestinatie() {
    return this->destinatie;
}

Bilet &Bilet::operator=(const Bilet &altu) {
    if (this == &altu)
        return *this;
    this->cod = altu.cod;
    this->pret = altu.pret;
    delete[] destinatie;
    this->destinatie = new char[strlen(altu.destinatie) + 1];
    strcpy(this->destinatie, altu.destinatie);
    return *this;

}