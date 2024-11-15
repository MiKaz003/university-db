#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DBtest : ::testing::Test {
    Database database;
};

TEST_F(DBtest, CanDisplayEmptyDb) {
    std::string content = database.show();
    std::string expected = "";
    EXPECT_EQ(expected, content);
}

TEST_F(DBtest, CanThrowWhileNotFound){
    EXPECT_THROW(database.findByPESEL("00242703584"), std::runtime_error);
    EXPECT_THROW(database.findByLastName("Kowalski"), std::runtime_error);
}

TEST_F(DBtest, CanFindByLastName){
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
    EXPECT_EQ(found, expected);
}

TEST_F(DBtest, CanFindByPESELAndRemove){
        Student ada {
        "Adrianna",
        "Kowalska",
        "ul. Warszawska 32, 62-200 Gniezno",
        456234,
        "00242706584",
        Gender::Female
    };
    database.add(ada);

    auto found = database.findByPESEL("00242706584");
    EXPECT_EQ(found.show(), "Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 00242706584; Female. \n");
    EXPECT_THROW(database.remove(123123), std::out_of_range);
    database.remove(456234);
    EXPECT_EQ(database.show(), "");
}

TEST_F(DBtest, CanSortByPESEL){
    EXPECT_THROW(database.sortByPESEL(), std::runtime_error);
    Student ada {
        "Adrianna",
        "Kowalska",
        "ul. Warszawska 32, 62-200 Gniezno",
        456234,
        "00242702584",
        Gender::Female
    };
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
        "Marcinski",
        "ul. Warszawska 33, 62-200 Gniezno",
        456254,
        "04242701584",
        Gender::Other
    };
    Student marek {
        "Marek",
        "Kowalski",
        "ul. Warszawska 28, 62-200 Gniezno",
        852325,
        "04222309524",
        Gender::Male
    };
    database.add(marek);
    database.add(adrian);
    database.add(adam);
    database.add(ada);
    auto expected = "Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 00242702584; Female. \n"
                    "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 00242703584; Male. \n"
                    "Marek Kowalski; ul. Warszawska 28, 62-200 Gniezno; 852325; 04222309524; Male. \n"
                    "Adrian Marcinski; ul. Warszawska 33, 62-200 Gniezno; 456254; 04242701584; Other. \n";
    database.sortByPESEL();
    EXPECT_EQ(database.show(), expected);
}

TEST_F(DBtest, CanSortByLastName){
    EXPECT_THROW(database.sortByLastName(), std::runtime_error);
    Student ada {
        "Adrianna",
        "Kowalska",
        "ul. Warszawska 32, 62-200 Gniezno",
        456234,
        "00242702584",
        Gender::Female
    };
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
        "Marcinski",
        "ul. Warszawska 33, 62-200 Gniezno",
        456254,
        "04242701584",
        Gender::Other
    };
    Student marek {
        "Marek",
        "Kowalski",
        "ul. Warszawska 28, 62-200 Gniezno",
        852325,
        "04222309524",
        Gender::Male
    };
    database.add(adam);
    database.add(ada);
    database.add(marek);
    database.add(adrian);
    auto expected = "Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 00242702584; Female. \n"
                    "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 00242703584; Male. \n"
                    "Marek Kowalski; ul. Warszawska 28, 62-200 Gniezno; 852325; 04222309524; Male. \n"
                    "Adrian Marcinski; ul. Warszawska 33, 62-200 Gniezno; 456254; 04242701584; Other. \n";
    database.sortByLastName();
    EXPECT_EQ(database.show(), expected);
}

