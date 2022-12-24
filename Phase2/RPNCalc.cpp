/*
* this file is the implemation of 
* class RPNCalc. The interface definition
* is the file RPNCalc.h
*/
#define _CRT_SECURE_NO_WARNINGS
#include "RPNCalc.h"
#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;
bool isRunning = true;
bool got_int(string s, int* resultp);
string parseRString(istream& input);

/// <summary>
/// defalut constructor 
/// an empty stack
/// </summary>
RPNCalc::RPNCalc()
{
    
}

/// <summary>
/// 
/// </summary>
RPNCalc::~RPNCalc()
{

}

void quit() {
    isRunning = false;
    return;
}
/// <summary>
/// main loop run function.
/// fetch commands and exec while running.
/// </summary>
void RPNCalc::run()
{
    execCommands(cin); //read commands from cin when the program starts
    //if the function execCommands(cin) return.that means the cin reached eof 
//or fetch the command "quit".
    //need to quit the program
    cerr << "Thank you for using CalcYouLater." << endl;
  
}


void RPNCalc:: execCommands(istream& input) {
    string cmd = "";
    int intVar;
    bool boolVar;
    string rstringVar;
    while (!input.fail() && isRunning) {
        input >> cmd;
        if (input.fail())
            continue;
        if (cmd == "quit") {
            isRunning = false;
            continue;
        }
        else if (got_int(cmd, &intVar)) {//int
            Datum d(intVar);
            this->stack.push(d);
        }
        else if (cmd == "#t") {//true
            boolVar = true;
            Datum d(boolVar);
            this->stack.push(d);
        }
        else if (cmd == "#f") {//false
            boolVar = false;
            Datum d(boolVar);
            this->stack.push(d);
        }
        else if (cmd == "{") {//rstring
            string rstring = parseRString(input);
            Datum d(rstring);
            this->stack.push(d);
        }
        else  {
            try {
                //may throw runtime exceptons
                execCommandsWithException(cmd);           
            }
            catch (runtime_error e) {
                cerr << "Error: " << e.what() << endl;
                continue;
            }
        }
    }
    return;
}
//may throw runtime errors
void RPNCalc::execCommandsWithException(string cmd) {
    bool boolVar;
    if (cmd == "not") {
        Datum top = (this->stack).top();
        this->stack.pop(); //this may throw an empty stack runtime error
        boolVar = !top.getBool();//this may throw a not bool runtime error
        Datum d(boolVar); 
        this->stack.push(d);
    }
    else if(cmd=="clear"){
        this->stack.clear();
    }
    else if (cmd == "drop") {
        this->stack.pop();// may throw an empty stack runtime error
    }
    else if (cmd == "dup") {
        Datum d = this->stack.top();
        this->stack.push(d);
    }
    else if (cmd == "swap") {
        Datum top1 = this->stack.top();
        this->stack.pop();
        Datum top2 = this->stack.top();
        this->stack.pop();
        this->stack.push(top1);
        this->stack.push(top2);
    }
    else if (cmd == "print") {
        Datum d = this->stack.top();
        cout << d.toString() << endl;
    }
    else if (cmd == "+") {
        ArithmeticOperation(cmd);
    }
    else if (cmd == "-") {
        ArithmeticOperation(cmd);
    }
    else if (cmd == "*") {
        ArithmeticOperation(cmd);
    }
    else if (cmd == "/") {
        ArithmeticOperation(cmd);
    }
    else if (cmd == "mod") {
        ArithmeticOperation(cmd);
    }
    else if (cmd == "<") {
        RelationOperation(cmd);
    }
    else if (cmd == ">") {
        RelationOperation(cmd);
    }
    else if (cmd == "<=") {
        RelationOperation(cmd);
    }
    else if (cmd == ">=") {
        RelationOperation(cmd);
    }
    else if (cmd == "==") {
        RelationOperation(cmd);
    }
    else if (cmd == "exec") {
        execRstring();
    }
    else if (cmd == "file") {
        execFile();
    }
    else if (cmd == "if") {
        execIF();
    }
    else {
        cerr << cmd<<": unimplemented" << endl;
    }
}
void RPNCalc::ArithmeticOperation(string op) {
    int intRightHand = 0;
    int intLeftHand = 0;
    int result = 0;
    if (op == "+") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
         result = intLeftHand + intRightHand;
        Datum d(result);
        this->stack.push(d);
    }
    else if (op == "-") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        result = intLeftHand - intRightHand;
        Datum d(result);
        this->stack.push(d);
    }
    else if (op == "*") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        result = intLeftHand * intRightHand;
        Datum d(result);
        this->stack.push(d);
    }
    else if (op == "/") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        if (intRightHand == 0)
            throw runtime_error("divide by Zero");
        result = intLeftHand / intRightHand;
        Datum d(result);
        this->stack.push(d);
    }
    else if (op == "mod") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        result = intLeftHand % intRightHand;
        Datum d(result);
        this->stack.push(d);
    }
    else {
        throw runtime_error("unimpleted Arithmetic Operation"+op);
    }
}
void RPNCalc::RelationOperation(string op) {
    int intRightHand=0;
    int intLeftHand=0;
    bool result=false;
    if (op == "<") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        result = (intLeftHand < intRightHand);
        Datum d(result);
        this->stack.push(d);
    }
    else if (op == ">") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        result = (intLeftHand > intRightHand);
        Datum d(result);
        this->stack.push(d);
    }
    else if (op == "<=") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        result = (intLeftHand <= intRightHand);
        Datum d(result);
        this->stack.push(d);
    }
    else if (op == ">=") {
        Datum intDatumRightHand = this->stack.top();
        this->stack.pop();
        Datum intDatumLeftHand = this->stack.top();
        this->stack.pop();
        intRightHand = intDatumRightHand.getInt();
        intLeftHand = intDatumLeftHand.getInt();
        result = (intLeftHand >= intRightHand);
        Datum d(result);
        this->stack.push(d);
    }
    else if(op=="=="){
        Datum rightHand = this->stack.top();
        this->stack.pop();
        Datum leftHand = this->stack.top();
        this->stack.pop();
        result = (rightHand == leftHand);
        Datum d(result);
        this->stack.push(d);
    }
    else {
        throw runtime_error("unimpleted Relation Operation"+op);
    }

 }
