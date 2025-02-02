#pragma once
#include <iostream>

enum class Gender {
    Male,
    Female,
    Other
};

class Person {
public:
    std::string name_;
    std::string lastname_;
    std::string adress_;
    std::string PESEL_;
    Gender gender_;

    Person( std::string name,
            std::string lastname, 
            std::string adress, 
            std::string pesel, 
            Gender gender);
    
    virtual ~Person() = default;

    virtual std::string show() const = 0;
    bool peselValidation() const;
    std::string getPESEL() const;
    std::string getName() const;
    std::string getLastName() const;
    std::string getGender() const;
};