#include "employee.hpp"

Employee::Employee(std::string name, 
            std::string lastname, 
            std::string adress, 
            int earnings,
            std::string pesel, 
            Gender gender)
            : Person(name, lastname, adress, pesel, gender)
            , earnings_(earnings){};

std::string Employee::show() const {
    return "Employee: "
    + name_ + " " 
    + lastname_ + "; " 
    + adress_ + "; " 
    + std::to_string(earnings_) + "; " 
    + PESEL_ + "; " 
    + getGender() 
    + ". \n";
}