#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

void read_file(string file_name, vector<string>& words) {
    ifstream file(file_name);
    string word;

    while (file >> word) {
        words.push_back(word);
    }

    file.close();
}

void print_words_from_file() {
    ifstream file("lorem.txt");
    string word;

    cout << "Text from file:" << endl;

    while (file >> word) {
        cout << word << " ";
    }

    cout << endl;

    file.close();
}

void print_most_frequent_word_from_file() {
    ifstream file("lorem.txt");
    string word;

    map<string, int> words_map;

    while (file >> word) {
        words_map[word]++;
    }

    file.close();

    int max = 0;
    string max_word;

    for (const auto& entry : words_map) {
        if (entry.second >= max) {
            max = entry.second;
            max_word = entry.first;
        }
    }

    cout << "Most frequent word: " << max_word << endl;
}

void print_word_frequency_from_file() {
    ifstream file("lorem.txt");
    string word;

    map<string, int> words_map;

    while (file >> word) {
        words_map[word]++;
    }

    file.close();

    cout << "Word frequencies:" << endl;
    for (const auto& entry : words_map) {
        cout << entry.first << ": " << entry.second << endl;
    }
}