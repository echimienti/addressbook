/*
 * addressbook_test.cpp
 *
 *  Created on: May 4, 2017
 *  @author: E. Chimienti
 *  @version 0.1 04/05/17
 *
 */
#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "CsvFileTest.h"
#include "addressbook.h"

using namespace std;


vector<string> an_address_entry {"Piet",
                         "Puk",
                         "Pukstraat 1",
                         "1111 PP",
                         "Pukstad",
                         "011 11111111",
                         "06123456789",
                         "pietje@puk.nl"
};

vector< vector <string> > p_address { an_address_entry };

TEST_F(CsvFileTestBase, add_addressStringTes_pos) {
    Address a(1, 8);
    a.add_address(an_address_entry);

    ASSERT_EQ(a.get_m_address_book().size(), 1) << "Size of vector should be 1";

    vector < vector<string> > addr_vector = a.get_m_address_book();

    for(int col=0; col<8; col++){
        ASSERT_EQ(p_address[0][col], addr_vector[0][col]) <<
                "Name of add_vector[0][" + to_string(col) + "] should be: "
                + p_address[0][col];
    }
}
