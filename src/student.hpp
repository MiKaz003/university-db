#pragma once
#include <iostream>

enum class Gender {
    Male,
    Female,
    Other
};

class Student {
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

private:
    std::string name_;
    std::string lastname_;
    std::string address_;
    int indexNumber_;
    std::string PESEL_;
    Gender gender_;
};