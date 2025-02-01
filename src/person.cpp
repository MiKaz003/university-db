#include "person.hpp"

Person::Person( std::string name,
                std::string lastname, 
                std::string adress, 
                std::string pesel, 
                Gender gender)
                : name_(name)
                , lastname_(lastname)
                , adress_(adress)
                , PESEL_(pesel)
                , gender_(gender){}