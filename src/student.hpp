#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

enum class Gender {
    Male,
    Female,
    Other
};

class Student {
    std::string name_;
    std::string lastname_;
    std::string address_;
    int indexNumber_;
    std::string PESEL_;
    Gender gender_;
    
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