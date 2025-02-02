#include <iostream>
#include <limits>
#include "database.hpp"
#include "student.hpp"
#include "person.hpp"
#include "employee.hpp"

std::shared_ptr<Person> makeStudent() {
    std::string name, lastname, address, PESEL, gender;
    int indexNumber;
    std::cout << "Enter name: \n";
    std::cin >> name;
    std::cout << "Enter lastname: \n";
    std::cin >> lastname;
    std::cout << "Ender address: \n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, address);
    std::cout << "Enter index number: \n";
    std::cin >> indexNumber;
    std::cout << "Enter PESEL: \n";
    std::cin >> PESEL;
    std::cout << "Enter gender: \n";
    std::cin >> gender;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Gender gen;
    if (gender == "Male") {
        gen = Gender::Male;
    } else if (gender == "Female") {
        gen = Gender::Female;
    } else {
        gen = Gender::Other;
    }
    Student s(name, lastname, address, indexNumber, PESEL, gen);
    std::shared_ptr<Person> p = std::make_shared<Student>(s);
    return p;
}

int main() {
    Database database;
    int option, choice;
    std::string value;

    Database::loadFromFile(database);
    std::cout << "Welcome to University DataBase!" << std::endl;

    bool running = true;
    while (running) {
        std::cout << "Select option: " << std::endl;
        std::cout << "1. Add new student" << std::endl;
        std::cout << "2. Display DataBase" << std::endl;
        std::cout << "3. Find student" << std::endl;
        std::cout << "4. Sort DataBase" << std::endl;
        std::cout << "5. Remove student" << std::endl;
        std::cout << "6. Save and exit program" << std::endl;
        std::cin >> option;

        if (std::cin.fail()) {
            std::cerr << "Error! Invalid input. Please enter a number between 1 and 6\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (option) {
        case 1:
            database.add(makeStudent());
            break;
        case 2:
            database.display();
            break;
        case 3:
            std::cout << "1. By lastname\n2. By PESEL\n";
            std::cin >> choice;
            switch (choice) {
            case 1:
                std::cout << "Enter lastname: ";
                std::cin >> value;
                try {
                    std::cout << database.findByLastName(value);
                } catch (const std::runtime_error& e) {
                    std::cout << "Student not found\n";
                }
                std::cin.ignore();
                break;
            case 2:
                std::cout << "Enter PESEL: ";
                std::cin >> value;
                try {
                    std::cout << database.findByPESEL(value) << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Student not found\n";
                }
                std::cin.ignore();
                break;
            default:
                std::cout << "Undefined value!";
                break;
            }
            break;
        case 4:
            std::cout << "1. By lastname\n2. By PESEL\n";
            std::cin >> choice;
            switch (choice) {
            case 1:
                database.sortByLastName();
                std::cin.ignore();
                break;
            case 2:
                database.sortByPESEL();
                std::cin.ignore();
                break;
            default:
                break;
            }
            break;
        case 5:
            int indexNumber;
            std::cout << "Enter student's index number: \n";
            std::cin >> indexNumber;
            database.removeStudent(indexNumber);
            std::cin.ignore();
            break;
        case 6:
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