#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "person.hpp"


class Student : public Person{
    int indexNumber_;
    
public:
    Student(std::string name,
            std::string lastname,
            std::string address,
            int indexNumber,
            std::string PESEL,
            Gender gender);

    std::string show() const;
    std::string getPESEL() const;
    std::string getLastName() const;
    std::string getGender() const;
    int getIndexNumber() const;
    bool peselValidation() const;
};