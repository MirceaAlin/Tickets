#include "Entities.h"

Tranzactie::Tranzactie()
{
    this->valoare = 0;
    this->cantitate = 0;
}

Tranzactie::Tranzactie(int x, int y)
{
    this ->cantitate = x;
    this->valoare = y;
}

Tranzactie::Tranzactie(const Tranzactie &tranzactie) {
    this->cantitate = tranzactie.cantitate;
    this->valoare = tranzactie.valoare;
}

Tranzactie::~Tranzactie() {

}

Tranzactie &Tranzactie::operator=(const Tranzactie &alti) {
    if (this == &alti)
        return *this;
    this->cantitate = alti.cantitate;
    this->valoare = alti.valoare;
    return *this;
}

void Tranzactie::setValoare(int valoare) {
    this->valoare = valoare;
}

int Tranzactie::getValoare() {
    return this->valoare;
}

void Tranzactie::setCantitate(int cantitate) {
    this->cantitate =  cantitate;
}

int Tranzactie::getCantitate() {
    return this->cantitate;
}


