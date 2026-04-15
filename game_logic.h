//
// Created by spide on 4/15/2026.
//

#ifndef CHEATING_HANGMAN_GAME_LOGIC_H
#define CHEATING_HANGMAN_GAME_LOGIC_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game{
private:
    vector<string> dictionary;
    vector<string> possible_words;

    vector<char> guesses;
    vector<char> misses;

    string pattern;
    int lives;
    bool hard_mode;

public:
    Game(const vector<string>& dict);

    void chooseDifficulty();
    void initializeWordLength(int length);

    void printStatus() const;
    char getPlayerGuess();
    bool alreadyGuessed(char c) const;

    bool processGuess(char guess);
    bool isWin() const;
    bool isLose() const;

    void play();
};

#endif //CHEATING_HANGMAN_GAME_LOGIC_H