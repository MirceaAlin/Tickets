#include "Repo.h"

Repo_bilete::Repo_bilete() {
}

Repo_bilete::~Repo_bilete() {
}

std::vector<Bilet>& Repo_bilete::getAll() {
    return bilete;
}

int Repo_bilete::getSize() {
    return bilete.size();
}

void Repo_bilete::addItem(Bilet &bilet) {
    if(!bl.validate(bilet.getCod(),bilet.getDestinatie(),bilet.getPret()))
        throw Exceptii_Repo("Biletul nu a putut fi adaugat\n");
    bilete.push_back(bilet);
}

bool Repo_bilete::modificareBilet(int pozitie, const Bilet& biletModificat) {
    if (pozitie >= 0 && pozitie < bilete.size()) {
        bilete[pozitie] = biletModificat;
        return true;
    }
    return false;
}

bool Repo_bilete::eraseBilet(int cod) {
    for (auto i = bilete.begin(); i != bilete.end(); ++i)
        if(i->getCod()==cod){
            bilete.erase(i);
            return true;
        }
    return false;
}



