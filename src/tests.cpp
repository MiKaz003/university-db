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
        Student ada{
            "Adrianna",
            "Kowalska",
            "ul. Warszawska 32, 62-200 Gniezno",
            456234,
            "04252354328",
            Gender::Female};
        Student adam{
            "Adam",
            "Kowalski",
            "ul. Warszawska 32, 62-200 Gniezno",
            1234523,
            "01311598778",
            Gender::Male};
        Employee adrian{
            "Adrian",
            "Marcinski",
            "ul. Warszawska 33, 62-200 Gniezno",
            7000,
            "02101867892",
            Gender::Other};
        Employee marek{
            "Marek",
            "Kowalski",
            "ul. Warszawska 28, 62-200 Gniezno",
            6200,
            "02230487651",
            Gender::Male};
        database.add(std::make_shared<Student>(ada));
        database.add(std::make_shared<Student>(adam));
        database.add(std::make_shared<Employee>(adrian));
        database.add(std::make_shared<Employee>(marek));
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
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "13252262393",
        Gender::Male};
    EXPECT_TRUE(adam.peselValidation());
}
