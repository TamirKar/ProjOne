//Class of Var Command  - calulate expression given and give value to var

#ifndef UNTITLED16_VARCOMMAND_H
#define UNTITLED16_VARCOMMAND_H


#include "Command.h"
#include <string>
#include <vector>

class VarCommand: public Command {
private:
    map<string,double > symbolTable;
public:
    /**
     * Calulate expression given and give value to var
     * @param args
     */
    void Execute(vector<string> args) override;
    map<string, double> GetSymbolMap() override;
    void setSymbolMap(map<string, double> symbolMap) override;


};


#endif //UNTITLED16_VARCOMMAND_H
