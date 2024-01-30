#include "else.h"

int main() {
    vector<string> words;
    read_file("lorem.txt", words);

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Display text from file" << endl;
        cout << "2. See the most frequently used word" << endl;
        cout << "3. See data about the usage of all words" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            print_words_from_file();
            break;
        case 2:
            print_most_frequent_word_from_file();
            break;
        case 3:
            print_word_frequency_from_file();
            break;
        case 4:
            break; 
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);
    return 0;
}