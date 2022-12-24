/*
* unit tests file
* this file contains all the test functions
* of DatumStack and parser
*/
#include "Datum.h"
#include "DatumStack.h"
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
