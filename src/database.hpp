#pragma once
#include <vector>
#include "student.hpp"
#include <memory>
#include "employee.hpp"
#include "person.hpp"

class Database {
    std::vector<std::shared_ptr<Person>> BodyDb_;

public:
    void addStudent(const std::string& name, const std::string& lastname, const std::string& adress, const std::string& pesel, const int indexNumber, const Gender& gender);
    void addEmployee(const std::string& name, const std::string& lastname, const std::string& adress, const std::string& pesel, const int earnings, const Gender& gender);
    void display() const;
    std::string show() const;
    std::string findByPESEL(const std::string& PESEL) const;
    std::string findByLastName(const std::string& lastName) const;
    void sortByPESEL();
    void sortByLastName();
    void removeStudent(int indexNumber);
    void removeEmployee(const std::string pesel);
    void saveToFile();
    static void loadFromFile(Database& db);

};