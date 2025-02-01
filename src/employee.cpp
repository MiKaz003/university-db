#include "employee.hpp"

Employee::Employee(std::string name, 
            std::string lastname, 
            std::string adress, 
            std::string pesel, 
            int earnings,
            Gender gender)
            : Person(name, lastname, adress, pesel, gender)
            , earnings_(earnings){};

std::string Employee::show() const {
    return name_ + " " 
    + lastname_ + "; " 
    + adress_ + "; " 
    + std::to_string(earnings_) + "; " 
    + PESEL_ + "; " 
    + getGender() 
    + ". \n";
}