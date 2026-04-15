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

Game::Game(const vector<string>& dict) {
    dictionary = dict;
    hard_mode = false;
    lives = 0;
}

void Game::chooseDifficulty() {
    char choice;
    cout << "Play in hard mode? (y/n): ";
    cin >> choice;

    choice = tolower(choice);
    hard_mode = (choice == 'y');
}

void Game::initializeWordLength(int length) {
    possible_words = filter_size(dictionary, length);

    pattern = string(length, '-');

    if (hard_mode)
        lives = length;
    else
        lives = 5;
}

void Game::printStatus() const {
    cout << "\nPattern: " << pattern << endl;

    cout << "Guesses: ";
    for (char c : guesses) cout << c << " ";
    cout << endl;

    cout << "Misses: ";
    for (char c : misses) cout << c << " ";
    cout << endl;

    cout << "Lives: " << lives << "\n" << endl;
}

char Game::getPlayerGuess() {
    char g;
    cout << "Enter a letter: ";
    cin >> g;
    return tolower(g);
}

bool Game::alreadyGuessed(char c) const {
    return find(guesses.begin(), guesses.end(), c) != guesses.end();
}

bool Game::processGuess(char guess) {
    guesses.push_back(guess);

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

    bool revealed = (merged != pattern);

    if (!revealed) {
        lives--;
        misses.push_back(guess);
    }

    pattern = merged;
    possible_words = new_list;

    return revealed;
}

bool Game::isWin() const {
    return pattern.find('-') == string::npos;
}

bool Game::isLose() const {
    return lives <= 0;
}

void Game::play() {
    while (!isWin() && !isLose()) {
        printStatus();

        char guess = getPlayerGuess();

        if (alreadyGuessed(guess)) {
            cout << "Already guessed that letter.\n";
            continue;
        }

        processGuess(guess);
    }

    if (isWin()) {
        cout << "You win! The word was: " << pattern << endl;
    } else {
        string final_word = possible_words[rand() % possible_words.size()];
        cout << "You lose! The word was: " << final_word << endl;
    }
}