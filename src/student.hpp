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
            std::string adress,
            int indexNumber,
            std::string PESEL,
            Gender gender);
    ~Student() override = default;
    std::string show() const override;
    int getIndexNumber() const;
};