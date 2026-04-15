//
// Created by spide on 4/15/2026.
//

#include "game_logic.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "filters.h"

using namespace std;

//constructor
Game::Game(const vector<string>& dict) {
    dictionary = dict;
    hard_mode = false;
    lives = 0;
}

//game diffculty for the class
void Game::chooseDifficulty() {
    char choice;
    cout << "Play in hard mode? (y/n): ";
    cin >> choice;

    choice = tolower(choice);
    hard_mode = (choice == 'y');
}

//sets the word length of the class
void Game::initializeWordLength(int length) {
    possible_words = filter_size(dictionary, length);

    pattern = string(length, '-');

    //little mini mechanic
    if (hard_mode) //if hard mode is avilible, then whatever the length of the word, is the number of lives the user has
        lives = length;
    else
        lives = 5;
}

//prints the status of the game
void Game::printStatus() const {
    //current pattern of the game
    cout << "\nPattern: " << pattern << endl;

    //what guesses the user entered
    cout << "Guesses: ";
    for (char c : guesses) cout << c << " ";
    cout << endl;

    //what letters where misses
    cout << "Misses: ";
    for (char c : misses) cout << c << " ";
    cout << endl;

    //number of lives that exist
    cout << "Lives: " << lives << "\n" << endl;
}

//gets the number of guesses from the user
char Game::getPlayerGuess() {
    char g;
    cout << "Enter a letter: ";
    cin >> g;
    return tolower(g);
}

//checks if the user has already guessed the letter
bool Game::alreadyGuessed(char c) const {
    return find(guesses.begin(), guesses.end(), c) != guesses.end();
}

//handels the players guess
bool Game::processGuess(char guess) {
    guesses.push_back(guess);

    //for cheating
    vector<string> new_list = filtering_via_word(possible_words, guess);

    // Build pattern from any word in the new list
    string new_pattern = build_pattern(new_list[0], guess);

    // Merge patterns
    string merged = pattern;
    for (int i = 0; i < merged.size(); i++) {
        if (new_pattern[i] != '-') {
            merged[i] = new_pattern[i];
        }
    }

    //checks if the guess revails something, and if it doesn't, it removes a life
    bool revealed = (merged != pattern);
    if (!revealed) {
        lives--;
        misses.push_back(guess);
    }

    //updates the pattern and also updates the possible list of words
    pattern = merged;
    possible_words = new_list;

    return revealed;
}

//checking if the user won the game, by looking if there are no '-'
bool Game::isWin() const {
    return pattern.find('-') == string::npos;
}

//checks if the user lost
bool Game::isLose() const {
    return lives <= 0;
}

//main game system that plays the game
void Game::play() {
    //loops until the user wins or not
    while (!isWin() && !isLose()) {
        printStatus();

        char guess = getPlayerGuess();

        if (alreadyGuessed(guess)) {
            cout << "Already guessed that letter.\n";
            continue;
        }

        processGuess(guess);
    }

    //checks if the user wins
    if (isWin()) {
        cout << "You win! The word was: " << pattern << endl;
    }
    //else the user lost
    else {
        string final_word = possible_words[rand() % possible_words.size()];
        cout << "You lose! The word was: " << final_word << endl;
    }
}