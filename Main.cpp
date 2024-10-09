#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to add a new password
void addPassword() {
    ofstream outfile;
    outfile.open("passwords.txt", ios::app); // Open the file in append mode

    string website, username, password;
    cout << "Enter website: ";
    cin >> website;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Write the information to the file
    outfile << website << " " << username << " " << password << endl;
    outfile.close();
    cout << "Password added successfully!" << endl;
}

// Function to retrieve and display stored passwords
void viewPasswords() {
    ifstream infile;
    infile.open("passwords.txt");

    string website, username, password;
    cout << "\nStored Passwords:\n";
    cout << "-----------------\n";
    while (infile >> website >> username >> password) {
        cout << "Website: " << website << ", Username: " << username << ", Password: " << password << endl;
    }
    infile.close();
}

int main() {
    int choice;

    while (true) {
        cout << "\nPassword Manager\n";
        cout << "1. Add Password\n";
        cout << "2. View Passwords\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}