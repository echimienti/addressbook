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
    google_name,
    google_given_ame,
    google_additional_name,
    google_family_name,yomi_name,
    google_given_name_yomi,
    google_additional_name_yomi,
    google_family_name_yomi,name_prefix,
    google_name_suffix,
    google_Initials,
    google_nickname,
    google_short_name,
    google_maiden_name,
    google_birthday,
    google_gender,
    google_Location,
    google_billing_information,
    google_directory_server,
    google_mileage,
    google_occupation,
    google_hobby,
    google_sensitivity,
    google_priority,
    google_subject,
    google_notes,
    google_group_membership,
    google_e_mail_1_type,
    google_e_mail_1_value,
    google_e_mail_2_type,
    google_e_mail_2_value,
    google_phone_1_type,
    google_phone_1_value,
    google_phone_2_type,
    google_phone_2_value,
    google_phone_3_type,
    google_phone_3_value,
    google_address_1_type,
    google_address_1_formatted,
    google_address_1_street,
    google_address_1_city,
    google_address_1_po_box,
    google_address_1_region,
    google_address_1_postal_code,
    google_address_1_country,
    google_address_1_extended_address,
    google_organization_1_type,
    google_organization_1_name,
    google_organization_1_yomi_name,
    google_organization_1_title,organization_1_department,
    google_organization_1_symbol,
    google_organization_1_Location,
    google_organization_1_job_description,
    google_website_1_type,website_1_value,
    google_end
};
enum outlookColumns {
    outlook_first_name,
    outlook_middle_name,
    outlook_last_name,
    outlook_title,
    outlook_suffix,
    outlook_initials,
    outlook_web_page,
    outlook_gender,
    outlook_birthday,
    outlook_anniversary,
    outlook_location,
    outlook_language,
    outlook_internet_free_busy,
    outlook_notes,
    outlook_e_mail_address,
    outlook_e_mail_2_address,
    outlook_e_mail_3_address,
    outlook_primary_phone,
    outlook_home_phone,
    outlook_home_phone_2,
    outlook_mobile_phone,
    outlook_pager,
    outlook_home_fax,
    outlook_home_address,
    outlook_home_street,
    outlook_home_street_2,
    outlook_home_street_3,
    outlook_home_address_po_box,
    outlook_home_city,
    outlook_home_state,
    outlook_home_postal_code,
    outlook_home_country,
    outlook_spouse,
    outlook_children,
    outlook_manager_s_name,
    outlook_assistant_s_name,
    outlook_referred_by,
    outlook_company_main_phone,
    outlook_business_phone,
    outlook_business_phone_2,
    outlook_business_fax,
    outlook_assistant_s_phone,
    outlook_company,
    outlook_job_title,
    outlook_department,
    outlook_office_Location,
    outlook_organizational_id_number,
    outlook_profession,
    outlook_account,
    outlook_business_address,
    outlook_business_street,
    outlook_business_street_2,
    outlook_business_street_3,
    outlook_business_address_po_box,
    outlook_business_city,
    outlook_business_state,
    outlook_business_postal_code,
    outlook_business_country,
    outlook_other_phone,
    outlook_other_fax,
    outlook_other_address,
    outlook_other_street,
    outlook_other_street_2,
    outlook_other_street_3,
    outlook_other_address_po_box,
    outlook_other_city,
    outlook_other_state,
    outlook_other_postal_code,
    outlook_other_country,
    outlook_callback,
    outlook_car_phone,
    outlook_isdn,
    outlook_radio_phone,
    outlook_tty_tdd_phone,
    outlook_telex,
    outlook_user_1,
    outlook_user_2,
    outlook_user_3,
    outlook_user_4,
    outlook_keywords,
    outlook_mileage,
    outlook_hobby,
    outlook_billing_information,
    outlook_directory_server,
    outlook_sensitivity,
    outlook_priority,
    outlook_private,
    outlook_categories,
    outlook_end
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
    if(m_col == address_end){
        m_address_book.push_back(addressLine);
    }
    else if(m_col == outlook_end){
        vector<string> tempLine;

        //first initialize temp vector with empty lines
        for(int j=outlook_first_name;j<outlook_end;j++) {
            tempLine.push_back("");
        }

        // update with entered fields
        tempLine[outlook_first_name] = addressLine[address_first_name];
        tempLine[outlook_last_name] = addressLine[address_last_name];
        tempLine[outlook_home_street] = addressLine[address_street];
        tempLine[outlook_home_postal_code] = addressLine[address_zip_code];
        tempLine[outlook_home_city] = addressLine[address_town];
        tempLine[outlook_home_phone] = addressLine[address_telephone_number];
        tempLine[outlook_mobile_phone] = addressLine[address_mobile_phone];
        tempLine[outlook_e_mail_address] = addressLine[address_email_address];
        tempLine[outlook_priority] = "Normal";
        tempLine[outlook_categories] = "My contacts";

        m_address_book.push_back(tempLine);
    }
    else if(m_col == google_end){
        vector<string> tempLine;

        //first initialize temp vector with empty lines
        for(int j=outlook_first_name;j<google_end;j++) {
            tempLine.push_back("");
        }

        tempLine[google_name] = addressLine[address_first_name];
        tempLine[google_family_name] = addressLine[address_last_name];
        tempLine[google_address_1_street] = addressLine[address_street];
        tempLine[google_address_1_postal_code] = addressLine[address_zip_code];
        tempLine[google_address_1_city] = addressLine[address_town];
        tempLine[google_phone_1_type] = "Home";
        tempLine[google_phone_1_value] = addressLine[address_telephone_number];
        tempLine[google_phone_2_type] = "Mobile";
        tempLine[google_phone_2_value] = addressLine[address_mobile_phone];
        tempLine[google_e_mail_1_type] = "Other";
        tempLine[google_e_mail_1_value] = addressLine[address_email_address];
        tempLine[google_priority] = "Normal";
        tempLine[google_subject] = "* My contacts";

        m_address_book.push_back(tempLine);
    }
}

/* Function for adding csv header, naming the csv fields
 */
void Address::add_header(vector<string> csvHeader) {
    /* Adds header to csv file naming the csv fields
     *
     * @param: vector<string> csvHeader: name of csv header vector
     * @return: void
     */
    for(int i=0;i<m_row;i++) {
        vector<string> addressLine;
        for(int j=0;j<m_col;j++) {
            addressLine.push_back(csvHeader[j]);
        }
        m_address_book.push_back(addressLine);
    }
}
