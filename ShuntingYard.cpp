#include <stack>
#include <string>
#include <cstring>
#include "Expression.h"
#include "Number.h"
#include "ShuntingYard.h"

using namespace std;

/**
 * The function returns false while the characters are an operator or Parenthesis,
 * and else the characters are valid and it returns true.
 * @param newChar newChar
 * @param otherChar otherChar
 * @return true or false
 */
bool ShuntingYard::hasPrecedence(char op1, char op2) {

    if (op2 == '(' || op2 == ')')
        return false;
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return false;
    else
        return true;
}

/**
 * The function gets two numbers in type double and makes the operation between them.
 * @param newChar newChar
 * @param number number
 * @param otherNum otherNum
 * @return double
 */
double ShuntingYard::applyOp(char op, double b, double a) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                perror("Cannot divide by zero");
            return a / b;
    }
    return 0;
}

/**
 * The evaluate function which evaluates the expression.
 * @param str str
 * @return Expression
 */
Expression *ShuntingYard::Calculate(string &strExp) {
    char textArr[strExp.length() + 1];
    strcpy (textArr, strExp.c_str());
    char singleChar;
    char otherChar;
    char newChar;
    double aNum = 0;
    double aOtherNum = 0;
    double bNum = 0;
    double bOtherNum = 0;
    double cNum = 0;
    double cOtherNum = 0;
    stack<double> numbersInStack;
    stack<char> charsInStack;

    //running through the string
    for (int i = 0; i < strExp.length() + 1; i++) {
        // If current token is a whitespace, skip it.
        if (textArr[i] == ' ')
            continue;
        // If current token is a number, push it to stack for numbers.
        if (textArr[i] >= '0' && textArr[i] <= '9') {
            string newString = "";
            // There may be more than one digits in number.
            while (i < strExp.length() + 1 && textArr[i] >= '0' && textArr[i] <= '9')
                newString= newString + (textArr[i++]);
            i=i-1;
            numbersInStack.push((double)stoi(newString));
        }

            /*
             * if we are in the start of the text - '('
             */
        else if (textArr[i] == '(')
            charsInStack.push(textArr[i]);

            /*
            * if we are in the start of the text - '('
            */
        else if (textArr[i] == ')') {
            while (charsInStack.top() != '(') {

                //if the stack of numbers is not empty, pops the first number from the stack.
                if(!numbersInStack.empty()){
                    aNum=numbersInStack.top();
                    numbersInStack.pop();
                }

                //if the stack of numbers is not empty, pops the first number from the stack.
                if(!numbersInStack.empty()){
                    aOtherNum=numbersInStack.top();
                    numbersInStack.pop();
                }
                otherChar = charsInStack.top();
                charsInStack.pop();
                numbersInStack.push(applyOp(otherChar, aNum, aOtherNum));
            }
            charsInStack.pop();
        }

            /*
             * in case there is an operator
             */
        else if (textArr[i] == '+' || textArr[i] == '-' || textArr[i] == '*' || textArr[i] == '/') {
            while (!charsInStack.empty() && hasPrecedence(textArr[i], charsInStack.top())) {
                singleChar = charsInStack.top();
                charsInStack.pop();

                //if the stack of chars is not empty, puts the remaining numbers in the stack of the numbers.
                if (!numbersInStack.empty()) {
                    bNum = numbersInStack.top();
                    numbersInStack.pop();
                }

                //if the stack of chars is not empty, puts the remaining numbers in the stack of the numbers.
                if (!numbersInStack.empty()) {
                    bOtherNum = numbersInStack.top();
                    numbersInStack.pop();
                }
                numbersInStack.push(applyOp(singleChar, bNum, bOtherNum));
            }
            charsInStack.push(textArr[i]);
        }
    }

    /*
     * the loop runs through the remaining chars in the stack of the numbers
     * and puts them in the stack of the numbers.
     */
    while (!charsInStack.empty()) {
        newChar = charsInStack.top();
        charsInStack.pop();

        //if the stack of chars is not empty, puts the remaining numbers in the stack of the numbers.
        if (!numbersInStack.empty()) {
            cNum = numbersInStack.top();
            numbersInStack.pop();
        }

        //if the stack of chars is not empty, puts the remaining numbers in the stack of the numbers.
        if (!numbersInStack.empty()) {
            cOtherNum = numbersInStack.top();
            numbersInStack.pop();
        }
        numbersInStack.push(applyOp(newChar, cNum, cOtherNum));
    }
    double val = numbersInStack.top();
    numbersInStack.pop();
    Expression* res = new Number(val);
    return res;
}

/**
 * Needed Calculation.
 * @param vec vec
 * @return true or false
 */
bool ShuntingYard::NeedsCalculation(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        if ((v[i].find('+') != std::string::npos) ||
            (v[i].find('-') != std::string::npos) ||
            (v[i].find('*') != std::string::npos) ||
            (v[i].find('/') != std::string::npos)){
            return true;
        }
    }
    return false;
}