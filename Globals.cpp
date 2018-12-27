#include <map>
#include <vector>
#include "Globals.h"
#include "StringUtilis.h"


//binding map
map<string, string> BindMapVarToPath = {};
//paths values map
map<string, double> ValuesOfPathMap = {{"/instrumentation/airspeed-indicator/indicated-speed-kt",        0},
                                       {"/instrumentation/altimeter/indicated-altitude-ft",              0},
                                       {"/instrumentation/altimeter/pressure-alt-ft",                    0},
                                       {"/instrumentation/attitude-indicator/indicated-pitch-deg",       0},
                                       {"/instrumentation/attitude-indicator/indicated-roll-deg",        0},
                                       {"/instrumentation/attitude-indicator/internal-pitch-deg",        0},
                                       {"/instrumentation/attitude-indicator/internal-roll-deg",         0},
                                       {"/instrumentation/encoder/indicated-altitude-ft",                0},
                                       {"/instrumentation/encoder/pressure-alt-ft",                      0},
                                       {"/instrumentation/gps/indicated-altitude-ft",                    0},
                                       {"/instrumentation/gps/indicated-ground-speed-kt",                0},
                                       {"/instrumentation/gps/indicated-vertical-speed",                 0},
                                       {"/instrumentation/heading-indicator/indicated-heading-deg",      0},
                                       {"/instrumentation/magnetic-compass/indicated-heading-deg",       0},
                                       {"/instrumentation/slip-skid-ball/indicated-slip-skid",           0},
                                       {"/instrumentation/turn-indicator/indicated-turn-rate",           0},
                                       {"/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0},
                                       {"/controls/flight/aileron",                                      0},
                                       {"/controls/flight/elevator",                                     0},
                                       {"/controls/flight/rudder",                                       0},
                                       {"/controls/flight/flaps",                                        0},
                                       {"/controls/engines/current-engine/throttle",                     0},
                                       {"/engines/engine/rpm",                                           0}};

/**
 * update Path value from the var's value.
 * @param var var
 * @param varsValue varsValue
 */
void UpdatePathValueFromVar(string var, int varsValue) {
    if (BindMapVarToPath.count(var)) {
        //get path from map
        string path = BindMapVarToPath.at(var);
        if (ValuesOfPathMap.count(path)) {
            //update it's value
            ValuesOfPathMap.at(path) = varsValue;
        }
    }
}

/**
 * bind the var to the bind map, also insert the path to the paths value map and update value to 0.
 * @param var var
 * @param path path
 */
void InsertVarToMaps(string var, string path) {
    if (ValuesOfPathMap.count(path) == 0) {
        ValuesOfPathMap.insert(pair<string, double>(path, 0));
    }
    BindMapVarToPath.insert(pair<string, string>(var, path));
}

/**
 * update the Paths values based on the data sent from the server.
 * @param buffer buffer
 */
void UpdatePathValuesFromServer(string buffer) {
    vector <string> ValuesFromServer = StringUtilis::SplitString(buffer, ",");
    for (int i = 0; i < ValuesFromServer.size(); i++) {
        switch (i) {
            case 0:
                ValuesOfPathMap.at("/instrumentation/airspeed-indicator/indicated-speed-kt") = stod(ValuesFromServer[i]);
            case 1:
                ValuesOfPathMap.at("/instrumentation/altimeter/indicated-altitude-ft") = stod(ValuesFromServer[i]);
            case 2:
                ValuesOfPathMap.at("/instrumentation/altimeter/pressure-alt-ft") = stod(ValuesFromServer[i]);
            case 3:
                ValuesOfPathMap.at("/instrumentation/attitude-indicator/indicated-pitch-deg") = stod(ValuesFromServer[i]);
            case 4:
                ValuesOfPathMap.at("/instrumentation/attitude-indicator/indicated-roll-deg") = stod(ValuesFromServer[i]);
            case 5:
                ValuesOfPathMap.at("/instrumentation/attitude-indicator/internal-pitch-deg") = stod(ValuesFromServer[i]);
            case 6:
                ValuesOfPathMap.at("/instrumentation/attitude-indicator/internal-roll-deg") = stod(ValuesFromServer[i]);
            case 7:
                ValuesOfPathMap.at("/instrumentation/encoder/indicated-altitude-ft") = stod(ValuesFromServer[i]);
            case 8:
                ValuesOfPathMap.at("/instrumentation/encoder/pressure-alt-ft") = stod(ValuesFromServer[i]);
            case 9:
                ValuesOfPathMap.at("/instrumentation/gps/indicated-altitude-ft") = stod(ValuesFromServer[i]);
            case 10:
                ValuesOfPathMap.at("/instrumentation/gps/indicated-ground-speed-kt") = stod(ValuesFromServer[i]);
            case 11:
                ValuesOfPathMap.at("/instrumentation/gps/indicated-vertical-speed") = stod(ValuesFromServer[i]);
            case 12:
                ValuesOfPathMap.at("/instrumentation/heading-indicator/indicated-heading-deg") = stod(ValuesFromServer[i]);
            case 13:
                ValuesOfPathMap.at("/instrumentation/magnetic-compass/indicated-heading-deg") = stod(ValuesFromServer[i]);
            case 14:
                ValuesOfPathMap.at("/instrumentation/slip-skid-ball/indicated-slip-skid") = stod(ValuesFromServer[i]);
            case 15:
                ValuesOfPathMap.at("/instrumentation/turn-indicator/indicated-turn-rate") = stod(ValuesFromServer[i]);
            case 16:
                ValuesOfPathMap.at("/instrumentation/vertical-speed-indicator/indicated-speed-fpm") = stod(ValuesFromServer[i]);
            case 17:
                ValuesOfPathMap.at("/controls/flight/aileron") = stod(ValuesFromServer[i]);
            case 18:
                ValuesOfPathMap.at("/controls/flight/elevator") = stod(ValuesFromServer[i]);
            case 19:
                ValuesOfPathMap.at("/controls/flight/rudder") = stod(ValuesFromServer[i]);
            case 20:
                ValuesOfPathMap.at("/controls/flight/flaps") = stod(ValuesFromServer[i]);
            case 21:
                ValuesOfPathMap.at("/controls/engines/current-engine/throttle") = stod(ValuesFromServer[i]);
            case 22:
                ValuesOfPathMap.at("/engines/engine/rpm") = stod(ValuesFromServer[i]);
        }
    }
}


