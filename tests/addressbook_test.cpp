/*
 * addressbook_test.cpp
 *
 *  Created on: May 4, 2017
 *  @author: E. Chimienti
 *  @version 0.1 04/05/17
 *
 */
#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "../addressbook.cpp"
#include "../csvfile.cpp"

using namespace std;

vector<string> an_entry {"Piet Puk",
                           "Pukstraat 1",
                           "1111 PP",
                           "Pukstad",
                           "011 11111111",
                           "pietje@puk.nl"
};

vector< vector <string> > an_address { an_entry };

string system_cmd_output() {
    ifstream inf("out.txt");
    string line;
    string act_line;

    while (!inf.eof()) {
        getline(inf, line, '\n');
        if (line.size() != 0) {
            act_line = line;
        }
    }
    inf.close();

    return act_line;
}

void clean_test_files() {
    // if test files exist delete them first
    const int test_file_exist = system("ls test.csv > /dev/null 2>&1");
    if(test_file_exist == 0) {
        system("rm test.csv");
    }

    const int out_file_exist = system("ls out.txt > /dev/null 2>&1");
    if(out_file_exist == 0) {
        system("rm out.txt");
    }
}

TEST(add_addressTest, add_addressPos) {
    Address a(1, 6);
    a.add_address("Piet Puk",
                  "Pukstraat 1",
                  "1111 PP",
                  "Pukstad",
                  "011 11111111",
                  "pietje@puk.nl");

    ASSERT_EQ(a.get_m_address_book().size(), 1) << "Size of vector should be 1";

    vector < vector<string> > addr_vector = a.get_m_address_book();

    for(int col=0; col<6; col++){
        ASSERT_EQ(addr_vector[0][col], an_address[0][col]) <<
                "Name of add_vector[0][" + to_string(col) + "] should be: "
                + an_address[0][col];
    }
}

TEST(csv_write_read_fileTest, csv_write_readPos) {

    clean_test_files();

    CsvFile csv("test.csv", an_address);
    csv.write_file("app");
    vector < vector<string> > csv_vector = csv.get_m_csv_vector();

    system("wc -l test.csv|cut -d\" \" -f1 > out.txt"); // execute the linux command

    string act_lines = system_cmd_output();

    ASSERT_EQ(csv.get_m_csv_vector().size(), 1) << "Expected 1 row written/read";
    ASSERT_EQ(act_lines, "1") << "Expected 1 row written/read";

    CsvFile csv_r("test.csv");
    csv_r.read_file();

    ASSERT_EQ(csv.count_vector_rows(), 1) << "Size of vector should be 1";

    clean_test_files();
}

TEST(csv_search_fileTest, csv_search_Pos) {
    clean_test_files();

    CsvFile csv("test.csv", an_address);
    csv.write_file("in");
    string expected_found = "Piet Puk";
    string search_found = csv.search_entry("Puk");

    ASSERT_EQ(search_found, expected_found) << "Did not find Pietje Puk";

    clean_test_files();
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
