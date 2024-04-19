#include <iostream>
#include <vector>
#include <algorithm> // for std::transform

using namespace std;

struct List {
    string item;
};

vector<List> v1;

void clearScreen() {
    system("cls");
}

void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main() {
    while (true) {
        int choice;
        cout<< "1. Add items\n";
        cout<< "2. Search for items\n";
        cout<< "0. Exit from program\n";
        cout<< "Enter choice: ";
        cin>> choice;

        switch (choice) {
            case 1: {
                clearScreen();
                int total;
                cout << "How many items do you want to add: ";
                cin >> total;
                for (int i = 0; i < total; i++) {
                    List list;
                    cout << "Name: ";
                    cin.ignore(); // Clear input buffer
                    getline(cin, list.item);
                    v1.push_back(list);
                    cout << "Saved item: " << list.item << endl;
                }
                break;
            }
            case 2: {
                clearScreen();
                string search;
                cout << "Enter name to search: ";
                cin.ignore(); // Clear input buffer
                getline(cin, search);
                toLowerCase(search); // Convert search string to lowercase
                bool found = false;
                for (const auto& item : v1) {
                    string itemLower = item.item;
                    toLowerCase(itemLower); // Convert item string to lowercase
                    if (itemLower == search) {
                        cout << "Found: " << item.item << endl << endl;
                        found = true;
                        break; // Once found, exit the loop
                    }
                }
                if (!found) {
                    cout << "No match found." << endl << endl;
                }
                break;
            }
            case 0: {
                clearScreen();
                return 0;
            }
            default: {
                clearScreen();
                cout << "Invalid Input" << endl << endl;
                break;
            }
        }
    }
}
