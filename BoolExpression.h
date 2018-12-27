
//class of BoolExpression - evaluate two expressions with an operator.
#ifndef UNTITLED16_BOOLEXPRESSION_H
#define UNTITLED16_BOOLEXPRESSION_H

#include "Expression.h"
#include <string>
using namespace std;

/**
 * Boolean Expression.
 */
class BoolExpression{
private:
    Expression * leftExp;
    Expression * rightExp;
    string operation;
public:

    /**
     * BoolExpression.
     * @param leftExp leftExp
     * @param rightExp rightExp
     * @param operation operation
     */
    BoolExpression(Expression *leftExp, Expression *rightExp, const string &operation);
    //Evaluate the expressions
    bool Evaluate();
};

#endif //UNTITLED16_BOOLEXPRESSION_H