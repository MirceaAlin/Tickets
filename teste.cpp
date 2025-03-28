#include "Entities.h"
#include "Repo.h"
#include "Service.h"
#include <cassert>
#include <iostream>
#include "teste.h"
#include <string.h>

    void test_Bilet() {

        char* destinatie = "New York";
        Bilet b2(1001, destinatie, 500);
        assert(b2.getCod() == 1001);
        assert(b2.getPret() == 500);
        assert(strcmp(b2.getDestinatie(), destinatie) == 0);

        Bilet b3 = b2;
        assert(b3.getCod() == 1001);
        assert(b3.getPret() == 500 );
        assert(strcmp(b3.getDestinatie(), destinatie) == 0);

        b3.setCod(2002);
        assert(b3.getCod() == 2002);

        b3.setPret(700);
        assert(b3.getPret() == 700);

        char* newDest = "Los Angeles";
        b3.setDestinatie(newDest);
        assert(strcmp(b3.getDestinatie(), newDest) == 0);

        Bilet b4;
        b4 = b3;
        assert(b4.getCod() == 2002 );
        assert(b4.getPret() == 700 );
        assert(strcmp(b4.getDestinatie(), newDest) == 0);
    }

    void test_Tranzactie() {
        Tranzactie t2(10, 100);
        assert(t2.getCantitate() == 10 );
        assert(t2.getValoare() == 100);

        Tranzactie t3 = t2;
        assert(t3.getCantitate() == 10);
        assert(t3.getValoare() == 100);


        t3.setCantitate(20);
        assert(t3.getCantitate() == 20);

        t3.setValoare(200);
        assert(t3.getValoare() == 200);

        Tranzactie t4;
        t4 = t3;
        assert(t4.getCantitate() == 20 );
        assert(t4.getValoare() == 200 );
    }

void test_Repo_Tranzactie() {
    Repo_Tranzactie repo;
    Tranzactie t1(100, 10);
    repo.addItem(t1);
    assert(repo.getSize() == 1);

    assert(repo.modificareTranzactie(100, 5) == false);
    assert(repo.modificareTranzactie(200, 5) == false);

    assert(repo.eraseBancnota(100, 3) == false);
    assert(repo.eraseBancnota(100, 3) == false);

    assert(repo.getSuma() == 1000);
    repo.eraseBancnota(10,98);
    assert(repo.getAll()[0].getCantitate()==2);
}

void test_Repo_Bilete() {
    Repo_bilete repo;
    Bilet b1(1, "New York", 500);
    repo.addItem(b1);
    assert(repo.getSize() == 1);

    Bilet b2(2, "Los Angeles", 700);
    assert(repo.modificareBilet(0, b2) == true);
    assert(repo.modificareBilet(1, b2) == false);

    assert(repo.eraseBilet(1) == false);
}

void test_Service() {
    Repo_Tranzactie repoTranzactie;
    Repo_bilete repoBilete;
    Service service(repoTranzactie, repoBilete);

    service.createBilet(1, "Destination1", 100);
    assert(service.readAllBilete().size() == 1);

    service.createTranzactie(10, 50);
    assert(service.readAllTranzacti().size() == 1);

    service.deleteBilet(1);
    assert(service.readAllBilete().size() == 0);

    service.deleteTranzactie(50, 5);

    assert(service.getSuma() == 250);

    service.createTranzactie(2, 10);
    service.createTranzactie(3, 20);
    service.createTranzactie(5, 50);

    assert(service.getRest(Bilet(2, "Test", 120)) == false);
}
