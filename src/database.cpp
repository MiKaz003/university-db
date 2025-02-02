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

void Database::add(const std::shared_ptr<Person>& person) {
    try {
        findByPESEL(person->getPESEL());
        std::cout << "Student is already added \n";
    } catch (const std::runtime_error& e) {
        if(person->peselValidation()){
        BodyDb_.push_back(person);
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

void Database::sortByPESEL() {
    if(!BodyDb_.empty()){
        std::sort(BodyDb_.begin(), BodyDb_.end(), 
            [](const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2){
            return p1->getPESEL() < p2->getPESEL();
        });
    }
    else{
        throw std::runtime_error("Database is empty!");
    }
}

void Database::sortByLastName() {
    if (!BodyDb_.empty()) {
        std::sort(BodyDb_.begin(), BodyDb_.end(), 
            [](const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2) {
            if (p1->getLastName() != p2->getLastName()) {
                return p1->getLastName() < p2->getLastName();
            } else {
                return p1->getPESEL() < p2->getPESEL();
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

void Database::removeEmployee(const std::string pesel){
    auto it = std::remove_if(BodyDb_.begin(), BodyDb_.end(), 
        [pesel](const std::shared_ptr<Person>& person){
            auto employee = std::dynamic_pointer_cast<Employee>(person);
            return employee && employee->getPESEL() == pesel;
    }); 
    if (it != BodyDb_.end()) {
        std::cout << "Employee" << (*it)->name_ << (*it)->lastname_ << "was deleted" << std::endl;
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
        for(auto& person : BodyDb_){
            if(auto student = std::dynamic_pointer_cast<Student>(person)){
                file << "Student:" << person->show();
            }
            else if(auto employee = std::dynamic_pointer_cast<Employee>(person)){
                file << "Employee:" << person->show();
            } 
            else{
                std::cerr << "Unknown type" << std::endl;
            }
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
    std::string type, name, lastname, address, indexNumber, PESEL, gender, trash;
    std::ifstream file;
    std::string line;
    std::cout << "Loading data from file...\n";
    file.open("../src/.DataBase.txt");

    if(!file.is_open()){
        throw std::runtime_error("File cannot be opened");
    }

    while(std::getline(file, line)){
        
        std::istringstream data(line);

        getlineTrimed(data, type, ':');
        getlineTrimed(data, name, ' ');
        getlineTrimed(data, lastname, ';');
        getlineTrimed(data, address, ';');
        getlineTrimed(data, indexNumber, ';');
        getlineTrimed(data, PESEL, ';');
        getlineTrimed(data, gender, '.');

        Gender gen;
        int indexNum = std::stoi(indexNumber);
        int earnings = indexNum;

        if(gender == "Male"){
            gen = Gender::Male;    
        } else if(gender == "Female"){
            gen = Gender::Female;
        } else{
            gen = Gender::Other;
        }
        
        if(type == "Student"){
            Student s{name, lastname, address, indexNum, PESEL, gen};
            std::shared_ptr<Person> P = std::make_shared<Student>(s); 
            db.add(P);
        }
        else if(type == "Employee"){
            Employee e{name, lastname, address, PESEL, earnings, gen};
            std::shared_ptr<Person> P = std::make_shared<Employee>(e); 
            db.add(P);
        }
        else{
            continue;
        }
    }
}
