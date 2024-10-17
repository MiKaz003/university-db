#pragma once
#include "student.hpp"

class Database {
public:
    bool add(const Student& s);
    void display() const;
    std::string show() const;

private:
    bool isAdded_;
};