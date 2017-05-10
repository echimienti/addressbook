/**
 addressbook, addressbook.cpp
 Purpose: Addressbook program to add addresses/tel nrs and email
 addresses are written to address.csv (comma separated file)
 provides add/read/search/count entries

 @author E. Chimienti
 @version 0.1 28/03/17
 */

#include "addressbook.h"


/* Function for getting m_address_book vector
 */
void Address::add_address(string name, string street,
        string zip_code, string town, string telephone_nr,
        string email_address) {
    /* Adds an address in a row of 2 dimensional array
     *
     * @param: name: address name
     * @param: street: address street
     * @param: zip_code: address zip code
     * @param: town: address town
     * @param: telephone_nr: address telephone number
     * @param: email_address: address email address
     * @return: void
     */
    for(int i=0;i<m_row;i++) {
        vector<string> addressLine;
        for(int j=0;j<m_col;j++) {
            addressLine.push_back(name);
            addressLine.push_back(street);
            addressLine.push_back(zip_code);
            addressLine.push_back(town);
            addressLine.push_back(telephone_nr);
            addressLine.push_back(email_address);
        }
        m_address_book.push_back(addressLine);
    }
}