/// <summary>
/// execute a rstring on the top of stack
/// throws empty excetpion while the stack is empty
/// throws datum_not_rstring exception whle the 
/// top element is not a rstring datum.
/// </summary>
void RPNCalc::execRstring() {
    Datum rstringDatum = this->stack.top();
    this->stack.pop();
    if (rstringDatum.isRString() == false) {
        std::cerr << "Error: cannot execute non rstring\n";
        return;
    }
    string rstring = rstringDatum.getRString();
    //remove the { at the begin } at the end of the rstring;
    //to make it an valid command
    rstring.erase(0, 1);
    rstring.pop_back();
    istringstream iss(rstring);
    execCommands(iss);
}
void RPNCalc::execFile() {
    Datum rstringDatum = this->stack.top();
    this->stack.pop();
    if (false == rstringDatum.isRString()) {
        std::cerr << "Error: file operand not rstring\n";
        return;
    }
    string rstring = rstringDatum.getRString();
    //remove the  brackets and space
    //"{ file.txt }" -> "file.txt"
    rstring.erase(0, 2);
    rstring.pop_back();
    rstring.pop_back();
    string filename = rstring;
    ifstream inFileStream(filename);
    if (!inFileStream.is_open()) {
        cerr << "Unable to read " << filename << "\n";
        return;
    }
    else {
        execCommands(inFileStream);
        inFileStream.close();
    }
}
void RPNCalc::execIF() {
    Datum datumFalseCase = this->stack.top();
    this->stack.pop();
    Datum datumTrueCase = this->stack.top();
    this->stack.pop();
    Datum datumTestConditon = this->stack.top();
    this->stack.pop();

    if (datumTestConditon.isBool() == false) {
        cerr << "Error: expected boolean in if test\n";
    }
    else if (datumFalseCase.isRString() == false || datumTrueCase.isRString() == false) {
        cerr << "Error: expected rstring in if branch\n";
    }
    else {
        if (datumTestConditon.getBool() == true) {
            this->stack.push(datumTrueCase);
        }
        else
        {
            this->stack.push(datumFalseCase);
        }
        execRstring();
    }

}

bool got_int(string s, int* resultp)
{
    /* Holds the first non-whitespace character after the integer */
    char extra;

    return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}