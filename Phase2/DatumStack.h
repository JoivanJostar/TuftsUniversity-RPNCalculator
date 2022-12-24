/*
* this file is the class DatumStack definition
* the interfaces and data members are defined here
* note: the stack is implemented by STL <list>
*/


#ifndef __DATUMSTACK_H__
#define __DATUMSTACK_H__
#include "Datum.h"
#include <list>

class DatumStack
{
public:
    //A default constructor,
    //which takes no parametersand initializes an empty stack.
    DatumStack();
    DatumStack(Datum data[], size_t size);
    bool isEmpty();
    void clear();
    size_t size();
    Datum top();
    void pop();
    void push(Datum d);
private:
    std::list<Datum> stack;
};


#endif


