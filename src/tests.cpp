#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

TEST(DBtest, CanItIncludeAStudent){
    Student adam {
        "Adam", 
        "Kowalski", 
        "ul. Warszawska 32, 62-200 Gniezno", 
        1234523, 
        "00242703584",
        Gender::Male
    };
    Database database;
    EXPECT_TRUE(database.add(adam));
    EXPECT_FALSE(database.add(adam));
}
 
