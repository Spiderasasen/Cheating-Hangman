//
// Created by Diego Diaz on 4/14/2026.
//

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

//imports of other classes
#include "fileCheck.h"
#include "game_logic.h"

//New system that will be used a lot
using namespace std;

int main() {
    vector<string> dict = import_files("dictionary.txt");

    Game game(dict);

    game.chooseDifficulty();

    int length;
    cout << "Choose word length: ";
    cin >> length;

    game.initializeWordLength(length);

    game.play();
}