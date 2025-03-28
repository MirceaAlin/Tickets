#ifndef LABORATOR9_10_SERVICE_H
#define LABORATOR9_10_SERVICE_H
#include "Repo.h"
#include "Exceptii_Service.h"
class Service {
private:
    Repo_Tranzactie repoTranzactie;
    Repo_bilete repoBilete;

public:
    Service();
    Service(Repo_Tranzactie &repoTranzactie, Repo_bilete &repoBilete);
    ~Service();
    void createBilet(int cod, char* destinatie, int pret);
    void createTranzactie(int cantitate, int valoare);
    std::vector<Bilet>& readAllBilete();
    std::vector<Tranzactie>& readAllTranzacti();
    void updateBilet(int pozitie, const Bilet& bilet);
    void updateTranzactie(int valoare, int cantitate);
    void deleteBilet(int cod);
    void deleteTranzactie(int valoare, int cantitate);
    int getSuma();
    bool getRest(Bilet bilet);
};

#endif //LABORATOR9_10_SERVICE_H
