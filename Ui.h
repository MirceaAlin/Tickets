#ifndef LABORATOR9_10_UI_H
#define LABORATOR9_10_UI_H

#include "Service.h"
#include "Exceptii_Ui.h"
#include <limits>
class Ui {
private:
    Service service;
public:
    Ui(Service& service);
    ~Ui();
    void meniu();
    void run();
    void Cumpara_Bilet();
    void Adaugare_Tranzactie();
    void Adaugare_Bilet();
    void Afisare_Tranzacti();
    void Afisare_Bilete();
    void Afisare_Suma();

};

#endif //LABORATOR9_10_UI_H
