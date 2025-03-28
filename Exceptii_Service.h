#ifndef LABORATOR9_10_Exceptii_Service_H
#define LABORATOR9_10_Exceptii_Service_H


#include <stdexcept>
#include <string>

class Exceptii_Service: public std::runtime_error{
private:
    std::string eroare;
public:
    explicit  Exceptii_Service(const std::string& eroare) : std::runtime_error(eroare){
        this->eroare=eroare;
    }
};


#endif //LABORATOR9_10_Exceptii_Service_H
