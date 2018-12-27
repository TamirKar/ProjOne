
#include "Parser.h"
#include "Expression.h"
#include "OpenDataServerCommand.h"
#include "ConnectServerCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "VarCommand.h"
#include <algorithm>
#include "ShuntingYard.h"
#include <ctype.h>
#include "StringUtilis.h"

/**
 * Parser.
 */
Parser::Parser() {
    //insert commands to command table condition (vars and conditional commands are special cases)
    commandsTable.insert(std::pair<string, Command *>("openDataServer", new OpenDataServerCommand));
    commandsTable.insert(std::pair<string, Command *>("connect", new ConnectCommand));
    commandsTable.insert(std::pair<string, Command *>("print", new PrintCommand));
    commandsTable.insert(std::pair<string, Command *>("sleep", new SleepCommand));
    isCondition = false;
}

/**
 * Parser.
 * @param symbolTable symbolTable
 * @param commandsTable commandsTable
 * @param text text
 */
Parser::Parser(map<string, double> &symbolTable, map<string, Command *> &commandsTable,
               vector<vector<string>> &text) : symbolMap(symbolTable),
                                               commandsTable(commandsTable), text(text) {
    //get the end condition
    this->endCondition = StringUtilis::ConvertVectorTostring(text[0]);
    this->endCondition = StringUtilis::CharRemoverStr(endCondition, '{');
    //remove the end condition and brackets
    text.erase(text.begin());
    string str = StringUtilis::ConvertVectorTostring(text[text.size()-1]);
    if(str == "} "){
        text.erase(text.end());
    }
    else{
        string str2 = StringUtilis::ConvertVectorTostring(StringUtilis::CharRemover(str,'}'));
        text[text.size()-1] = StringUtilis::CharRemover(str2,' ');
    }
    //update the text
    this->text = text;
    isCondition = true;
}

/**
 * Parse the text.
 * @param text text
 */
void Parser::ParseText(vector<vector<string>> text) {
    for (int i = 0; i < text.size(); ++i) {
        if (commandsTable.count(text[i][0])) {

            /*
             * none conitional state create and execute commands
             */
            if (!isCondition) {
                Command *command = commandsTable.at(text[i][0]);
                command->setSymbolMap(symbolMap);
                command->Execute(text[i]);

                /**
                 * conitional state store the commands.
                 */
            } else {
                commands.push_back(commandsTable.at(text[i][0]));
                commandArgs.push_back(text[i]);
            }

            /**
             * for conditional commands all text between the brackets is stored and sent to a new parser in conditional state.
             *
             */
        } else if (text[i][0] == "while" || text[i][0] == "if") {
            //counting the brackets, "{" will increase the counter and "}" will decrease it.
            int counter = 0;
            vector<vector<string>> args;

            /**
             * add the text between the brackets using the counter as a stop condition.
             */
            if (std::find(text[i + 1].begin(), text[i].end(), "{") != text[i + 1].end()) {
                args.push_back(text[i]);
                args.push_back(text[i + 1]);
                counter++;
                i += 2;
            }

            do {
                args.push_back(text[i]);
                if (std::find(text[i].begin(), text[i].end(), "{") != text[i].end()) {
                    counter++;
                }
                if (std::find(text[i].begin(), text[i].end(), "}") != text[i].end()) {
                    counter--;
                }
                i++;
            } while (counter != 0);
            //create a new parser with the text between the brackets
            Parser *parseCondtion = new Parser(symbolMap, commandsTable, args);
            parseCondtion->ParseText(args);
            this->symbolMap = parseCondtion->getSymbolMap();
            i--;

            /**
             * special case for adding or updating variables.
             */
        } else if (text[i][0] == "var" || symbolMap.count(text[i][0]) == 1 ||
                   (text[i].size() >= 4 && text[i][3] == "bind")) {
            VarsUpdate(text, i);
        }
    }

    /**
     * create condition if inconditionn state
     */
    if (isCondition) {
        CreateCondition();
    }
}

/**
 * special case from adding or updating variables
 * @param text vector of text
 * @param i int
 */
void Parser::VarsUpdate(vector<vector<string>> text, int i) {
    ShuntingYard shuntingYard;

    /**
     * bind var = "/controls/flight/speedbrake"
     */
    if (text[i].size() >= 4 && text[i][3] == "bind") {
        //add the var to the symbol table
        symbolMap.insert(pair<string, double>(text[i][1], 0));
        //update global maps
        InsertVarToMaps(text[i][1], text[i][4]);

        /**
         * var z = x * y or z = x * y
         */
    } else if ((text[i][0] == "var" || symbolMap.count(text[i][0]) == 1) && shuntingYard.NeedsCalculation(text[i])) {
        //calculate in var command
        Command * command = new VarCommand;
        command->setSymbolMap(symbolMap);

        /**
         * execute command if not condtion.
         */
        if (!isCondition) {
            command->Execute(text[i]);
            this->symbolMap = command->GetSymbolMap();
            //otherwise add the command
        } else {
            commands.push_back(command);
            commandArgs.push_back(text[i]);
        }

        // var x = 1
    } else if (text[i][0] == "var" && StringUtilis::IsDigit(text[i][3])) {
        //add var to the table with value
        symbolMap.insert(pair<string, double>(text[i][1], stod(text[i][3])));

        // var x = z (z is already defined)
    } else if (text[i][0] == "var" && symbolMap.count(text[i][3]) == 1) {
        //add to symbol table and update value to defined var
        symbolMap.insert(pair<string, double>(text[i][1], 0));
        symbolMap.at(text[i][1]) = symbolMap.at(text[i][3]);
        UpdatePathValueFromVar(text[i][1], symbolMap.at(text[i][3]));

        // x = z (x,z are already defined)
    } else if (symbolMap.count(text[i][0]) == 1 && symbolMap.count(text[i][2]) == 1 && text[i].size() == 3) {
        //update value to the the defined var
        symbolMap.at(text[i][0]) = symbolMap.at(text[i][2]);
        //update global map
        UpdatePathValueFromVar(text[i][0], symbolMap.at(text[i][0]));

        // x = 1
    } else if (symbolMap.count(text[i][0]) == 1 && StringUtilis::IsDigit(text[i][2]) && text[i].size() <= 3) {
        //update value to number
        symbolMap.at(text[i][0]) = stod(text[i][2]);
        //update global map
        UpdatePathValueFromVar(text[i][0], symbolMap.at(text[i][0]));
    }
}

/**
 * set Symbol Map.
 * @param symbolMap symbolMap
 */
void Parser::setSymbolMap(const map<string, double> &symbolMap) {
    Parser::symbolMap = symbolMap;
}

/**
 * creates a conditional command and send the commands to it.
 */
void Parser::CreateCondition() {
    //create while command send commands to execute
    if (endCondition.find("while") != std::string::npos) {
        WhileCommand *whileCommand = new WhileCommand(symbolMap, endCondition, commands, commandArgs);
        vector<string> args;
        whileCommand->Execute(args);
        this->symbolMap = whileCommand->GetSymbolMap();

        //create if command send commands to execute
    } else if (endCondition.find("if") != std::string::npos) {
        IfCommand *ifCommand = new IfCommand(symbolMap, endCondition, commands, commandArgs);
        vector<string> args;
        ifCommand->Execute(args);
        this->symbolMap = ifCommand->GetSymbolMap();
    }
}

/**
 * get Symbol Map.
 * @return map<string, double>
 */
const map<string, double> &Parser::getSymbolMap() const {
    return symbolMap;
}












