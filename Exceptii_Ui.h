#ifndef LABORATOR9_10_EXCEPTII_Ui_H
#define LABORATOR9_10_EXCEPTII_Ui_H


#include <stdexcept>
#include <string>

class Exceptii_Ui: public std::runtime_error{
private:
    std::string eroare;
public:
    explicit  Exceptii_Ui(const std::string& eroare) : std::runtime_error(eroare){
        this->eroare=eroare;
    }
};


#endif //LABORATOR9_10_EXCEPTII_Ui_H
