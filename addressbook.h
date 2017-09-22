/**
 addressbook, addressbook.h
 Purpose: Header file forAddressbook program

 @author E. Chimienti
 @version 0.1 28/03/17
 */

#pragma once

#include <string>
#include <fstream>
#include <vector>


/*! Address Class: a class provides functionality to add an address and add that
 * to a 2 dimensional vector of vectors.
 * This class has a connection to CsvFile class to store to CSV file.
 * (comma separated file).
 */
class Address {
private:
    int m_row;
    int m_col;
    std::vector<std::vector<std::string> > m_address_book;

public:
    //! constructor
    Address(int, int);

    //! Function for adding an address to 2 dimensional vector
    void add_address(std::vector<std::string> addressLine);

    //! Function for adding csv header, naming the csv fields
    void add_header(std::vector<std::string> csvHeader);

    //! Function for getting m_address_book vector
    std::vector< std::vector<std::string> > get_m_address_book() { return m_address_book; }
};
