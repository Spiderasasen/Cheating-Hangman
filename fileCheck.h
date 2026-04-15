//
// Created by Diego Diaz on 4/14/2026.
//

#ifndef CHEATING_HANGMAN_FILECHECK_H
#define CHEATING_HANGMAN_FILECHECK_H

#include <string>
#include <vector>

using namespace std;

//getting the dictinary and putting it into a list
vector<string>import_files(const string& filename);

//getting a random word
string random_word(const vector<string>& lines);

#endif //CHEATING_HANGMAN_FILECHECK_H