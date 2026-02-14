
---

# 💻 diary.cpp (Complete Code)

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addEntry() {
    ofstream file("diary.txt", ios::app);
    string date, content;

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> date;
    cin.ignore();

    cout << "Write your diary entry:\n";
    getline(cin, content);

    file << date << "|" << content << endl;
    file.close();

    cout << "Entry added successfully!\n";
}

void viewEntries() {
    ifstream file("diary.txt");
    string line;

    cout << "\n===== All Diary Entries =====\n";
    while (getline(file, line)) {
        int pos = line.find("|");
        string date = line.substr(0, pos);
        string content = line.substr(pos + 1);

        cout << "Date: " << date << endl;
        cout << "Entry: " << content << endl;
        cout << "-----------------------------\n";
    }

    file.close();
}

void searchEntry() {
    ifstream file("diary.txt");
    string searchDate, line;
    bool found = false;

    cout << "Enter Date to search (DD-MM-YYYY): ";
    cin >> searchDate;

    while (getline(file, line)) {
        int pos = line.find("|");
        string date = line.substr(0, pos);
        string content = line.substr(pos + 1);

        if (date == searchDate) {
            cout << "\nEntry Found:\n";
            cout << "Date: " << date << endl;
            cout << "Entry: " << content << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No entry found for this date.\n";

    file.close();
}

void deleteEntry() {
    ifstream file("diary.txt");
    ofstream temp("temp.txt");
    string deleteDate, line;
    bool found = false;

    cout << "Enter Date to delete (DD-MM-YYYY): ";
    cin >> deleteDate;

    while (getline(file, line)) {
        int pos = line.find("|");
        string date = line.substr(0, pos);

        if (date == deleteDate) {
            found = true;
            continue;
        }

        temp << line << endl;
    }

    file.close();
    temp.close();

    remove("diary.txt");
    rename("temp.txt", "diary.txt");

    if (found)
        cout << "Entry deleted successfully!\n";
    else
        cout << "No entry found for this date.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Digital Diary =====\n";
        cout << "1. Add Entry\n";
        cout << "2. View Entries\n";
        cout << "3. Search Entry\n";
        cout << "4. Delete Entry\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: deleteEntry(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
