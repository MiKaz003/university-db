#include "student.hpp"

Student::Student(std::string name,
                 std::string lastname,
                 std::string adress,
                 int indexNumber,
                 std::string PESEL,
                 Gender gender)
    : Person(name, lastname, adress, PESEL, gender)
    , indexNumber_(indexNumber)
 {}

std::string Student::show() const {
    return "Student: " 
    + name_ + " " 
    + lastname_ + "; " 
    + adress_ + "; " 
    + std::to_string(indexNumber_) + "; " 
    + PESEL_ + "; " 
    + getGender() 
    + ". \n";
}

int Student::getIndexNumber() const {
    return indexNumber_;
}

