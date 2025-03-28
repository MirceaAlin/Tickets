//
// Created by Ali on 21.05.2024.
//

#ifndef LABORATOR9_10_VALIDATOR_H
#define LABORATOR9_10_VALIDATOR_H
#include "Entities.h"
#include "Exceptii_Entitate.h"
#include <iostream>
#include <cstring>
#include <utility>

class TranzactieValidator {
public:
    bool validate(int cantitate, int valoare) {
        if (cantitate <= 0) {
            throw Exceptii_Entitate("Cantitatea trebuie sa fie mai mare decat zero.\n");
        }
        if (valoare < 0) {
            throw Exceptii_Entitate("Valoarea trebuie sa fie non-negativa.\n");
        }
        return true;
    }

};

class BiletValidator {
public:
    bool validate(int cod, const char* destinatie, int pret) {
        if (cod <= 0) {
            throw Exceptii_Entitate("Codul trebuie sa fie mai mare decat zero.\n");
        }
        if (destinatie == nullptr || std::strlen(destinatie) == 0) {
            throw Exceptii_Entitate("Destinatia nu poate fi vida.\n");
        }
        if (pret < 0) {
            throw Exceptii_Entitate("Pretul trebuie sa fie pozitiv.\n");
        }
        return true;
    }
};


#endif //LABORATOR9_10_VALIDATOR_H
