#include "student.hpp"

Student::Student(std::string name,
                 std::string lastname,
                 std::string address,
                 int indexNumber,
                 std::string PESEL,
                 Gender gender)

    : name_(name)
    , lastname_(lastname)
    , address_(address)
    , indexNumber_(indexNumber)
    , PESEL_(PESEL)
    , gender_(gender) {}

std::string Student::show() const{
    return name_ + " " 
    + lastname_ + "; " 
    + address_ + "; " 
    + std::to_string(indexNumber_) + "; " 
    + PESEL_ + "; " 
    + "Male"; 
}
    
std::string Student::getPESEL() const{
    return PESEL_;
}

std::string Student::getLastName() const {
    return lastname_;
}