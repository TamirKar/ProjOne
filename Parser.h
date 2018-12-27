//Class of Parser - The parser get's the lines of text from the text. Then it creates the commands and executes them.
//the parser has 2 states: conditional and none conditional.
//in conditional state it will create the commands and send them to the conditional commands for execution.
//in the none conditional state it will create and execute the commands.

#ifndef UNTITLED16_PARSER_H
#define UNTITLED16_PARSER_H
#include <vector>
#include <string>
#include <map>
#include "Command.h"
#include <algorithm>
#include "WhileCommand.h"
#include "IfCommand.h"
#include "VarCommand.h"
#include "ShuntingYard.h"
#include "StringUtilis.h"
#include "Globals.h"
using namespace std;

/**
 * Parser
 */
class Parser {
private:
    map<string,Command *> commandsTable;
    map<string,double > symbolMap;
    bool isCondition;
    vector<vector<string>>text;
    string endCondition;
    vector<vector<string>>commandArgs;
    vector<Command *>commands;

public:
    /**
     * Parser - constructor.
     * @param symbolTable symbolTable
     * @param commandsTable commandsTable
     * @param text text
     */
    Parser( map<string, double> &symbolTable,  map<string, Command *> &commandsTable,
            vector<vector<string>> &text);

    /**
     * get Symbol Map.
     * @return map<string, double>
     */
    const map<string, double> &getSymbolMap() const;

    /**
     * Parser - another constructor.
     */
    Parser();

    /**
     * creates and executes commands based on state.
     */
    void ParseText(vector<vector<string>>);

    /**
     * special case from adding or updating variables.
     * @param text text
     * @param i int
     */
    void VarsUpdate(vector<vector<string>> text, int i);

    /**
     * creates a conditional command and send the commands to it.
     */
    void CreateCondition();

    /**
     * set Symbol Map.
     * @param symbolMap symbolMap
     */
    void setSymbolMap(const map<string, double> &symbolMap);
};

#endif //UNTITLED16_PARSER_H