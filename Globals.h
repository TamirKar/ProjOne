//Globals of the Program - Contains the Thread parameter for opening and connecting to the server.
//And two maps - one for binding between vars to paths and one from paths values.
//also contains methods for updating the maps.

#ifndef UNTITLED16_THREADPARAMETERS_H
#define UNTITLED16_THREADPARAMETERS_H

#include <string>
#include <iostream>
using namespace std;

//server parmeters
struct OpenServerParameters {
    int speed;
    int port;
};

//client parameters
struct ConnectServerParameters {
    int port;
    string ip;
};

//binding map
extern map<string,string> BindMapVarToPath;
//paths values map
extern map<string,double> ValuesOfPathMap;

/**
 * update the paths value from the vars value
 * @param var var
 * @param varsValue varsValue
 */
void UpdatePathValueFromVar(string var, int varsValue);

/**
 * bind the var to the bind map, also insert the path to the paths value map and update value to 0.
 */
void InsertVarToMaps(string,string);

/**
 * update path values based on date sent from server
 * @param buffer buffer
 */
void UpdatePathValuesFromServer(string buffer);

#endif //UNTITLED16_THREADPARAMETERS_H