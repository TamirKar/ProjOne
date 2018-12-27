#include "BoolExpression.h"
BoolExpression::BoolExpression(Expression *leftExp, Expression *rightExp, const string &operation) : leftExp(leftExp),
                                                                                                     rightExp(rightExp),
                                                                                                     operation(
                                                                                                             operation) {}
/**
 * evaluate the expressions based on the operator.
 * @return true if the expression is correct, and if it incorrect, returns false.
 */
bool BoolExpression::Evaluate() {
    if (this->operation == ">=") {
        return leftExp->Calculate() >= rightExp->Calculate();
    }
    if (this->operation == "<=") {
        return leftExp->Calculate() <= rightExp->Calculate();
    }
    if (this->operation == ">") {
        return leftExp->Calculate() > rightExp->Calculate();
    }
    if (this->operation == "<") {
        return leftExp->Calculate() < rightExp->Calculate();
    }
    if (this->operation == "==") {
        return leftExp->Calculate() == rightExp->Calculate();
    }
    if (this->operation == "!=") {
        return leftExp->Calculate() != rightExp->Calculate();
    }
}


