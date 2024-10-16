#include "database.hpp"

bool Database::add(const Student& s){
    if (!isAdded_){
        isAdded_ = true;
        return true;
    }
    else{
        return false;
    }
}