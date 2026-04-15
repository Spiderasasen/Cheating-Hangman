//
// Created by spiderasasen on 4/15/26.
//

#include "filters.h"

//imports
#include <iostream>
#include <string>
#include <vector>
#include <map>

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

/*getting a random letter from the alphabet and using the system to filter via certin areas of the word
 * will return words with the certin specificatens are met depending on what the word filter says
 */

//function that creates and holds a pattern of words
string build_pattern(const string& word, char guess) {
    string pattern;

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == guess) {
            pattern.push_back(guess);
        } else {
            pattern.push_back('-');
        }
    }

    return pattern;
}


//filtering via the random letter
vector<string> filtering_via_word(const vector<string>& words, char guess) {
    map<string, vector<string>> families;

    // Build families
    for (const auto& word : words) {
        string pattern = build_pattern(word, guess);
        families[pattern].push_back(word);
    }

    // Find largest family
    vector<string> largest_family;
    int max_size = 0;

    for (const auto& entry : families) {
        const vector<string>& family = entry.second;

        if (family.size() > max_size) {
            max_size = family.size();
            largest_family = family;
        }
    }

    return largest_family;
}
