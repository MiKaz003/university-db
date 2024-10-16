#pragma once
#include <iostream>

enum class Gender{
    Male,
    Female, 
    Other
};

class Student{
public:
    Student(std::string name,
            std::string lastname,
            std::string address,
            int indexNumber,
            std::string PESEL, 
            Gender gender);

private: 
    Gender g_;
};