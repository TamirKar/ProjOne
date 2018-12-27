//class of OpenDataServerCommand sends parameters and creates a thread for opening server.
#ifndef UNTITLED16_OPENDATASERVERCOMMAND_H
#define UNTITLED16_OPENDATASERVERCOMMAND_H


#include "Command.h"
#include <sstream>
#include "OpenDataServerCommand.h"
#include "Globals.h"
#include "DataReaderServer.h"

/**
 * Open Data Server Command.
 */
class OpenDataServerCommand: public Command {
public:

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

    /**
     * Execute actions from the data from the vector.
     * @param args args
     */
    void Execute(vector<string> args) override;

private:
    map<string,double>symbolTable;


};


#endif //UNTITLED16_OPENDATASERVERCOMMAND_H