#include <iostream>
#include "database.hpp"
#include "student.hpp"

int main(){
       Database database;

        Student adam {
        "Adam",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "00242703584",
        Gender::Male
    };
    Student adrian {
        "Adrian",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "00242703884",
        Gender::Male
    };
    database.add(adam);
    database.add(adrian);
    std::string expected = "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 00242703584; Male. \n"
                           "Adrian Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 00242703884; Male. \n";

    auto found = database.findByLastName("Kowalski");
    std::cout << found << std::endl;
    std::cout << expected << std::endl;
    return 0;
}