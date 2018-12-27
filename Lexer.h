
//Class of Lexer - The Lexer gets the lines from the text given and passes it to the parser.
#ifndef UNTITLED16_LEXER_H
#define UNTITLED16_LEXER_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * Lexer
 */
class Lexer {

public:

    /**
     * get the lines from the text.
     * @param fileName fileName
     * @return vector<vector<string>>
     */
    vector<vector<string>> GetFileLines(const char * fileName);
};

#endif //UNTITLED16_LEXER_H