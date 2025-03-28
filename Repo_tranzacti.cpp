#include "Repo.h"

Repo_Tranzactie::Repo_Tranzactie() {
}

Repo_Tranzactie::~Repo_Tranzactie() {
}

std::vector<Tranzactie>& Repo_Tranzactie::getAll() {
    return tranzacti;
}

int Repo_Tranzactie::getSize() {
    return tranzacti.size();
}

void Repo_Tranzactie::addItem(Tranzactie &bancnota) {
    if(!tr.validate(bancnota.getCantitate(),bancnota.getValoare()))
        throw Exceptii_Repo("Tranzactia nu a putut fi validata\n");
    bool ok = true;
    for (auto i =tranzacti.begin(); i != tranzacti.end(); ++i) {
        if (i->getValoare()==bancnota.getValoare()) {
            int a=i->getCantitate()+bancnota.getCantitate();
            i->setCantitate(a);
            ok=false;
            break;
        }
    }
    if (ok){
        tranzacti.push_back(bancnota);
    }

}

bool Repo_Tranzactie::modificareTranzactie(int valoare,int cantitate) {
    for (auto i = tranzacti.begin(); i != tranzacti.end(); ++i) {
        if (i->getValoare() == valoare) {
            i->setCantitate(cantitate);
            return true;
        }
    }
    return false;
}

bool Repo_Tranzactie::eraseBancnota(int valoare, int cantitate) {
    for (auto i = tranzacti.begin(); i != tranzacti.end(); ++i) {
        if (i->getValoare() == valoare) {
            int a = i->getCantitate() - cantitate;
            i->setCantitate(a);
            return true;
        }
    }
    return false;
}

int Repo_Tranzactie::getSuma() {
    int suma=0;
    for (auto i = tranzacti.begin(); i != tranzacti.end(); ++i) {
        suma=suma+(i->getValoare()*i->getCantitate());
    }
    return suma;
}
