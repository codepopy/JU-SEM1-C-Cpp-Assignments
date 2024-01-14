#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

void addRecord(const string& filename);
void viewAllRecords(const string& filename);
void deleteRecord(const string& filename, const string& recordToDelete);
void searchRecord(const string& filename, const string& searchKey);
void updateRecord(const string& filename, const string& recordToUpdate);


int main() {
	char choice;
	string filename;
    cout<<"enter the filename : ";
    cin>>filename;
    

    do {
        cout << "\nMenu:\n";
        cout << "a) Add new record\n";
        cout << "b) View all records\n";
        cout << "c) Delete particular record\n";
        cout << "d) Search record\n";
        cout << "e) Update record\n";
        cout << "x) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                addRecord(filename);
                break;
            case 'b':
                viewAllRecords(filename);
                break;
            case 'c':
                {
                    string recordToDelete;
                    cout << "Enter the record to delete: ";
                    cin.ignore();
                    getline(cin, recordToDelete);
                    deleteRecord(filename, recordToDelete);
                }
                break;
            case 'd':
                {
                    string searchKey;
                    cout << "Enter the search key: ";
                    cin.ignore();
                    getline(cin, searchKey);
                    searchRecord(filename, searchKey);
                }
                break;
            case 'e':
                {
                    string recordToUpdate;
                    cout << "Enter the record to update: ";
                    cin.ignore();
                    getline(cin, recordToUpdate);
                    updateRecord(filename, recordToUpdate);
                }
                break;
            case 'x':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'x');

    return 0;
}

// Function to add a new record to the file
void addRecord(const string& filename) {
    ofstream outFile(filename.c_str(), ios::app);

    if (!outFile.is_open()) {
        cerr << "Error opening the file for writing.\n";
        exit(EXIT_FAILURE);
    }

    string newRecord;
    cout << "Enter the new record (tab-separated): ";
    cin.ignore();
    getline(cin, newRecord);

    outFile << newRecord << "\n";
    cout << "Record added successfully.\n";

    outFile.close();
}

// Function to view all records from the file
void viewAllRecords(const string& filename) {
    ifstream inFile(filename.c_str());

    if (!inFile.is_open()) {
        cerr << "Error opening the file for reading.\n";
        exit(EXIT_FAILURE);
    }

    string record;
    cout << "\nAll Records:\n";
    while (getline(inFile, record)) {
        cout << record << endl;
    }

    inFile.close();
}

// Function to delete a particular record from the file
void deleteRecord(const string& filename, const string& recordToDelete) {
    ifstream inFile(filename.c_str());
    ofstream tempFile("temp.txt");

    if (!inFile.is_open() || !tempFile.is_open()) {
        cerr << "Error opening files for reading/writing.\n";
        exit(EXIT_FAILURE);
    }

    string record;
    bool recordFound = false;

    while (getline(inFile, record)) {
        if (record != recordToDelete) {
            tempFile << record << "\n";
        } else {
            recordFound = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    if (recordFound) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

// Function to search for a particular record in the file
void searchRecord(const string& filename, const string& searchKey) {
    ifstream inFile(filename.c_str());

    if (!inFile.is_open()) {
        cerr << "Error opening the file for reading.\n";
        exit(EXIT_FAILURE);
    }

    string record;
    bool recordFound = false;

    while (getline(inFile, record)) {
        if (record.find(searchKey) != string::npos) {
            cout << "Record found:\n" << record << endl;
            recordFound = true;
            break;  // Break after finding the first occurrence
        }
    }

    inFile.close();

    if (!recordFound) {
        cout << "Record not found.\n";
    }
}

// Function to update a particular record in the file
void updateRecord(const string& filename, const string& recordToUpdate) {
    ifstream inFile(filename.c_str());
    ofstream tempFile("temp.txt");

    if (!inFile.is_open() || !tempFile.is_open()) {
        cerr << "Error opening files for reading/writing.\n";
        exit(EXIT_FAILURE);
    }

    string record;
    bool recordFound = false;

    while (getline(inFile, record)) {
        if (record != recordToUpdate) {
            tempFile << record << "\n";
        } else {
            string updatedRecord;
            cout << "Enter the updated record (tab-separated): ";
            cin.ignore();
            getline(cin, updatedRecord);
            tempFile << updatedRecord << "\n";
            recordFound = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    if (recordFound) {
        cout << "Record updated successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

