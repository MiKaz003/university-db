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

TEST_F(DBtest, CanDisplayDatabase){
        Student adam {
        "Adam",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "00242703584",
        Gender::Male
    };
    database.add(adam); 
    database.add(adam);
    EXPECT_EQ(database.show(), "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 00242703584; Male");
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
    database.add(adam);
    
    auto found = database.findByLastName("Kowalski");
    EXPECT_EQ(found.show(), "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 00242703584; Male");
}

TEST_F(DBtest, CanFindByPESEL){
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
    EXPECT_EQ(found.show(), "Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 00242706584; Female");
}



