/*
* this file is the class definition of RPNCalc
*/

#ifndef __RPNCALC_H__
#define __RPNCALC_H__
#include "DatumStack.h"
#include <iostream>
#include <string>
class RPNCalc
{
public:

    RPNCalc();
    ~RPNCalc();
    void run();


private:
    //Note:
    //if you want to run unit test code, these private functions
    //should be changed into public
    void execCommands(std::istream& input);
    void execCommandsWithException(std::string cmd);
    void ArithmeticOperation(std::string op);
    void RelationOperation(std::string op);
    void execIF();
    void execRstring();
    void execFile();

    DatumStack stack;


};
#endif // !__RPNCALC_H__



