#include <iostream>
#include "teste.h"
#include "Ui.h"
#include "Repo.h"
#include "Service.h"
int main() {
    test_Bilet();
    test_Tranzactie();
    std::cout << "S-a executat Entitatea\n";
    test_Repo_Bilete();
    test_Repo_Tranzactie();
    std::cout << "S-a executat Repo\n";
    test_Service();
    std::cout << "S-a executat Service\n";
    Repo_Tranzactie repoTranzactie;
    Repo_bilete repoBilete;
    Service service(repoTranzactie,repoBilete);
    Ui ui(service);
    ui.run();
}