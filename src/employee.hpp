#pragma once
#include <iostream>
#include "person.hpp"

class Employee : public Person{
    int earnings_;
public:
    Employee(std::string name, 
            std::string lastname, 
            std::string adress, 
            int earnings,
            std::string pesel, 
            Gender gender);

    ~Employee() override = default;

    int getEarnings() const;
    std::string show() const override;
};
