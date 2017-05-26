/**
 addressbook, addressbook.cpp
 Purpose: Addressbook program to add addresses/tel nrs and email
 addresses are written to address.csv (comma separated file)
 provides add/read/search/count entries

 @author E. Chimienti
 @version 0.1 28/03/17
 */

#include "addressbook.h"


enum googleColumns {
    google_first_name,
    google_middle_name,
    google_last_name,
    google_title,
    google_suffix,
    google_initials,
    google_web_page,
    google_gender,
    google_birthday,
    google_anniversary,
    google_location,
    google_language,
    google_internet_free_busy,
    google_notes,
    google_e_mail_address,
    google_e_mail_2_address,
    google_e_mail_3_address,
    google_primary_phone,
    google_home_phone,
    google_home_phone_2,
    google_mobile_phone,
    google_pager,
    google_home_fax,
    google_home_address,
    google_home_street,
    google_home_street_2,
    google_home_street_3,
    google_home_address_po_box,
    google_home_city,
    google_home_state,
    google_home_postal_code,
    google_home_country,
    google_spouse,
    google_children,
    google_manager_s_name,
    google_assistant_s_name,
    google_referred_by,
    google_company_main_phone,
    google_business_phone,
    google_business_phone_2,
    google_business_fax,
    google_assistant_s_phone,
    google_company,
    google_job_title,
    google_department,
    google_office_Location,
    google_organizational_id_number,
    google_profession,
    google_account,
    google_business_address,
    google_business_street,
    google_business_street_2,
    google_business_street_3,
    google_business_address_po_box,
    google_business_city,
    google_business_state,
    google_business_postal_code,
    google_business_country,
    google_other_phone,
    google_other_fax,
    google_other_address,
    google_other_street,
    google_other_street_2,
    google_other_street_3,
    google_other_address_po_box,
    google_other_city,
    google_other_state,
    google_other_postal_code,
    google_other_country,
    google_callback,
    google_car_phone,
    google_isdn,
    google_radio_phone,
    google_tty_tdd_phone,
    google_telex,
    google_user_1,
    google_user_2,
    google_user_3,
    google_user_4,
    google_keywords,
    google_mileage,
    google_hobby,
    google_billing_information,
    google_directory_server,
    google_sensitivity,
    google_priority,
    google_private,
    google_categories,
    google_end
};

enum addressColumns {
    address_first_name,
    address_last_name,
    address_street,
    address_zip_code,
    address_town,
    address_telephone_number,
    address_mobile_phone,
    address_email_address,
    address_end
};

/* Function for getting m_address_book vector
 */
void Address::add_address(vector<string> addressLine) {
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
    if(m_col == 8){
        m_address_book.push_back(addressLine);
    }
    else if(m_col == google_end){
        vector<string> tempLine;

        //first initialize temp vector with empty lines
        for(int j=google_first_name;j<google_end;j++) {
            tempLine.push_back("");
        }

        // update with entered fields
        tempLine[google_first_name] = addressLine[address_first_name];
        tempLine[google_last_name] = addressLine[address_last_name];
        tempLine[google_home_street] = addressLine[address_street];
        tempLine[google_home_postal_code] = addressLine[address_zip_code];
        tempLine[google_home_city] = addressLine[address_town];
        tempLine[google_home_phone] = addressLine[address_telephone_number];
        tempLine[google_mobile_phone] = addressLine[address_mobile_phone];
        tempLine[google_e_mail_address] = addressLine[address_email_address];
        tempLine[google_priority] = "Normal";
        tempLine[google_categories] = "My contacts";

        m_address_book.push_back(tempLine);
    }
}

void Address::add_header(vector<string> csvHeader) {
    for(int i=0;i<m_row;i++) {
        vector<string> addressLine;
        for(int j=0;j<m_col;j++) {
            addressLine.push_back(csvHeader[j]);
        }
        m_address_book.push_back(addressLine);
    }
}
