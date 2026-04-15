//
// Created by spiderasasen on 4/15/26.
//

#include "filters.h"

//imports
#include <iostream>
#include <random>
#include <string>
#include <vector>

//calling another file
#include "fileCheck.h"

using namespace std;

//filter via size
vector<string> filter_size(const vector<string>& lines, int size) {
    vector<string> new_list;

    //loop that will check the size of the word inside of the list
    for (const auto & line : lines) {
        if (line.size() == size) {
            new_list.push_back(line);
        }
    }
    return new_list;
}