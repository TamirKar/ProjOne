
#include <sstream>
#include "Lexer.h"
#include <algorithm>
#include "StringUtilis.h"

/**
 * Lexer
 * @param fileName fileName
 * @return vector<vector<string>>
 */
vector<vector<string>> Lexer::GetFileLines(const char *fileName) {
    vector<vector<string>> vec;
    string line;
    ifstream infile;
    infile.open(fileName);
    //lines are splitted by /n and then added to a vector of strings.
    while (!infile.eof()) {
        getline(infile, line);
        if (line.size() != 0) {
            //remove additional '\' for the bind command
            if (line.find("bind") != std::string::npos) {
                line = StringUtilis::CharRemoverStr(line, '\"');
            }
            //add spaces for equal operator.
            if (line.find('=') != std::string::npos
                && !(line.find("==") != std::string::npos
                     || line.find("!=") != std::string::npos
                     || line.find(">=") != std::string::npos
                     || line.find("<=") != std::string::npos)) {
                int i = line.find("=");
                string str1 = line.substr(0, i);
                string str2 = line.substr(i+1, line.size());
                line = str1 + " = " + str2;
            }
            //remove any ','
            line = StringUtilis::CharRemoverStr(line, ',');
            //remove spaces and add to vector.
            vector<string> v = StringUtilis::CharRemover(line, ' ');
            vec.push_back(v);
        }
    }
    infile.close();
    return vec;
}












