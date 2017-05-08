/**
 addressbook, addressbook.h
 Purpose: Header file forAddressbook program

 @author E. Chimienti
 @version 0.1 28/03/17
 */

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <string>
#include <fstream>
#include <vector>


using namespace std;

int get_address(char choice);

/*! Address Class: a class provides functionality to add an address and add that
 * to a 2 dimensional vector of vectors.
 * This class has a connection to CsvFile class to store to CSV file.
 * (comma separated file).
 */
class Address {
private:
    int m_row;
    int m_col;
    vector<vector<string> > m_address_book;

public:
    //! constructor
    Address(int row, int col)
        : m_row(row), m_col(col)
    {
       vector< vector<string> > m_address_book(m_row, vector<string>(m_col));
    }

    //! Function for adding an address to 2 dimensional vector
    void add_address(string name, string street,
                string zip_code, string town, string telephone_nr,
                string email_address);

    //! Function for getting m_address_book vector
    vector< vector<string> > get_m_address_book() { return m_address_book; }
};

#endif
