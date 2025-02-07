#pragma once
#include <iostream>
#include "database.hpp"

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

    static Gender strToGender(const std::string& genderStr);
    static void getPersonalData(std::string& name, std::string& lastname, std::string& adress, std::string& pesel, Gender& gender);
    static void makePerson(Database& database, int choice);
    virtual std::string show() const = 0;
    static bool peselValidation(const std::string& pesel, const Gender& gender);
    std::string getPESEL() const;
    std::string getName() const;
    std::string getLastName() const;
    std::string getGender() const;
};