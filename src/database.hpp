#pragma once
#include "student.hpp"

class Database{
public:
    bool add(const Student& s);

private:
    bool isAdded_;
};