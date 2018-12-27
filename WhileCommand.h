// Class of WhileCommand - a Conditional execute the commands while the condition is true.

#ifndef UNTITLED16_LOOPCOMMAND_H
#define UNTITLED16_LOOPCOMMAND_H

#include    "Command.h"
#include<vector>
#include <string>

/**
 * WhileCommand
 */
class WhileCommand: public Command {

private:
    vector<Command*>commands;
    vector<vector<string>>commandArgs;
    map<string,double > symbolTable;
    string boolCondition;

public:

    /**
     * execute the commands while the condition is true.
     * @param args args
     */
    void Execute(vector<string> args) override;
    WhileCommand( map<string, double> symbolTable,  string &boolCondition, const vector<Command *> &commands,
                  const vector<vector<string>> &commandArgs);

    /**
     * GetSymbolMap.
     * @return map<string, double>
     */
    map<string, double> GetSymbolMap() override;

    /**
     * setSymbolMap.
     * @param symbolMap symbolMap
     */
    void setSymbolMap(map<string, double> symbolMap) override;
};

#endif //UNTITLED16_LOOPCOMMAND_H