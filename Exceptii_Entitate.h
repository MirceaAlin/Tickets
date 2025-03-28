//
// Created by Ali on 21.05.2024.
//

#ifndef LABORATOR9_10_EXCEPTII_ENTITATE_H
#define LABORATOR9_10_EXCEPTII_ENTITATE_H

#include <stdexcept>

class Exceptii_Entitate: public std::runtime_error{
private:
    std::string eroare;
public:
    explicit  Exceptii_Entitate(const std::string& eroare) : std::runtime_error(eroare){
        this->eroare=eroare;
    }
};



#endif //LABORATOR9_10_EXCEPTII_ENTITATE_H
