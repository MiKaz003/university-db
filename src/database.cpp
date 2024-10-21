#include "database.hpp"

void Database::add(const Student& s) {
try{
    findByPESEL(s.getPESEL());
    std::cout << "Student is already added";
} catch(const std::runtime_error& e){
     BodyDb_.push_back(s); 
     std::cout << "Student added successfully";
    }
 }

 void Database::display() const {
    std::cout << show() << std::endl;
}


std::string Database::show() const {
    std::string result;
    for (auto && student : BodyDb_){
        result += student.show();
    }
    return result;
}

const Student& Database::findByPESEL(const std::string& PESEL) const {
    for(auto && student : BodyDb_) {
        if (student.getPESEL() == PESEL){
            return student;
        }
    }
    throw std::runtime_error("Student not found");
}

