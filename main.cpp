#include <iostream>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Number.h"
#include "Plus.h"
#include "Lexer.h"
#include "Parser.h"
using namespace std;

int main(int argc,char * argv[]) {
    Lexer lexer;
    Parser parser;
    //parse the text given from lexer
    parser.ParseText(lexer.GetFileLines(argv[1]));
}