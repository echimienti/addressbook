/*
 * main.cpp
 *
 *  Created on: May 5, 2017
 *
 *  @author E. Chimienti
 *  @version 0.1 05/05/17
 */
#include "addressbook.h"
#include "libcsvfile/csvfile.h"


vector<string> get_csv_header_line(string filename) {
    /* Reads in the first line from the csv file and pushes the elements to
     * a vector. The length of the vector will result in nr of columns
     *
     * @param: filename: filename of csv file
     * @return: int: nr of columns
     */
    string csvLine;
    ifstream inf(filename.c_str());
    vector<string> csvHeaderLine;

    // If we couldn't open the input file stream for reading
    if (!inf) {
        // Print an error and exit
        cerr << filename << " is not present!" << endl;
        return csvHeaderLine;
    }

    // While there's still stuff left to read
    getline(inf, csvLine, '\n');
    if (csvLine.size() != 0) {
        string element;
        stringstream csvLineStream(csvLine);

        while(std::getline(csvLineStream,element,',')){
            csvHeaderLine.push_back(element);
        }
    }

    inf.close();

    return csvHeaderLine;
}

/* Function that runs the main of the program that provides to enter
 * a choice of what you wants to do
 */
int make_choice(char choice) {
    /* Enter choice of operation
     *
     * @param: choice: enter a choice
     */
    string filename = "address.csv";
    vector<string> csvHeader = get_csv_header_line(filename);
    int row = 1;
    bool no_csv_header = false;

    if(csvHeader.size() == 0){
        csvHeader.push_back("First Name");
        csvHeader.push_back("Last Name");
        csvHeader.push_back("Street");
        csvHeader.push_back("Zip Code");
        csvHeader.push_back("Town");
        csvHeader.push_back("Telephone number");
        csvHeader.push_back("Mobile Phone");
        csvHeader.push_back("Email address");

        no_csv_header = true;
    }

    int col = csvHeader.size();
    CsvFile<string> csv("address.csv", col);
    string mode_a = "app";
    string mode_in = "in";
    vector<string> addressLine;

    Address address(row, col);

    if(no_csv_header){
        address.add_header(csvHeader);
    }

    if (choice == 'a') {
        addressLine.push_back(get_input("Enter first name:"));
        addressLine.push_back(get_input("Enter last name:"));
        addressLine.push_back(get_input("Enter street:"));
        addressLine.push_back(get_input("Enter zip_code:"));
        addressLine.push_back(get_input("Enter town:"));
        addressLine.push_back(get_input("Enter telephone nr:"));
        addressLine.push_back(get_input("Enter mobile phone:"));
        addressLine.push_back(get_input("Enter email address:"));

        address.add_address(addressLine);
    }

    CsvFile<string> csv_a(filename, address.get_m_address_book(), col);

    switch (choice) {
        case 'a': {
            string confirm = get_input("Confirm add y/n:");

            if (confirm == "y") {
                csv_a.write_file(mode_a);
            } else {
                cout << "Will not write address to database file!" << endl;
            }
            break;
        }
        case 'p': {
            csv.read_file();
            csv.print_entries();
            break;
        }
        case 's': {
            csv.read_file();
            csv.search_entry(get_input("Search for: "));
            break;
        }
        case 'n': {
            csv.read_file();
            cout << "Addressbook has " << csv.count_vector_rows() << " entries" << endl;
            break;
        }
        case 'm': {
            csv.read_file();
            csv.delete_modify("modify", "address(es)");
            csv.write_file(mode_in);
            break;
        }
        case 'd': {
            csv.read_file();
            csv.delete_modify("delete", "address(es)");
            csv.write_file(mode_in);
            break;
        }
        case 'b': {
            csv.backup_data();
            break;
        }
        case 'r': {
            csv.restore_data();
            break;
        }
    }

    return 0;
}

int main() {
    char choice;

    do {
        cout << endl << "Enter a to add and write an address to addressbook"
                << endl;
        cout << "Enter p to print all addresses from addressbook" << endl;
        cout << "Enter s to search from addressbook" << endl;
        cout << "Enter n for number of entries in addressbook" << endl;
        cout << "Enter m for modifying entries in addressbook" << endl;
        cout << "Enter d for delete entries in addressbook" << endl;
        cout << "Enter b for backup addressbook" << endl;
        cout << "Enter r for restore addressbook" << endl;
        cout << "Enter q or Q to quit" << endl << endl;

        cin >> choice;
        cin.ignore(32767, '\n');
        make_choice(choice);
    } while (!(choice == 'q' || choice == 'Q'));

    return 0;
}
