
#include <sstream>
#include "ConnectServerCommand.h"
#include "Globals.h"
#include "DataReaderConnect.h"
#include "ShuntingYard.h"

void ConnectCommand::Execute(vector<string> args) {
    ShuntingYard shuntingYard;
    //get port and ip
    int port = (int) shuntingYard.Calculate(args[2])->Calculate();
    string ip = args[1];
    //store parameters in struct to send to function
    ConnectServerParameters * parameters = new ConnectServerParameters;
    parameters->port = port;
    parameters->ip = ip;
    pthread_t pthread;
    //create pthread and parameters to function,
    pthread_create(&pthread, nullptr, DataReaderConnect::ConnectServer, parameters);
    pthread_detach(pthread);

}


map<string, double> ConnectCommand::GetSymbolMap() {
    return this->symbolTable;
}

void ConnectCommand::setSymbolMap(map<string, double> symbolMap) {
    symbolTable = symbolMap;
}