
#include <sstream>
#include "StringUtilis.h"

/**
 * CharRemover - remove a char from the string return in vector form.
 * @param str str
 * @param charToRemove charToRemove
 * @return vector<string>
 */
vector<string> StringUtilis::CharRemover(string str, char charToRemove) {
    vector<string> newVec;
    vector<string> vec;
    istringstream stream(str);
    string s;
    while (getline(stream, s, charToRemove)) {
        newVec.push_back(s);
    }
    for (int i = 0; i < newVec.size(); ++i) {
        if (newVec[i].empty()) {
            continue;
        } else {
            vec.push_back(newVec[i]);
        }
    }
    return vec;
}

/**
 * remove a char from the string, return in string form.
 * @param str str
 * @param charToRemove charToRemove
 * @return string
 */
string StringUtilis::CharRemoverStr(string str, char charToRemove) {
    vector<string> v = CharRemover(str, charToRemove);
    string s = ConvertVectorToStringWithoutSpaces(v);
    return s;
}

/**
 * ConvertVectorTostring - convert vector to string.
 * @param v v
 * @return string
 */
string StringUtilis::ConvertVectorTostring(vector<string> v) {
    string str;
    for (int i = 0; i < v.size(); ++i) {
        str += v[i] + " ";
    }
    return str;
}

/**
 * SplitString - split a string based on a splitter, return in vector form.
 * @param str str
 * @param splitter splitter
 * @return vector<string>
 */
vector<string> StringUtilis::SplitString(string str, string splitter) {
    vector<string> newVec;
    int begin = 0;
    int ending = 0;
    while ((ending = str.find(splitter, begin)) < str.size()) {
        std::string val = str.substr(begin, ending - begin);
        newVec.push_back(val);
        begin = ending + splitter.size();

    }
    if (begin < str.size()) {
        string val = str.substr(begin);
        newVec.push_back(val);
    }
    return newVec;
}

/**
 * check if a string is a number.
 * @param str str
 * @return true or false.
 */
bool StringUtilis::IsDigit(string str) {
    try {
        std::stod(str);
    }
    catch (...) {
        return false;
    }
    return true;
}

/**
 * ConvertVectorToStringWithoutSpaces - convert vector to a string, but without spaces each substring.
 * @param v v
 * @return string
 */
string StringUtilis::ConvertVectorToStringWithoutSpaces(vector<string> v) {
    string str;
    for (int i = 0; i < v.size(); ++i) {
        str += v[i];
    }
    return str;
}


