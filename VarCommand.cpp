

#include "VarCommand.h"
#include "ConditionChecker.h"
#include "ShuntingYard.h"
#include "StringUtilis.h"
#include "Globals.h"

//VarCommand - add or update variables that need calculation.
void VarCommand::Execute(vector<string> args) {
    string str;
    ShuntingYard shuntingYard;
    ConditionChecker checker(str,symbolTable);
    //split the expression by the operation =
    string str1 = StringUtilis::ConvertVectorToStringWithoutSpaces(args);
    vector<string> splitExp = StringUtilis::SplitString(str1,"=");
    //get numeric values from right expression and calculate it
    string rightExp = checker.ConvertCondition(splitExp[1]);
    double calculation = shuntingYard.Calculate(rightExp)->Calculate();
    //update left expression to the calculation
    if(symbolTable.count(splitExp[0])){
        symbolTable.at(splitExp[0])=calculation;
    }
    //update Path Map
    UpdatePathValueFromVar(splitExp[0], calculation);


}

map<string, double> VarCommand::GetSymbolMap() {
    return this->symbolTable;
}

void VarCommand::setSymbolMap(map<string, double> symbolMap) {
    this->symbolTable = symbolMap;

}
