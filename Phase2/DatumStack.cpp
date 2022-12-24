/*
* this file is the implemation of DatumStack
* the definiton of this class is in DatumStack.h
*/

#include "DatumStack.h"
#include <iostream>
using namespace std;

//create an empty stack
DatumStack::DatumStack() {
}

/// <summary>
/// create the stack with given array
/// </summary>
/// <param name="data"></param> the array contains the Datum
/// <param name="num"></param> the size of the array
DatumStack::DatumStack(Datum data[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        stack.push_back(data[i]);
    }
}

/// <summary>
/// predicate if the stack is empty
/// </summary>
/// <returns></returns> true: empty ; false:not empty
bool DatumStack::isEmpty() {
    return stack.empty();
}


/// <summary>
/// clear the stack
/// </summary>
void DatumStack::clear() {
    stack.clear();
}

/// <summary>
/// get the size of the stack
/// </summary>
/// <returns></returns> 
size_t DatumStack::size() {
    return stack.size();
}



/// <summary>
/// get the top value of the stack but not pop it;
/// throws runtime_error("empty_stack") if the stack
/// is empty
/// </summary>
/// <returns></returns> the top Datum value
Datum DatumStack::top() {
    if (isEmpty()) {
        throw runtime_error("empty_stack");
    }
    else {
        return stack.back();
    }
}

/// <summary>
/// pop off the top element of the stack
/// throws runtime_error("empty_stack") if 
/// the stack is empty
/// </summary>
void DatumStack::pop() {
    if (isEmpty()) {
        throw runtime_error("empty_stack");
    }
    else {
        stack.pop_back();
    }
}

/// <summary>
/// push a Datum into the stack
/// </summary>
/// <param name="d"></param> the Datum Object to be pushed
void DatumStack::push(Datum d) {
    stack.push_back(d);
}
