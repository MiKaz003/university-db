#include "database.hpp"
#include <algorithm>
#include <fstream>

std::string trim(std::string& s){
    size_t first = s.find_first_not_of(' ');
    if(first == std::string::npos){
        return "";
    }
    size_t last = s.find_last_not_of(' ');
    return s.substr(first, last - first + 1);
}

void getlineTrimed(std::istringstream& stream, std::string& result, char delimiter){
    std::getline(stream, result, delimiter);
    result = trim(result);
}

void Database::add(const std::shared_ptr<Person> person) {
    try {
        findByPESEL(person->getPESEL());
        std::cout << "Student is already added \n";
    } catch (const std::runtime_error& e) {
        if(person->peselValidation()){
        BodyDb_.push_back(s);
        std::cout << "Student added successfully \n";
        }
        else{
            std::cout << "PESEL is invalid" << std::endl;
        }
    }
}

void Database::display() const {
    std::cout << show() << '\n';
}

std::string Database::show() const {
    std::string result;
    for (auto&& person : BodyDb_) {
        result += person->show();
    }
    return result;
}

std::string Database::findByPESEL(const std::string& PESEL) const {
    for (auto&& person : BodyDb_) {
        if (person->getPESEL() == PESEL) {
            return person->show();
        }
    }
    throw std::runtime_error("Student not found");
}

std::string Database::findByLastName(const std::string& lastName) const {
    std::string result;
    for (auto&& person : BodyDb_) {
        if (person->getLastName() == lastName) {
            result += person->show();
        }
    }
    if (!result.empty()) {
        return result;
    } else {
        throw std::runtime_error("Student not found");
    }
}
//TODO
void Database::sortByPESEL() {
    if(!BodyDb_.empty()){
        std::sort(BodyDb_.begin(), BodyDb_.end(), [](const Person& s1, const Person& s2){
            return s1.getPESEL() < s2.getPESEL();
        });
    }
    else{
        throw std::runtime_error("Database is empty!");
    }
}
//TODO
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

void Database::removeStudent(const int indexNumber){
   auto it = std::remove_if(BodyDb_.begin(), BodyDb_.end(), 
   [indexNumber](const std::shared_ptr<Person>& person){
    auto student = std::dynamic_pointer_cast<Student>(person);
    return student && student->getIndexNumber() == indexNumber;
   });
    if(it != BodyDb_.end()){
        std::cout << (*it)->getName() << (*it)->getLastName() << "was deleted" << std::endl;
        BodyDb_.erase(it, BodyDb_.end());
    }
    else {
        throw std::out_of_range("Student not found");
    }
}

void Database::saveToFile(){
    std::ofstream file;
    std::cout << "Saving to file...\n";
    if(BodyDb_.empty()){
        std::cout << "Database is empty!" << std::endl;
        return;
    }
    file.open("../src/.DataBase.txt");
    if(file.is_open()){
        for(auto& student : BodyDb_){
            file << student.show();
            if(file.fail()){
                std::cout << "Save failed\n";
                file.close();
                return;
            }
        }
        file.close();
        std::cout << "Saved\n";
    }
    else{
        std::cout << "File can't be opened" << std::endl;
        return;
    }
}

void Database::loadFromFile(Database& db){
    std::string name, lastname, address, indexNumber, PESEL, gender, trash;
    std::ifstream file;
    std::string line;
    std::cout << "Loading data from file...\n";
    file.open("../src/.DataBase.txt");

    if(!file.is_open()){
        throw std::runtime_error("File cannot be opened");
    }

    while(std::getline(file, line)){
        
        std::istringstream data(line);

        getlineTrimed(data, name, ' ');
        getlineTrimed(data, lastname, ';');
        getlineTrimed(data, address, ';');
        getlineTrimed(data, indexNumber, ';');
        getlineTrimed(data, PESEL, ';');
        getlineTrimed(data, gender, '.');

        Gender gen;
        int indexNum = std::stoi(indexNumber);
        if(gender == "Male"){
            gen = Gender::Male;    
        } else if(gender == "Female"){
            gen = Gender::Female;
        } else{
            gen = Gender::Other;
        }

        Student s{name, lastname, address, indexNum, PESEL, gen}; 
        db.add(s);
        }
    }
