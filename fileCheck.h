//
// Created by spide on 4/14/2026.
//

#ifndef CHEATING_HANGMAN_FILECHECK_H
#define CHEATING_HANGMAN_FILECHECK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//getting the dictinary and putting it into a list
vector<string>import_files(const string& filename);

//filtering the size of the dictunary
vector<string>filter_size(const vector<string>& lines, int size);

#endif //CHEATING_HANGMAN_FILECHECK_H