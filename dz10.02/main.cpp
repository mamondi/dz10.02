#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> dictionary;

    ifstream inputFile("dictionary.txt");
    if (inputFile.is_open()) {
        string word, definition;
        while (getline(inputFile, word) && getline(inputFile, definition)) {
            dictionary[word] = definition;
        }
        inputFile.close();
    }

    while (true) {
        cout << "1. Search for a word" << endl;
        cout << "2. Add a word" << endl;
        cout << "3. Delete a word" << endl;
        cout << "4. Edit a word" << endl;
        cout << "5. Save dictionary" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string word;
            cout << "Enter a word: ";
            cin >> word;

            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                cout << "Meaning of the word \"" << word << "\": " << it->second << endl;
            }
            else {
                cout << "Word \"" << word << "\" not found." << endl;
            }
            break;
        }
        case 2: {
            string word, definition;
            cout << "Enter a word: ";
            cin >> word;
            cout << "Enter the definition: ";
            cin.ignore();
            getline(cin, definition);

            dictionary[word] = definition;
            cout << "Word \"" << word << "\" successfully added." << endl;
            break;
        }
        case 3: {
            string word;
            cout << "Enter a word: ";
            cin >> word;

            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                dictionary.erase(it);
                cout << "Word \"" << word << "\" successfully deleted." << endl;
            }
            else {
                cout << "Word \"" << word << "\" not found." << endl;
            }
            break;
        }
        case 4: {
            string word;
            cout << "Enter a word: ";
            cin >> word;

            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                string newDefinition;
                cout << "Enter the new definition: ";
                cin.ignore();
                getline(cin, newDefinition);

                it->second = newDefinition;
                cout << "Word \"" << word << "\" successfully edited." << endl;
            }
            else {
                cout << "Word \"" << word << "\" not found." << endl;
            }
            break;
        }
        case 5: {
            ofstream outputFile("dictionary.txt");
            if (outputFile.is_open()) {
                for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
                    outputFile << it->first << endl;
                    outputFile << it->second << endl;
                }
                outputFile.close();
                cout << "Dictionary successfully saved." << endl;
            }
            else {
                cout << "Error saving dictionary." << endl;
            }
            break;
        }
        case 0: {
            return 0;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    }

    return 0;
}