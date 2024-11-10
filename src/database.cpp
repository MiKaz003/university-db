#include "database.hpp"
#include <algorithm>

void Database::add(const Student& s) {
    try {
        findByPESEL(s.getPESEL());
        std::cout << "Student is already added \n";
    } catch (const std::runtime_error& e) {
        BodyDb_.push_back(s);
        std::cout << "Student added successfully \n";
    }
}

void Database::display() const {
    std::cout << show() << std::endl;
}

std::string Database::show() const {
    std::string result;
    for (auto&& student : BodyDb_) {
        result += student.show();
    }
    return result;
}

const Student& Database::findByPESEL(const std::string& PESEL) const {
    for (auto&& student : BodyDb_) {
        if (student.getPESEL() == PESEL) {
            return student;
        }
    }
    throw std::runtime_error("Student not found");
}

std::string Database::findByLastName(const std::string& lastName) const {
    std::string result;
    for (auto&& student : BodyDb_) {
        if (student.getLastName() == lastName) {
            result += student.show();
        }
    }
    if (!result.empty()) {
        return result;
    } else {
        throw std::runtime_error("Student not found");
    }
}

void Database::sortByPESEL() {
    if(!BodyDb_.empty()){
        std::sort(BodyDb_.begin(), BodyDb_.end(), [](const Student& s1, const Student& s2){
            return s1.getPESEL() < s2.getPESEL();
        });
    }
    else{
        throw std::runtime_error("Database is empty!");
    }
}

void Database::sortByLastName() {
    if (!BodyDb_.empty()) {
        std::sort(BodyDb_.begin(), BodyDb_.end(), [](const Student& s1, const Student& s2) {
            if (s1.getLastName() != s2.getLastName()) {
                return s1.getLastName() < s2.getLastName();
            } else {
                return s1.getPESEL() < s2.getPESEL();
            }
        });
    }
    else{
        throw std::runtime_error("Database is empty!");
    }
}

void Database::remove(int indexNumber){
    for(auto it = BodyDb_.begin(); it != BodyDb_.end(); it++){
        if(it->getIndexNumber() == indexNumber){
            BodyDb_.erase(it);
            std::cout << "Student was deleted" << std::endl;
            return;
        }
    }
    throw std::out_of_range("Student not found");
}