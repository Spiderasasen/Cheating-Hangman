//
// Created by Diego Diaz on 4/14/2026.
//

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

//imports of other classes
#include "fileCheck.h"

//New system that will be used a lot
using namespace std;

int main() {
    // getting all words from  a dictnary
    vector<string> dict = import_files("1000-most-common-words.txt");

    //getting a random word from the dicrinary
    string word = random_word(dict);
    cout << "Random Word: " << word << endl;
}