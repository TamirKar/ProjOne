//Class of PrintCommand - The command will print any text given to it and values of variables from the symbol map.

#ifndef UNTITLED16_PRINTCOMMAND_H
#define UNTITLED16_PRINTCOMMAND_H


#include "Command.h"
#include <map>

/**
 * PrintCommand
 */
class PrintCommand : public Command{

private:
    map<string,double>symbolTable;
public:
    /**
     * print any text and the  values of variables from the symbol map.
     * @param args
     */
    void Execute(vector<string> args) override;
    map<string, double> GetSymbolMap() override;
    void setSymbolMap(map<string, double> symbolMap) override;
};

#endif //UNTITLED16_PRINTCOMMAND_H