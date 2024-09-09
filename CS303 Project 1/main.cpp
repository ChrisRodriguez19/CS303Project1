#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main() {
    int arr[100]; 
    int size = 0; 
    ifstream inputFile("A1input.txt");
    if (!inputFile) {
        cout << "Error: Could not open the input file." << endl;
        return 1;
    }
    // Read data from file and put it into an array
    while (inputFile >> arr[size]) {
        size++;
    }
    inputFile.close();

    string command;
    int value, index, oldValue;
    bool playing = true;
    while (playing == true) {
        cout << "Type search, modify, add, remove, or exit.";
        cout << "\nEnter command: " << endl;
        cin >> command;
        try {
            if (command == "search") {
                //Looks for a number and gives you the index
                cout << "Enter number to search: ";
                cin >> value;
                if (cin.fail()) {
                    throw invalid_argument("Value must be a number.");
                }
                index = search(arr, size, value);
                if (index != -1) {
                    cout << "Number found at index " << index << endl;
                }
                else {
                    cout << "Number not found" << endl;
                }
            }
            else if (command == "modify") {
                cout << "Enter index to modify: ";
                //changes the index that is given and changes it to a new number
                cin >> index;
                if (cin.fail()) {
                    throw invalid_argument("Index must be a number.");
                }
                cout << "Enter new value: ";
                cin >> value;
                if (cin.fail()) {
                    throw invalid_argument("Value must be a number.");
                }
                modify(arr, size, index, value, oldValue);
                cout << "Modified value. Old value: " << oldValue << ", New value: " << value << endl;
            }
            else if (command == "add") {
                //adds number to the end of the array
                cout << "Enter number to add: ";
                cin >> value;
                if (cin.fail()) {
                    throw invalid_argument("Value must be a number.");
                }
                add(arr, size, value);
                cout << "Number added." << endl;
            }
            else if (command == "remove") {
                //removes number at given index and moves everything to the left
                cout << "Enter index to remove: ";
                cin >> index;
                if (cin.fail()) {
                    throw invalid_argument("Index must number.");
                }
                remove(arr, size, index);
                cout << "Number removed." << endl;
            }
            else if (command == "exit") {
                //exit while loop
                playing = false;
                break;
            }
            else {
                cout << "Invalid! Please type search, modify, add, remove, or exit." << endl;
            }
        }
        catch (const exception& e) {
            //Catches erros and prints
            cout << "Error: " << e.what() << endl;
            //Clears the input and removes the input to allow a new one to be in
            cin.clear();
            cin.ignore();
        }
    }

    return 0;
}