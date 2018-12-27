
#include <iostream>
#include "PrintCommand.h"

using namespace std;

/**
 * print any text and the values of variables from the symbol map.
 * @param args args
 */
void PrintCommand::Execute(vector<string> args) {
    args.erase(args.begin());
    if(symbolTable.count(args[0])){
        cout<<symbolTable.at(args[0])<<endl;
    } else{
        for (int i = 0; i <args.size() ; ++i) {
            cout<<args[i]+" ";
        }cout<<"\n";
    }
}

/**
 * Print Command.
 * @return map<string, double>
 */
map<string, double> PrintCommand::GetSymbolMap() {
    return symbolTable;
}

/**
 * setSymbolMap.
 * @param symbolMap symbolMap
 */
void PrintCommand::setSymbolMap(map<string, double> symbolMap) {
    symbolTable=symbolMap;

}




