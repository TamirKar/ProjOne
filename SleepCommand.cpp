

#include <unistd.h>
#include "SleepCommand.h"

/**
 * Execute - suspends the program for a period of time..
 * @param args args
 */
void SleepCommand::Execute(vector<string> args) {
    //calculate in milseconds
    usleep(stoi(args[1])*1000);

}

/**
 * SleepCommand.
 * @return map<string, double>
 */
map<string, double> SleepCommand::GetSymbolMap() {
    return symbolTable;
}

/**
 * setSymbolMap.
 * @param symbolMap symbolMap
 */
void SleepCommand::setSymbolMap(map<string, double> symbolMap) {
    symbolTable= symbolMap;
}