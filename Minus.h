//Class of Minus.

#ifndef UNTITLED16_PLUS_H
#define UNTITLED16_PLUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}
    double Calculate() {
        return leftExp->Calculate() - rightExp->Calculate();
    }
};

#endif //UNTITLED16_PLUS_H
