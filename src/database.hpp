#pragma once
#include <vector>
#include "student.hpp"

class Database {
public:
    void add(const Student& s);
    void display() const;
    std::string show() const;
    const Student& findByPESEL(const std::string& PESEL) const;
    const Student& findByLastName(const std::string& lastName) const;

private:
    std::vector<Student> BodyDb_;
};