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

std::string Student::show() const {
    return name_ + " " 
    + lastname_ + "; " 
    + address_ + "; " 
    + std::to_string(indexNumber_) + "; " 
    + PESEL_ + "; " 
    + getGender() 
    + ". \n";
}

std::string Student::getGender() const {
    switch (gender_) {
    case Gender::Male:
        return "Male";
    case Gender::Female:
        return "Female";
    case Gender::Other:
        return "Other";
    default:
        return "Unknown";
    }
}

bool Student::peselValidation() const {
    // len
    if (PESEL_.length() != 11) {
        std::cout << "Pesel should have 11 characters" << std::endl;
        return false;
    }
    // digits
    for (char c : PESEL_) {
        if (isdigit(c - '0')) {
            std::cout << "Every char should be a number" << std::endl; 
            return false;
        }
    }
    // gender
    if (gender_ != Gender::Other) {
        switch (PESEL_[9] % 2) {
        case 0:
            if (gender_ == Gender::Male) {
                std::cout << "Gender";
                return false;
                break;
            };
            break;
        case 1:
            if (gender_ == Gender::Female) {
                std::cout << "Gender";
                return false;
                break;
            };
        }
    }
    //control sum
    std::array<int, 10> weights = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sum = 0;
    for (int i = 0; i < 10; i++){
        sum += ((PESEL_[i] - '0') * weights[i]);
    }
    if (10 - sum % 10 != PESEL_[10] - '0'){
        std::cout << "Sum";
        return false;
    }
    return true;
}

std::string Student::getPESEL() const {
    return PESEL_;
}

std::string Student::getLastName() const {
    return lastname_;
}

int Student::getIndexNumber() const {
    return indexNumber_;
}

