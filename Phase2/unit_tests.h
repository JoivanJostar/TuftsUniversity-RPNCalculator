/*
* unit tests file
* Note: before complie and running these test
* You must change the private functions of
* RPNCalc into Public.
* Otherwise, there will be some complie errors
*/
#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <iostream>
#include <string>
#include <cassert>
#include <exception>
#include <sstream>

std::string parseRString(std::istream& input);
/// <summary>
/// test if parseRString is ok
/// </summary>
void testParseRString1() {
	std::string s = "{ 2 3 + { 10 file } }";
	std::string expected = "{ 2 3 + { 10 file } }";
	std::istringstream iss(s);
	iss >> s;
	assert(expected == parseRString(iss));

}
void testParseRString2() {
	std::string s = "{ 1 2 / } { 2 3 + }";
	std::string expected = "{ 1 2 / }";
	std::istringstream iss(s);
	iss >> s;
	assert(expected == parseRString(iss));
}

/// <summary>
/// this test will create an empty stack
/// </summary>
void testDatumStackDeafultConstuctor() {
	DatumStack stack;
}
/// <summary>
/// test creating stack with a given array
/// </summary>
void testDatumStackVecotorConstuctor() {
	Datum datas[3] = { Datum(1),Datum("#t"),Datum("{ 1 2 + }") };
	DatumStack stack(datas, 3);
}
/// <summary>
/// test the IsEmpty of DatumStack
/// </summary>
void testDatumStackIsEmpty() {
	DatumStack stack;
	assert(stack.isEmpty());
	Datum datas[3] = { Datum(1),Datum("#t"),Datum("{ 1 2 + }") };
	stack = DatumStack(datas, 3);
	assert(false == stack.isEmpty());
}
/// <summary>
/// test the size() of DatumStack
/// </summary>
void testDatumStackGetSize() {
	Datum datas[3] = { Datum(1),Datum("#t"),Datum("{ 1 2 + }") };
	DatumStack stack = DatumStack(datas, 3);
	assert(stack.size() == 3);
}
/// <summary>
/// test the clear() of DatumStack
/// </summary>
void testDatumStackClear() {
	Datum datas[3] = { Datum(1),Datum("#t"),Datum("{ 1 2 + }") };
	DatumStack stack = DatumStack(datas, 3);
	stack.clear();
	stack.clear();
	assert(stack.size() == 0);
	assert(stack.isEmpty());
}
/// <summary>
/// test the top() of DatumStack
/// Edge test: try top() from an empty stack
/// </summary>
void testTop() {
	Datum datas[3] = { Datum(1),Datum(true),Datum("{ 1 2 + }") };
	DatumStack stack = DatumStack(datas, 3);
	assert(stack.top().isRString());
	assert(stack.top().getRString() == "{ 1 2 + }");
	try {
		stack.pop();
		stack.pop();
		stack.pop();
		stack.top();
		stack.top();
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test pop() of Datum Stack
/// Edge: pop from an empty stack
/// </summary>
void testPop() {
	Datum datas[3] = { Datum(1),Datum("#t"),Datum("{ 1 2 + }") };
	DatumStack stack = DatumStack(datas, 3);
	try {
		stack.pop();
		stack.pop();
		assert(stack.size() == 1);
		stack.pop();
		stack.pop();
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test the push of DatumStack
/// </summary>
void testPush() {
	DatumStack stack;
	stack.push(Datum(1));
	stack.push(Datum(1));
	stack.push(Datum(1));
	stack.push(Datum(1));
	assert(stack.size() == 4);
}


//---------test RPNCalc------


/*
* Note: before complie and running these test
* You must change the private functions of
* RPNCalc into Public.
* Otherwise, there will be some complie error
*/

/// <summary>
/// test the Constructor of RPNCalc
/// </summary>
void testRPNCalcConstructor() {
	RPNCalc calc;
}
/// <summary>
/// this is the init run, with nothing input;
/// </summary>
void testRPNCalcRun() {
	RPNCalc calc;
	//calc.run(); // this is not enable at the final test otherwise
	//it will cause the process waitting for input from cin
}
/// <summary>
/// test if the RPNCalc can quit
/// </summary>
void testCommandQuit() {
	RPNCalc calc;

	//the following may not pass complie
	//for some functions has been set private
	//in the final edition program

	std::string s = "quit";
	std::istringstream iss(s);
	calc.execCommands(iss);
}
/// <summary>
/// test the command print
/// </summary>
void testCommandPrint() {
	try {
		RPNCalc calc;
		std::string s = "print";
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}

}
/// <summary>
/// test the command N
/// </summary>
void testCommandN() {
	RPNCalc calc;
	std::string s = "100 print";
	std::istringstream iss(s);
	calc.execCommands(iss);
}
/// <summary>
/// test the command #t 
/// </summary>
void testCommandT() {
	RPNCalc calc;
	std::string s = "#t print";
	std::istringstream iss(s);
	calc.execCommands(iss);
}

/// <summary>
/// test the command #f
/// </summary>
void testCommandF() {
	RPNCalc calc;
	std::string s = "#f print";
	std::istringstream iss(s);
	calc.execCommands(iss);
}
/// <summary>
/// test the command { rstirng }
/// </summary>
void testCommandRstring() {
	RPNCalc calc;
	std::string s = "{ rstring } print";
	std::istringstream iss(s);
	calc.execCommands(iss);
}

/// <summary>
/// test the command not
/// </summary>
void testCommandNot() {
	RPNCalc calc;
	std::string s = "#t not print";
	std::istringstream iss(s);
	calc.execCommands(iss);
}
/// <summary>
/// Edge test the command not
/// </summary>
void testCommandNotEdge() {
	try {
		RPNCalc calc;
		std::string s = "not print";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}

}
/// <summary>
/// test the command clear
/// </summary>
void testCommandClear() {
	try {
		RPNCalc calc;
		std::string s = "1 2 3 print clear print";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test the command drop
/// </summary>
void testCommandDrop() {
	try {
		RPNCalc calc;
		std::string s = "1 2 print drop print";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what()<<std::endl;
	}
}
/// <summary>
/// test the command dup
/// </summary>
void testCommandDup() {
	try {
		RPNCalc calc;
		std::string s = "1 print dup print drop drop dup";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test command swap
/// </summary>
void testCommandSwap() {
	try {
		RPNCalc calc;
		std::string s = "1 print 2 print swap print drop print swap";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test + - * / mod
/// </summary>
void testCommandArithmeticOperation() {
	try {
		RPNCalc calc;
		std::string s = "1 2 + print 2 3 * print 3 2 - print \
			10 2 / print 5 2 mod print #t 1 + ";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
///Test the command < > <= >= ==
/// </summary>
void testCommandRelationOperation() {
	try {
		RPNCalc calc;
		std::string s = "1 2 < print 1 2 > print 1 2 >= print \
			1 2 <= print 1 2 == print #t 1 < print ";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test the command exec rstring
/// </summary>
void testCommandExec() {
	try {
		RPNCalc calc;
		std::string s = "{ 1 2 + print } exec 1 exec";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test the command file
/// </summary>
void testCommandFile() {
	try {
		RPNCalc calc;
		std::string s = "1 file";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		RPNCalc calc;
		std::string s = "{ xxx } file";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		RPNCalc calc;
		std::string s = "{ add.cylc } file";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test the command if
/// </summary>
void testCommandIF(){
	try {
		RPNCalc calc;
		std::string s = "1 2 3 if";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		RPNCalc calc;
		std::string s = "#true 2 3 if";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		RPNCalc calc;
		std::string s = "#t { 1 2 + print } { 2 1 - print } if";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		RPNCalc calc;
		std::string s = "#f { 1 2 + print } { 2 1 - print } if";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}
/// <summary>
/// test input a unimplement command
/// </summary>
void testCommandUnimplemented() {
	try {
		RPNCalc calc;
		std::string s = "XASFD";
		std::istringstream iss(s);
		calc.execCommands(iss);
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}