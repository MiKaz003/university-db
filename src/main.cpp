#include <iostream>
#include <limits>
#include "database.hpp"
#include "employee.hpp"
#include "person.hpp"
#include "student.hpp"

int main() {
    Database database;
    int choice;
    std::string value;

    Database::loadFromFile(database);
    std::cout << "Welcome to University DataBase!" << std::endl;

    bool running = true;
    while (running) {
        std::cout << "Select option: " << std::endl;
        std::cout << "1. Add new student" << std::endl;
        std::cout << "2. Add new employee" << std::endl;
        std::cout << "3. Display DataBase" << std::endl;
        std::cout << "4. Find" << std::endl;
        std::cout << "5. Sort DataBase" << std::endl;
        std::cout << "6. Remove student" << std::endl;
        std::cout << "7. Remove employee" << std::endl;
        std::cout << "8. Save and exit program" << std::endl;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cerr << "Error! Invalid input. Please enter a number between 1 and 6\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
        case 2:
            Person::makePerson(database, choice);
            break;
        case 3:
            database.display();
            break;
        case 4:
            std::cout << "1. By lastname\n2. By PESEL\n";
            std::cin >> choice;
            switch (choice) {
            case 1:
                std::cout << "Enter lastname: ";
                std::cin >> value;
                try {
                    std::cout << database.findByLastName(value);
                } catch (const std::runtime_error& error) {
                    std::cout << "Not found\n";
                }
                break;
            case 2:
                std::cout << "Enter PESEL: ";
                std::cin >> value;
                try {
                    std::cout << database.findByPESEL(value) << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Not found\n";
                }
                break;
            default:
                std::cout << "Undefined value!";
                break;
            }
            break;
        case 5:
            std::cout << "1. By lastname\n2. By PESEL\n";
            std::cin >> choice;
            switch (choice) {
            case 1:
                database.sortByLastName();
                break;
            case 2:
                database.sortByPESEL();
                break;
            default:
                break;
            }
            break;
        case 6:
            std::cout << "Enter employee's pesel: \n";
            std::cin >> value;
            database.removeEmployee(value);
            break;
        case 7:
            int indexNumber;
            std::cout << "Enter student's index number: \n";
            std::cin >> indexNumber;
            database.removeStudent(indexNumber);
            break;
        case 8:
            database.saveToFile();
            running = false;
            break;
        default:
            std::cout << "Enter correct value!\n";
            break;
        }
    }
    return 0;
}