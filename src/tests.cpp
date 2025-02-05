#include <gtest/gtest.h>
#include <memory>
#include "database.hpp"
#include "employee.hpp"
#include "person.hpp"
#include "student.hpp"

struct EmptyDBTest : ::testing::Test {
    Database database;
};

struct DBtest : ::testing::Test {
    Database database;
    void SetUp() override {
        database.addStudent("Adrianna", "Kowalska", "ul. Warszawska 32, 62-200 Gniezno", "04252354328", 456234, Gender::Female);
        database.addStudent("Adam", "Kowalski", "ul. Warszawska 32, 62-200 Gniezno", "01311598778", 1234523, Gender::Male);
        database.addEmployee("Adrian", "Marcinski", "ul. Warszawska 33, 62-200 Gniezno", "02101867892", 7000, Gender::Other);
        database.addEmployee("Marek", "Kowalski", "ul. Warszawska 28, 62-200 Gniezno", "02230487651", 6200, Gender::Male);
    };
};

TEST_F(EmptyDBTest, CanDisplayEmptyDb) {
    std::string content = database.show();
    std::string expected = "";
    EXPECT_EQ(expected, content);
}

TEST_F(EmptyDBTest, CanThrowWhileNotFound) {
    EXPECT_THROW(database.findByPESEL("00242703584"), std::runtime_error);
    EXPECT_THROW(database.findByLastName("Kowalski"), std::runtime_error);
    EXPECT_THROW(database.removeStudent(6200), std::out_of_range);
    EXPECT_THROW(database.removeEmployee("01311598778"), std::out_of_range);
    EXPECT_THROW(database.sortByPESEL(), std::runtime_error);
    EXPECT_THROW(database.sortByLastName(), std::runtime_error);
}

TEST_F(DBtest, CanFindByLastName) {
    std::string expected =
        "Student: Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 01311598778; Male. \n"
        "Employee: Marek Kowalski; ul. Warszawska 28, 62-200 Gniezno; 6200; 02230487651; Male. \n";
    auto found = database.findByLastName("Kowalski");
    EXPECT_EQ(found, expected);
}

TEST_F(DBtest, CanFindByPesel) {
    auto found = database.findByPESEL("04252354328");
    std::string expected = "Student: Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 04252354328; Female. \n";
    EXPECT_EQ(found, expected);
}

TEST_F(DBtest, CanRemove) {
    database.removeStudent(456234);
    database.removeStudent(1234523);
    database.removeEmployee("02101867892");
    database.removeEmployee("02230487651");

    EXPECT_EQ(database.show(), "");
}

TEST_F(DBtest, CanSortByPESEL) {
    auto expected =
        "Student: Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 01311598778; Male. \n"
        "Employee: Adrian Marcinski; ul. Warszawska 33, 62-200 Gniezno; 7000; 02101867892; Other. \n"
        "Employee: Marek Kowalski; ul. Warszawska 28, 62-200 Gniezno; 6200; 02230487651; Male. \n"
        "Student: Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 04252354328; Female. \n";

    database.sortByPESEL();
    EXPECT_EQ(database.show(), expected);
}

TEST_F(DBtest, CanSortByLastName) {
    auto expected =
        "Student: Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 04252354328; Female. \n"
        "Student: Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 01311598778; Male. \n"
        "Employee: Marek Kowalski; ul. Warszawska 28, 62-200 Gniezno; 6200; 02230487651; Male. \n"
        "Employee: Adrian Marcinski; ul. Warszawska 33, 62-200 Gniezno; 7000; 02101867892; Other. \n";

    database.sortByLastName();
    EXPECT_EQ(database.show(), expected);
}

TEST_F(DBtest, CanValidatePesel) {
    EXPECT_TRUE(Person::peselValidation("13252262393", Gender::Male));
    EXPECT_FALSE(Person::peselValidation("13252262393", Gender::Female));
}
