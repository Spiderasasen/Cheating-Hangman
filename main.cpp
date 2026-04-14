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
    cout << "Getting the dictunary list" << endl;
    vector<string> dict = import_files("1000-most-common-words.txt");
    cout << dict.size() << endl;

    cout << "getting the dictunary words with 5 letters in the word" << endl;
    vector<string> words = filter_size(dict, 5);
    cout << words.size() << endl;

    cout << "getting a random word from the dictunary" << endl;
    string word = random_word(dict);
    cout << word << endl;
}