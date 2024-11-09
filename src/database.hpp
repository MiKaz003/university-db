#pragma once
#include <vector>
#include "student.hpp"

class Database {
public:
    void add(const Student& s);
    void display() const;
    std::string show() const;
    const Student& findByPESEL(const std::string& PESEL) const;
    std::string findByLastName(const std::string& lastName) const;
    std::string sortByPESEL();
    std::string sortByPESEL(std::vector<Student>&);
    std::string sortByLastName();

private:
    std::vector<Student> BodyDb_;
};