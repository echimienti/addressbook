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


/* Function that runs the main of the program that provides to enter
 * a choice of what you wants to do
 */

int get_nr_of_columns(string filename) {
    /* Reads in the first line from the csv file and pushes the elements to
     * a vector. The length of the vector will result in nr of columns
     *
     * @param: filename: filename of csv file
     * @return: int: nr of columns
     */
    vector<string> csvColumns;
    string csvLine;
    ifstream inf(filename.c_str());

    // If we couldn't open the input file stream for reading
    if (!inf) {
        // Print an error and exit
        cerr << filename << " could not be opened for reading!" << endl;
        exit(1);
    }

    // While there's still stuff left to read
    getline(inf, csvLine, '\n');
    if (csvLine.size() != 0) {
        string element;
        stringstream csvLineStream(csvLine);

        while(std::getline(csvLineStream,element,',')){
            csvColumns.push_back(element);
        }
    }

    inf.close();

    return csvColumns.size();
}

int make_choice(char choice) {
    /* Enter choice of operation
     *
     * @param: choice: enter a choice
     */
    string filename = "address.csv";
    int row = 1;
    int col = get_nr_of_columns(filename);
    string name;
    string street;
    string zip_code;
    string town;
    string telephone_nr;
    string email_address;
    CsvFile<string> csv("address.csv", col);
    string mode_a = "app";
    string mode_in = "in";

    if (choice == 'a') {
        name = get_input("Enter name: ");
        street = get_input("Enter street: ");
        zip_code = get_input("Enter zip_code: ");
        town = get_input("Enter town: ");
        telephone_nr = get_input("Enter telephone nr: ");
        email_address = get_input("Enter email address: ");
    }

    Address address(row, col);

    address.add_address(name, street, zip_code, town, telephone_nr, email_address);

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
