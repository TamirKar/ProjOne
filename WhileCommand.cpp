
#include "WhileCommand.h"
#include "ConditionChecker.h"

/**
 * Execute - WhileCommand.
 * @param args args
 */
void WhileCommand::Execute(vector<string> args) {
    ConditionChecker * checker = new ConditionChecker(boolCondition,symbolTable);
    //execute the condition while condition is true
    while(checker->ConditionTrue()){
        for (int i = 0; i <commands.size() ; ++i) {
            commands[i]->setSymbolMap(this->symbolTable);
            commands[i]->Execute(commandArgs[i]);
            this->symbolTable = commands[i]->GetSymbolMap();
            checker->setSymbolTable(this->symbolTable);
        }
    }
}

/**
 * While Command - constructor.
 * @param symbolTable symbolTable
 * @param boolCondition boolCondition
 * @param commands commands
 * @param commandArgs commandArgs
 */
WhileCommand::WhileCommand( map<string, double> symbolTable,  string &boolCondition,
                            const vector<Command *> &commands, const vector<vector<string>> &commandArgs) : symbolTable(
        symbolTable), boolCondition(boolCondition), commands(commands), commandArgs(commandArgs) {
    int val = boolCondition.find("while");
    this->boolCondition = boolCondition.substr(val + 5);
}

/**
 * GetSymbolMap.
 * @return map<string, double>
 */
map<string, double> WhileCommand::GetSymbolMap() {
    return this->symbolTable;
}

/**
 * setSymbolMap.
 * @param symbolMap symbolMap
 */
void WhileCommand::setSymbolMap(map<string, double> symbolMap) {
    this->symbolTable=symbolMap;
}



