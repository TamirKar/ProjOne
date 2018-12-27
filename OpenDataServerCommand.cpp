//class of OpenDataServerCommand sends parameters and creates a thread for opening server.
#include "OpenDataServerCommand.h"
#include "ShuntingYard.h"

/**
 * class of OpenDataServerCommand sends parameters and creates a thread for opening server.
 * @param args args
 */
void OpenDataServerCommand::Execute(vector<string> args) {
    ShuntingYard yard;
    //get port and speed.
    int port = (int) yard.Calculate(args[1])->Calculate();
    int speed = (int) yard.Calculate(args[2])->Calculate();
    //store parameters in struct for function
    OpenServerParameters *parmeters = new OpenServerParameters();
    parmeters->port=port;
    parmeters->speed = speed;
    pthread_t pthread;
    //create thread for server opening
    pthread_create(&pthread, nullptr, DataReaderServer::CreateServer, parmeters);
    pthread_detach(pthread);
}

/**
 * Open Data Server Command.
 * @return map<string, double>
 */
map<string, double> OpenDataServerCommand::GetSymbolMap() {
    return symbolTable;
}

/**
 * set Symbol Map.
 * @param symbolMap symbolMap
 */
void OpenDataServerCommand::setSymbolMap(map<string, double> symbolMap) {
    symbolTable=symbolMap;
}