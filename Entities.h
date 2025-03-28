#ifndef LABORATOR9_10_ENTITIES_H
#define LABORATOR9_10_ENTITIES_H
class Tranzactie {
private:
    int cantitate;
    int valoare;

public:
    Tranzactie();
    ~Tranzactie();
    Tranzactie(int cantitate, int valoare);
    Tranzactie(const Tranzactie &tranzactie);
    void setValoare(int valoare);
    int getValoare();
    void setCantitate(int cantitate);
    int getCantitate();
    Tranzactie& operator=(const Tranzactie& alti);
};

class Bilet{
private:
    int cod;
    char *destinatie;
    int pret;
public:
    Bilet();
    Bilet(int cod, char* destinatie, int pret);
    Bilet(const Bilet &bilet);
    ~Bilet();
    void setCod(int cod);
    int getCod();
    void setPret(int pret);
    int getPret();
    void setDestinatie(char* destinatie);
    char *getDestinatie();
    Bilet& operator=(const Bilet& altu);
};
#endif //LABORATOR9_10_ENTITIES_H
