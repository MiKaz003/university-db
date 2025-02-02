#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"
#include "person.hpp"
#include "employee.hpp"
#include <memory>

struct DBtest : ::testing::Test {
    Database database;
    void SetUp() override {
        Student ada {
                    "Adrianna",
                    "Kowalska",
                    "ul. Warszawska 32, 62-200 Gniezno",
                    456234,
                    "04252354328",
                    Gender::Female
                };
        Student adam {
                    "Adam",
                    "Kowalski",
                    "ul. Warszawska 32, 62-200 Gniezno",
                    1234523,
                    "01311598778",
                    Gender::Male
                };
        Student adrian {
                    "Adrian",
                    "Marcinski",
                    "ul. Warszawska 33, 62-200 Gniezno",
                    456254,
                    "02101867892",
                    Gender::Other
                };
        Student marek {
                    "Marek",
                    "Kowalski",
                    "ul. Warszawska 28, 62-200 Gniezno",
                    852325,
                    "02230487651",
                    Gender::Male
                };
        database.add(std::make_shared<Student>(ada));
        database.add(std::make_shared<Student>(adam));
        database.add(std::make_shared<Student>(adrian));
        database.add(std::make_shared<Student>(marek));
    };
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
        "01311598778",
        Gender::Male
    };
    Student adrian {
        "Adrian",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "02101867892",
        Gender::Male
    };
    database.add(adam);
    database.add(adrian);
    std::string expected = "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 01311598778; Male. \n"
                           "Adrian Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 02101867892; Male. \n";
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
    database.remove(456234);
    EXPECT_EQ(found, "Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 00242706584; Female. \n");
    EXPECT_THROW(database.remove(123123), std::out_of_range);
    EXPECT_EQ(database.show(), "");
}

TEST_F(DBtest, CanSortByPESEL){
    EXPECT_THROW(database.sortByPESEL(), std::runtime_error);
    database.add(marek);
    database.add(adrian);
    database.add(adam);
    database.add(ada);
    auto expected = "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 01311598778; Male. \n"
                    "Adrian Marcinski; ul. Warszawska 33, 62-200 Gniezno; 456254; 02101867892; Other. \n"
                    "Marek Kowalski; ul. Warszawska 28, 62-200 Gniezno; 852325; 02230487651; Male. \n"
                    "Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 04252354328; Female. \n";
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
        "04252354328",
        Gender::Female
    };
    Student adam {
        "Adam",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "01311598778",
        Gender::Male
    };
    Student adrian {
        "Adrian",
        "Marcinski",
        "ul. Warszawska 33, 62-200 Gniezno",
        456254,
        "02101867892",
        Gender::Other
    };
    Student marek {
        "Marek",
        "Kowalski",
        "ul. Warszawska 28, 62-200 Gniezno",
        852325,
        "02230487651",
        Gender::Male
    };
    database.add(marek);
    database.add(adrian);
    database.add(adam);
    database.add(ada);
    auto expected = "Adrianna Kowalska; ul. Warszawska 32, 62-200 Gniezno; 456234; 04252354328; Female. \n"
                    "Adam Kowalski; ul. Warszawska 32, 62-200 Gniezno; 1234523; 01311598778; Male. \n"
                    "Marek Kowalski; ul. Warszawska 28, 62-200 Gniezno; 852325; 02230487651; Male. \n"
                    "Adrian Marcinski; ul. Warszawska 33, 62-200 Gniezno; 456254; 02101867892; Other. \n";
    database.sortByLastName();
    EXPECT_EQ(database.show(), expected);
}

TEST_F(DBtest, CanValidatePesel){
        Student adam {
        "Adam",
        "Kowalski",
        "ul. Warszawska 32, 62-200 Gniezno",
        1234523,
        "13252262393",
        Gender::Male
    };
    EXPECT_TRUE(adam.peselValidation());
}
