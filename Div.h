//Class of Div.
#ifndef UNTITLED16_PLUS_H
#define UNTITLED16_PLUS_H
#include "BinaryExpression.h"

/**
 * division
 */
class Div : public BinaryExpression {
public:

    /**
     * Div - constructor.
     * @param leftExp leftExp
     * @param rightExp rightExp
     */
    Div(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

    /**
     * Calculate the div expression.
     * @return the value of the division.
     */
    double Calculate() {
        return leftExp->Calculate() / rightExp->Calculate();
    }
};

#endif //UNTITLED16_PLUS_H