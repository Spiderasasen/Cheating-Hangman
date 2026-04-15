//
// Created by spiderasasen on 4/15/26.
//

#ifndef CHEATING_HANGMAN_FILTERS_H
#define CHEATING_HANGMAN_FILTERS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//filtering the size of the dictunary
vector<string>filter_size(const vector<string>& lines, int size);

vector<string> filtering_via_word(const vector<string>& lines, char letter_chossen);

#endif //CHEATING_HANGMAN_FILTERS_H