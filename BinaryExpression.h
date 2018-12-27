//class of BinaryExpression.
#ifndef UNTITLED16_BINARYEXPRESSION_H
#define UNTITLED16_BINARYEXPRESSION_H
#include "Expression.h"

/**
 * Binary Expression.
 */
class BinaryExpression:public Expression{
protected:
    Expression * leftExp;
    Expression * rightExp;
public:

    /**
     * BinaryExpression.
     * @param leftExp leftExp
     * @param rightExp rightExp
     */
    BinaryExpression(Expression *leftExp, Expression *rightExp) : leftExp(leftExp), rightExp(rightExp) {}
};

#endif //UNTITLED16_BINARYEXPRESSION_H