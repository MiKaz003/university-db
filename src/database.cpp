#include "database.hpp"

void Database::add(const Student& s) {
try{
    findByPESEL(s.getPESEL());
    std::cout << "Student is already added \n";
} catch(const std::runtime_error& e){
     BodyDb_.push_back(s); 
     std::cout << "Student added successfully \n";
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

std::string Database::findByLastName(const std::string& lastName) const{
    std::string result;
    for(auto && student : BodyDb_) {
        if (student.getLastName() == lastName){
            result += student.show();
        }
    }
    if(!result.empty()){
        return result;
    }   else {
    throw std::runtime_error("Student not found");
    }
}

void Database::sortByPESEL(){
    std::vector<Student> suppStruct;
    suppStruct.reserve(BodyDb_.size());
    std::string result;
    if(!BodyDb_.empty()){
        for(auto& student : BodyDb_){
            auto it = suppStruct.begin();
            while(it != suppStruct.end() && it->getPESEL() < student.getPESEL()){
                it++;
            }
            suppStruct.insert(it, student);
        }
    }
    else{
        std::cout << "Database is empty \n";
        }
    std::swap(BodyDb_, suppStruct);
}

