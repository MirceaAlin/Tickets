#ifndef LABORATOR9_10_EXCEPTII_REPO_H
#define LABORATOR9_10_EXCEPTII_REPO_H


#include <stdexcept>
#include <string>

class Exceptii_Repo: public std::runtime_error{
private:
    std::string eroare;
public:
    explicit  Exceptii_Repo(const std::string& eroare) : std::runtime_error(eroare){
        this->eroare=eroare;
    }
};


#endif //LABORATOR9_10_EXCEPTII_REPO_H
