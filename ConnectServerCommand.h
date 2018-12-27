//Class of ConnectCommand - the client connects to the simulator and can send information to it.

#ifndef UNTITLED16_CONNECTCOMMAND_H
#define UNTITLED16_CONNECTCOMMAND_H


#include "Command.h"

class ConnectCommand : public Command{
public:

    /**
     * connect to the server send values to the simulator
     */
    void Execute(vector<string> args) override;

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
    map<string,double>symbolTable;



};


#endif //UNTITLED16_CONNECTCOMMAND_H