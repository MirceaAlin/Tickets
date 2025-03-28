//#include "RepoFiletranzactie.h"
//#include "Repo.h"
//#include "RepoFileBilet.h"
//#include <fstream>
//#include <iostream>
//
//RepoFileBani::RepoFileBani() {}
//
//RepoFileBani::RepoFileBani(const char *fName) {
//    this->fileName = fName;
//    std::ifstream f(fName);
//    int cantitate,valoare;
//    while (f >> cantitate >> valoare) {
//        Tranzactie tranzactie(cantitate,valoare);
//        items.push_back(tranzactie);
//    }
//    f.close();
//}
//
//void RepoFileBani::saveFile() {
//    std::ofstream f(fileName);
//    for (const auto &tranzactie: items) {
//        f << tranzactie.getValoare() << "-" << tranzactie.getCantitate() <<"\n";
//    }
//    f.close();
//}
//
//void RepoFileBani::add(tranzactie &b) {
//    fileELems.push_back(b);
//    saveToFile();
//}
//
//void RepoFileBani::readFromFile() {
//    ifstream f(fileName);
//    if (!f) {
//        cerr << "Nu s-a putut deschide fisierul " << fileName << endl;
//        return;
//    }
//    fileELems.clear();
//    int cod;
//    char destinatie[100];
//    int pret;
//    while (f >> cod >> destinatie >> pret) {
//        tranzactie b(cod, destinatie, pret);
//        fileELems.push_back(b);
//    }
//    f.close();
//}
//
//void RepoFileBani::writeToFile() {
//    ofstream fileOutput(fileName);
//
//    if (!fileOutput.is_open()) {
//        cerr << "Nu s-a putut deschide fisierul " << fileName << " pentru scriere." << endl;
//        return;
//    }
//    for (const auto &tranzactie: fileELems) {
//        fileOutput << tranzactie.get_cod() << " " << tranzactie.get_destinatie() << " " << tranzactie.get_pret() << endl;
//    }
//    fileOutput.close();
//}
//
//RepoFileBani::~RepoFileBani() {
//    saveFile();
//}