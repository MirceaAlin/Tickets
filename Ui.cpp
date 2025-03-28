#include "Ui.h"
#include <iostream>
#include <cstring>

Ui::Ui(Service &service) : service(service) {}

void Ui::meniu() {
    std::cout << "\n=========== Meniu ===========\n";
    std::cout << " 1. Alimentare ATM\n";
    std::cout << " 2. Creaza un Bilet\n";
    std::cout << " 3. Afiseaza Biletele\n";
    std::cout << " 4. Afiseaza bancnotele\n";
    std::cout << " 5. Afiseaza Totala din ATM\n";
    std::cout << " 6. Cumpara bilet\n";
    std::cout << " 0. Iesire\n";
    std::cout << "=============================\n";
}

void Ui::run() {
    int optiune;
    do {
        meniu();
        std::cout << "Introduceti optiunea: ";
        std::cin >> optiune;
        try {
            std::cin.ignore();
            switch (optiune) {
                case 0:
                    std::cout << "Iesire din aplicatie...\n";
                    exit(0);
                case 1:
                    Adaugare_Tranzactie();
                    break;
                case 2:
                    Adaugare_Bilet();
                    break;
                case 3:
                    Afisare_Bilete();
                    break;
                case 4:
                    Afisare_Tranzacti();
                    break;
                case 5:
                    Afisare_Suma();
                    break;
                case 6:
                    Cumpara_Bilet();
                    break;
                default:
                    std::cout << "Optiune invalida. Va rugam selectati o optiune valida.\n";
                    break;
            }
        } catch (const Exceptii_Ui& ex) {
            std::cout << ex.what();
            std::cin.clear();
        }
    } while (optiune != 0);
}

void Ui::Adaugare_Tranzactie() {
    int valoare, cantitate;
    std::cout << "Introduceti valoarea: ";
    std::cin >> valoare;
    if (valoare <= 0) {
        throw Exceptii_Ui("Valoarea tranzactiei trebuie sa fie un numar pozitiv.");
    }
    std::cout << "Introduceti cantitatea: ";
    std::cin >> cantitate;
    if (cantitate <= 0) {
        throw Exceptii_Ui("Cantitatea tranzactiei trebuie sa fie un numar pozitiv.");
    }
    service.createTranzactie(cantitate, valoare);
    std::cout << "Bani adaugati cu succes!\n";
}

void Ui::Adaugare_Bilet() {
    int cod, pret;
    char destinatie[100];
    std::cout << "Introduceti codul: ";
    std::cin >> cod;
    if (cod <= 0) {
        throw Exceptii_Ui("Codul biletului trebuie sa fie un numar pozitiv.");
    }
    std::cout << "Introduceti destinatia: ";
    std::cin.ignore();
    std::cin.getline(destinatie, 100);
    if (strlen(destinatie) == 0) {
        throw Exceptii_Ui("Destinatia biletului nu poate fi vida.");
    }
    std::cout << "Introduceti pretul: ";
    std::cin >> pret;
    if (pret <= 0) {
        throw Exceptii_Ui("Pretul biletului trebuie sa fie un numar pozitiv.");
    }
    service.createBilet(cod, destinatie, pret);
    std::cout << "Bilet adaugat cu succes!\n";
}

void Ui::Afisare_Tranzacti() {
    auto bancnote = service.readAllTranzacti();
    for (auto& bancnota : bancnote)
        std::cout << bancnota.getValoare() << "-" << bancnota.getCantitate() << "\n";
}

void Ui::Afisare_Bilete() {
    auto bilete = service.readAllBilete();
    for (auto& bilet : bilete)
        std::cout << "Cod" << bilet.getCod() << "-" << bilet.getDestinatie() << "-" << bilet.getPret() << "\n";
}

void Ui::Afisare_Suma() {
    std::cout << service.getSuma() << " lei" << "\n";
}

void Ui::Cumpara_Bilet() {
    int cantitate, valoare, rest, ok = 0, pret = 0, cod = 0;
    char destinatie[100];
    std::vector<Bilet> bilete = service.readAllBilete();
    std::cout << "Introduceti destinatia: ";
    std::cin.ignore();
    std::cin.getline(destinatie, 100);
    for (auto& bilet : bilete) {
        if (strcmp(destinatie, bilet.getDestinatie()) == 0) {
            ok = 1;
            pret = bilet.getPret();
            cod = bilet.getCod();
            break;
        }
    }
    if (ok == 0) {
        throw Exceptii_Ui("Nu exista bilete disponibile pentru destinatia introdusa.");
    } else {
        std::cout << "Cate monede introduceti: ";
        std::cin >> cantitate;
        if (cantitate <= 0) {
            throw Exceptii_Ui("Cantitatea monedelor introdusa trebuie sa fie un numar pozitiv.");
        }
        std::cout << "Care e valoarea lor: ";
        std::cin >> valoare;
        if (valoare <= 0) {
            throw Exceptii_Ui("Valoarea monedelor introdusa trebuie sa fie un numar pozitiv.");
        }
        rest = service.getSuma() - pret;
        auto verificare = service.getRest({cod, destinatie, pret});
        if (verificare) {
            std::cout << "Tranzactia a fost realizata cu success si s-a oferit un rest de: " << rest << " lei\n";
            service.createTranzactie(cantitate, valoare);
            service.deleteBilet(cod);
        } else {
            throw Exceptii_Ui("Tranzactia nu a fost realizata, rest insuficient.");
        }
    }
}

Ui::~Ui() {}
