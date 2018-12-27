//Class of ConditionChecker - check if a given condition is true or false.
#ifndef UNTITLED16_CONDITIONCHECKER_H
#define UNTITLED16_CONDITIONCHECKER_H

#include <string>
#include <map>

using namespace std;

/**
 * ConditionChecker
 */
class ConditionChecker {

private:
    string stopCondition;
    map<string,double > symbolTable;
public:
    /**
     * set SymbolTable.
     * @param symbolTable symbolTable
     */
    void setSymbolTable(const map<string, double> &symbolTable);

public:
    /**
     * ConditionChecker - constructor.
     * @param boolCondition boolCondition
     * @param symbolTable symbolTable
     */
    ConditionChecker( string &boolCondition,  map<string, double> &symbolTable);

    /**
     * check if the condition is true
     * @return true if the condition is true, and false otherwise.
     */
    bool ConditionTrue();

    /**
     * convert the condition into a numeric one by extracting the values from the symbol table.
     * @param str str
     * @return the converted string.
     */
    string ConvertCondition(string str);


};




#endif //UNTITLED16_CONDITIONCHECKER_H