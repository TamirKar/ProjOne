// Class of IfCommand - a Conditional execute the commands if the condition is true.
#ifndef UNTITLED16_IFCOMMAND_H
#define UNTITLED16_IFCOMMAND_H
#include "Command.h"
#include<vector>
#include <map>
#include <string>

/**
 * IfCommand.
 */
class IfCommand :public Command{

public:

    /**
     * execute the commands if the condition is true.
     * @param args args
     */
    void Execute(vector<string> args) override;

    /**
     * IfCommand - constructor.
     * @param symbolTable symbolTable
     * @param boolCondition boolCondition
     * @param commands commands
     * @param commandArgs commandArgs
     */
    IfCommand( map<string, double> &symbolTable,  string &boolCondition,  vector<Command *> &commands,
               vector<vector<string>> &commandArgs);

    /**
     * Get Symbol Map.
     * @return map<string, double>
     */
    map<string, double> GetSymbolMap() override;

    /**
     * set Symbol Map.
     * @param symbolMap symbolMap
     */
    void setSymbolMap(map<string, double> symbolMap) override;

private:
    map<string,double > symbolTable;
    string boolCondition;
    vector<Command*>commands;
    vector<vector<string>>commandArgs;
};

#endif //UNTITLED16_IFCOMMAND_H