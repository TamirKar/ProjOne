//Class of StringUtilis - contains static methods of string manipulation.

#ifndef UNTITLED16_STRINGUTILIS_H
#define UNTITLED16_STRINGUTILIS_H

#include <vector>
#include <string>
using namespace std;

/**
 * StringUtilis
 */
class StringUtilis {
public:
    /**
     * remove a char from the string return in vector form
     * @param str
     * @param charToRemove
     * @return
     */
    static vector<string>CharRemover(string str,char charToRemove);
    /**
     *convert vector to string
     * @param str
     * @param charToRemove
     * @return
     */
    static string CharRemoverStr(string str,char charToRemove);
    /**
     * convert vector to string but without spaces each substring
     * @return string
     */
    static string ConvertVectorTostring(vector<string>);
    /**
     * convert vector to string
     * @return vector
     */
    static string ConvertVectorToStringWithoutSpaces(vector<string>);
    /**
     * split a string based on a splitter return in vector form.
     * @param str
     * @param splitter
     * @return
     */
    static  vector<string>SplitString(string str,string splitter);
    /**
     * check if a string is a number
     * @param str
     * @return
     */
    static bool IsDigit(string str);

};

#endif //UNTITLED16_STRINGUTILIS_H