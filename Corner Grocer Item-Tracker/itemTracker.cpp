#include <iostream>
#include <fstream>
#include <map>
#include <limits>
#include <string>
//Include necessary libraries


using namespace std;
//Item tracker class
class ItemTracker {
private:
    map<string, int> itemFrequency;
    //Read input file
public:
    void readInputFile() {
        ifstream inputFile("CS210_Project_Three_Input_File.txt");
        string item;
        
        while (inputFile >> item) {
            itemFrequency[item]++;
        }

        inputFile.close();
    }
    //Get item frequency
    int getItemFrequency(const string& item) {
        return itemFrequency[item];
    }
    //Print item frequencies
    void printItemFrequencies() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    //Print item histogram
    void printItemHistogram() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    //Create backup file
    void createBackupFile() {
        ofstream backupFile("frequency.dat");

        for (const auto& pair : itemFrequency) {
            backupFile << pair.first << " " << pair.second << endl;
        }

        backupFile.close();
    }
};
//Get menu choice from user
int getMenuChoice() {
    int choice;
    cout << "Menu Options:" << endl;
    cout << "1. Look up item frequency" << endl;
    cout << "2. Print item frequencies" << endl;
    cout << "3. Print item histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    //Display error msg if user selects invalid option
    while (cin.fail() || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a valid menu option: ";
        cin >> choice;
    }

    return choice;
}
//Main function
int main() {
    ItemTracker tracker;
    tracker.readInputFile();
    
    int choice;
    do {
        choice = getMenuChoice();
       
        switch (choice) {
        case 1: {
            string item;
            cout << "Enter the item to look up: ";
            cin, item;
            int frequency = tracker.getItemFrequency(item);
            cout << "Frequency of " << item << ": " << frequency << endl;
            break;
        }
        case 2:
            tracker.printItemFrequencies();
            break;
        case 3:
            tracker.printItemHistogram();
            break;
        case 4:
            tracker.createBackupFile();
            cout << "Exiting the program. Backup file created." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}