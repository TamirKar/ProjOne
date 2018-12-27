//Class of Plus.
#ifndef UNTITLED16_PLUS_H
#define UNTITLED16_PLUS_H


#include "BinaryExpression.h"

/**
 * Plus
 */
class Plus : public BinaryExpression {
public:
    Plus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

    /**
     * Calculate.
     * @return double
     */
    double Calculate() {
        return leftExp->Calculate() + rightExp->Calculate();
    }
};

#endif //UNTITLED16_PLUS_H