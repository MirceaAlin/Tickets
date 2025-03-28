#include "Service.h"

Service::Service() {
}

Service::Service(Repo_Tranzactie &repoTranzactie, Repo_bilete &repoBilete) : repoTranzactie(repoTranzactie), repoBilete(repoBilete) {
}

Service::~Service() {
}

void Service::createBilet(int cod, char* destinatie, int pret) {
    Bilet bilet(cod, destinatie, pret);
    repoBilete.addItem(bilet);
}

void Service::createTranzactie(int cantitate, int valoare){
    Tranzactie tranzactie(cantitate,valoare);
    repoTranzactie.addItem(tranzactie);
}

std::vector<Bilet>& Service::readAllBilete() {
    return repoBilete.getAll();
}

std::vector<Tranzactie>& Service::readAllTranzacti() {
    return repoTranzactie.getAll();
}

void Service::updateBilet(int pozitie, const Bilet &bilet){
    repoBilete.modificareBilet(pozitie, bilet);
}

void Service::updateTranzactie(int valoare, int cantitate){
    repoTranzactie.modificareTranzactie(valoare,cantitate);
}

void Service::deleteBilet(int cod) {
    repoBilete.eraseBilet(cod);
}

void Service::deleteTranzactie(int valoare, int cantitate) {
    repoTranzactie.eraseBancnota(valoare,cantitate);
}

int Service::getSuma() {
    return repoTranzactie.getSuma();
}

bool Service::getRest(Bilet bilet) {
    if (getSuma() < bilet.getPret()) {
        return false;
    }
    std::vector<Tranzactie> tranzacti = readAllTranzacti();
    std::vector<Tranzactie> bancnote;

    for (auto i = tranzacti.rbegin(); i != tranzacti.rend(); ++i)  {
        if (i->getCantitate() > 0 && i->getValoare() <= bilet.getPret()) {
            int numBills = std::min(i->getCantitate(), bilet.getPret() / i->getValoare());
            bilet.setPret(bilet.getPret() - numBills * i->getValoare());
            bancnote.push_back({ i->getValoare(), numBills });
        }
    }

    if (bilet.getPret() != 0) {
        return false;
    } else {
        for (auto& bancnota : bancnote) {
            repoTranzactie.eraseBancnota(bancnota.getValoare(), bancnota.getCantitate());
        }
        return true;
    }
}