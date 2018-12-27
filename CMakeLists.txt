cmake_minimum_required(VERSION 3.13)
project(untitled16)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "-pthread")


add_executable(untitled16 main.cpp Command.h Expression.h BinaryExpression.h Plus.h Minus.h Div.h Mul.h Number.h BoolExpression.h BoolExpression.cpp Lexer.cpp Lexer.h Parser.cpp Parser.h OpenDataServerCommand.cpp OpenDataServerCommand.h Globals.h DataReaderServer.cpp DataReaderServer.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h ConnectServerCommand.cpp ConnectServerCommand.h DataReaderConnect.cpp DataReaderConnect.h WhileCommand.cpp WhileCommand.h ShuntingYard.cpp ShuntingYard.h ConditionChecker.cpp ConditionChecker.h IfCommand.cpp IfCommand.h VarCommand.cpp VarCommand.h StringUtilis.cpp StringUtilis.h Globals.cpp)