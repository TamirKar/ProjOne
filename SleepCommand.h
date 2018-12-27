//Class of SleepCommand - suspends the program for a period of time.
#ifndef UNTITLED16_SLEEPCOMMAND_H
#define UNTITLED16_SLEEPCOMMAND_H

#include "Command.h"

/**
 * SleepCommand.
 */
class SleepCommand : public Command{

public:
    //suspends the program for a period of time.
    void Execute(vector<string> args) override;
    map<string, double> GetSymbolMap() override;
    void setSymbolMap(map<string, double> symbolMap) override;

private:
    map<string,double > symbolTable;
};

#endif //UNTITLED16_SLEEPCOMMAND_H