#include "IfCommand.h"
#include "ConditionChecker.h"

/**
 * If Command - constructor.
 * @param symbolTable symbolTable
 * @param boolCondition boolCondition
 * @param commands commands
 * @param commandArgs commandArgs
 */
IfCommand::IfCommand( map<string, double> &symbolTable,  string &boolCondition,
                      vector<Command *> &commands,  vector<vector<string>> &commandArgs) : symbolTable(
        symbolTable), boolCondition(boolCondition), commands(commands), commandArgs(commandArgs) {
    //remove the if from the string
    int index = boolCondition.find("if");
    this->boolCondition = boolCondition.substr(index + 3);
}

/**
 * execute the commands if the condition is true.
 * @param args args
 */
void IfCommand::Execute(vector<string> args) {
    ConditionChecker * checker = new ConditionChecker(boolCondition,symbolTable);
    //condition is checked
    if(checker->ConditionTrue()){
        //commands are executed
        for (int i = 0; i <commands.size() ; ++i) {
            commands[i]->setSymbolMap(this->symbolTable);
            commands[i]->Execute(commandArgs[i]);
            this->symbolTable = commands[i]->GetSymbolMap();
            checker->setSymbolTable(this->symbolTable);
        }
    }
}

/**
 * IfCommand - returns the symbol Table.
 * @return map<string, double>
 */
map<string, double> IfCommand::GetSymbolMap() {
    return symbolTable;
}

/**
 * set Symbol Map.
 * @param symbolMap symbolMap
 */
void IfCommand::setSymbolMap(map<string, double> symbolMap) {
    symbolTable = symbolMap;

}