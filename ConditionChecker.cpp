
#include <sstream>
#include "ConditionChecker.h"
#include "ShuntingYard.h"
#include "Expression.h"
#include "BoolExpression.h"
#include "StringUtilis.h"

/**
 * ConditionChecker - Check if the condition is true.
 * @return true if this is the operator, and if not - returns false.
 */
bool ConditionChecker::ConditionTrue() {
    string operation;
    ShuntingYard shuntingYard;
    //check the operator of the condition
    if (this->stopCondition.find(">=") != std::string::npos) {
        operation= ">=";
    }
    if (this->stopCondition.find("<=") != std::string::npos) {
        operation= "<=";
    }
    if (this->stopCondition.find(">") != std::string::npos) {
        operation= ">";
    }
    if (this->stopCondition.find("<") != std::string::npos) {
        operation= "<";
    }
    if (this->stopCondition.find("==") != std::string::npos) {
        operation= "==";
    }
    if (this->stopCondition.find("!=") != std::string::npos) {
        operation= "!=";
    }
    //split the condition into two expressions by their operation
    vector<string> expressionsVec = StringUtilis::SplitString(stopCondition,operation);
    string leftExpStr = expressionsVec[0];
    string rightExpStr = expressionsVec[1];
    //convert the condition into a numeric one by extracting the values from the symbol table.
    leftExpStr=ConvertCondition(leftExpStr);
    rightExpStr=ConvertCondition(rightExpStr);
    //use shuntingYard to calculate the expressions
    Expression * leftExp = shuntingYard.Calculate(leftExpStr);
    Expression * rightExp = shuntingYard.Calculate(rightExpStr);
    //evaluate if the condition is true and return result
    BoolExpression * boolExpression = new BoolExpression(leftExp,rightExp,operation);
    return boolExpression->Evaluate();
}

/**
 * constructor of ConditionChecker.
 * @param boolCondition boolCondition
 * @param symbolTable symbolTable
 */
ConditionChecker::ConditionChecker( string &boolCondition,  map<string, double> &symbolTable) : stopCondition(
        boolCondition), symbolTable(symbolTable) {}

/**
 * convert the condition into a numeric one by extracting the values from the symbol table.
 * @param str str
 * @return string
 */
string ConditionChecker::ConvertCondition(string str) {
    for (std::map<string, double>::iterator it = symbolTable.begin(); it != symbolTable.end(); ++it){
        if (str.find(it->first) != std::string::npos) {
            //find the var in the map
            int index = str.find(it->first);
            //create sub strings exculding the var
            string leftSubStr = str.substr(0, index);
            string rightSubStr = str.substr(index + it->first.length());
            //get the var's value in string form
            ostringstream strstream;
            strstream << it->second;
            string valFromMap = strstream.str();
            //return the new string with the extracted value
            string convertedString = leftSubStr + valFromMap + rightSubStr;
            str = convertedString;
        }
    }
    return str;
}

/**
 * set SymbolTable.
 * @param symbolTable symbolTable
 */
void ConditionChecker::setSymbolTable(const map<string, double> &symbolTable) {
    ConditionChecker::symbolTable = symbolTable;
}
