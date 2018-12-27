//
// Created by tamir on 12/23/18.
//

#ifndef UNTITLED16_SHUNTINGYARD_H
#define UNTITLED16_SHUNTINGYARD_H


#include "Expression.h"
#include <string>
#include <vector>

using namespace std;
class ShuntingYard {
public:
        bool hasPrecedence(char op1, char op2);
        Expression* Calculate(string &expression);
        double applyOp(char op, double b, double a);
        bool NeedsCalculation(vector<string> v);
};


#endif //UNTITLED16_SHUNTINGYARD_H
