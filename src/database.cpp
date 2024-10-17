#include "database.hpp"

bool Database::add(const Student& s) {
    if (!isAdded_) {
        isAdded_ = true;
        return true;
    } else {
        return false;
    }
}

void Database::display() const {
    std::cout << show() << std::endl;
}

std::string Database::show() const {
    return "";
}