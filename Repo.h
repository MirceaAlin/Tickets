#ifndef LABORATOR9_10_Repo_Tranzactie_H
#define LABORATOR9_10_Repo_Tranzactie_H
#include "Entities.h"
#include "Validator.h"
#include "Exceptii_Repo.h"
#include <vector>
class Repo_Tranzactie {
protected:
    std::vector<Tranzactie> tranzacti;
    TranzactieValidator tr;
public:
    Repo_Tranzactie();
    ~Repo_Tranzactie();
    std::vector<Tranzactie>& getAll();
    int getSize();
    void addItem(Tranzactie& bancnota);
    bool modificareTranzactie(int valoare,int cantitate);
    bool eraseBancnota(int valoare, int cantitate);
    int getSuma();
};
class Repo_bilete {
protected:
    std::vector<Bilet> bilete;
    BiletValidator bl;
public:
    Repo_bilete();
    ~Repo_bilete();
    std::vector<Bilet>& getAll();
    int getSize();
    void addItem(Bilet& bilet);
    bool modificareBilet(int pozitie, const Bilet& biletModificat);
    bool eraseBilet(int cod);
};
#endif //LABORATOR9_10_Repo_Tranzactie_H
