//Class of Number.


#ifndef UNTITLED16_NUMBER_H
#define UNTITLED16_NUMBER_H

#include "Expression.h"

class Number : public Expression {

private:
    double num;
public:
    Number(double num) : num(num) {}

    double Calculate() {
        return num;
    }
};

#endif //UNTITLED16_NUMBER_H
