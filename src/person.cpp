#include "person.hpp"
#include <array>
#include <limits>

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

Gender Person::strToGender(const std::string& genderStr) {
    if (genderStr == "Male") {
        return Gender::Male;
    }
    if (genderStr == "Female") {
        return Gender::Female;
    }
    return Gender::Other;
}

void Person::getPersonalData(std::string& name, std::string& lastname, std::string& adress, std::string& pesel, Gender& gender) {
    std::string genderStr;

    std::cout << "Enter name: \n";
    std::cin >> name;
    std::cout << "Enter lastname: \n";
    std::cin >> lastname;
    std::cout << "Ender address: \n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, adress);
    std::cout << "Enter PESEL: \n";
    std::cin >> pesel;
    std::cout << "Enter gender: \n";
    std::cin >> genderStr;

    gender = strToGender(genderStr);
}

void Person::makePerson(Database& database, int choice) {
    std::string name, lastname, adress, pesel, genderStr;
    int value;
    Gender gender;

    getPersonalData(name, lastname, adress, pesel, gender);

    if (choice == 1) {
        std::cout << "Enter student's index number: \n";
        std::cin >> value;
        database.addStudent(name, lastname, adress, pesel, value, gender);
        return;
    } else {
        std::cout << "Enter employee's earnings: \n";
        std::cin >> value;
        database.addEmployee(name, lastname, adress, pesel, value, gender);
    }
}

bool Person::peselValidation(const std::string& pesel, const Gender& gender) {
    // len
    if (pesel.length() != 11) {
        std::cout << "Pesel should have 11 characters" << std::endl;
        return false;
    }
    // digits
    for (char c : pesel) {
        if (isdigit(c - '0')) {
            std::cout << "Every char should be a number" << std::endl; 
            return false;
        }
    }
    // gender
    if (gender != Gender::Other) {
        switch (pesel[9] % 2) {
        case 0:
            if (gender == Gender::Male) {
                std::cout << "Gender is incorrect\n";
                return false;
                break;
            };
            break;
        case 1:
            if (gender == Gender::Female) {
                std::cout << "Gender is incorrect\n";
                return false;
                break;
            };
        }
    }
    //control sum
    std::array<int, 10> weights = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sum = 0;
    for (int i = 0; i < 10; i++){
        sum += ((pesel[i] - '0') * weights[i]);
    }
    if (10 - sum % 10 != pesel[10] - '0'){
        std::cout << "Control sum is incorrect!\n";
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
