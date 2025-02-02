#include "person.hpp"
#include <array>

Person::Person( std::string name,
                std::string lastname, 
                std::string adress, 
                std::string pesel, 
                Gender gender)
                : name_(name)
                , lastname_(lastname)
                , adress_(adress)
                , PESEL_(pesel)
                , gender_(gender){}

bool Person::peselValidation() const {
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


std::string Person::getGender() const {
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

std::string Person::getPESEL() const {
    return PESEL_;
}

std::string Person::getName() const {
    return name_;
}

std::string Person::getLastName() const {
    return lastname_;
}
