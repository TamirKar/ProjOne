//abstract class of Command each command has their own execution method and all the commands implement this class.
#ifndef UNTITLED16_COMMAND_H
#define UNTITLED16_COMMAND_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class Command {
public:
    /**
     *execute the command use a vector of strings for the arguments.
     *
     * @param args
     */
    virtual void Execute(vector<string> args) = 0;
    /**
     * setter and getter for updating the symbol map.
     * @return symbolmap
     */
    virtual  map<string, double> GetSymbolMap()=0;
    virtual void setSymbolMap(map<string, double> symbolMap)=0;
};

#endif //UNTITLED16_COMMAND_H