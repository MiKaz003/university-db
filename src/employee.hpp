#pragma once
#include <iostream>
#include "person.hpp"

class Employee : public Person{
    int earnings_;

    Employee(std::string name, 
            std::string lastname, 
            std::string adress, 
            std::string pesel, 
            int earnings,
            Gender gender);

    int getEarnings() const;
    std::string show() const override;
};
