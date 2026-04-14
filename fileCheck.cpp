//
// Created by Diego Diaz on 4/14/2026.
//

#include "fileCheck.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//gets a list and returns a list of strings from a dictionary
vector<string> import_files(const string& filename) {
    vector<string> lines;
    ifstream file(filename);

    //file never opened
    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return lines;
    }

    //puts all the words into the list
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}