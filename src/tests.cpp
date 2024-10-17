#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DBtest : ::testing::Test {
    Database database;
};

TEST_F(DBtest, CanAddStudents) {
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "00242703584",
        Gender::Male};
    EXPECT_TRUE(database.add(adam));
    EXPECT_FALSE(database.add(adam));
}

TEST_F(DBtest, CanDisplayEmptyDb) {
    std::string content = database.show();
    std::string expected = "";
    EXPECT_EQ(expected, content);
}

// TEST(DBtest, CanDisplayDatabase){
//     Database database;
//         Student adam {
//         "Adam",
//         "Kowalski",
//         "ul. Warszawska 32, 62-200 Gniezno",
//         1234523,
//         "00242703584",
//         Gender::Male
//     };
//     database.add(adam);
//     EXPECT_EQ(database.show(), ( "Adam",
//                                 "Kowalski",
//                                 "ul. Warszawska 32, 62-200 Gniezno",
//                                 1234523,
//                                 "00242703584",
//                                 Male));
// }
