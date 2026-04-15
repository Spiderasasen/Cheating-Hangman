//
// Created by Diego Diaz on 4/14/2026.
//

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

//imports of other classes
#include "fileCheck.h"
#include "filters.h"

//New system that will be used a lot
using namespace std;

int main() {
    // getting all words from  a dictnary
    vector<string> dict = import_files("1000-most-common-words.txt");

    //getting a random word from the dicrinary
    string word = random_word(dict);
    cout << "Random Word: " << word << endl;

    //getting a gist of the word from just getting the length of the word
    vector<string> possibale_words = filter_size(dict, word.size());

    //doing the main game logic
    bool result = true;

    //asking for diffculty
    char choice;
    cout << "would you like to play in hard difficulty(y/n): ";
    cin >> choice;

    choice = tolower(choice);

    do {
        int lives = 0;
        //number of tries a player has
        if (choice == 'y') {
            lives = word.size();
        }
        else {
            lives = 5;
        }

        cout << "How many lives you got: " << lives << endl;

        //getting the size of the word
        for (char letter : word) {
            cout << "_";
        }
        cout << "\n" << endl;

        //amount of guess and letters you missed
        vector<string> guesses;
        vector<string> missed_words;

        //displaying the vectors
        cout << "Your Guesses: " << endl;
        for (auto i : guesses) {
            cout << i << ", ";
        }
        cout << endl;

        cout << "Letters that are missed: " << endl;
        for (auto i : missed_words) {
            cout << i << ", ";
        }
        cout << endl;

        //entering a letter
        char letter_entered;
        cout << "Please enter a letter: ";
        cin >> letter_entered;

        //filterig out via the letter and the size of the word
        vector<string> test = filtering_via_word(possibale_words, letter_entered);

    }while (result);
}