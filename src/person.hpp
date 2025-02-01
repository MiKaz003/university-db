#include <iostream>

enum class Gender {
    Male,
    Female,
    Other
};

class Person {
protected:
    std::string name_;
    std::string lastname_;
    std::string adress_;
    std::string PESEL_;
    Gender gender_;

    Person( std::string name,
            std::string lastname, 
            std::string adress, 
            std::string pesel, 
            Gender gender);

    
};