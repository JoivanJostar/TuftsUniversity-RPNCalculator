/*
* this is the implemation of parseRString() function
* if you use it, please add this file into your project
* and add a function declaration  
* std::string parseRString(istream& input);
* into the file where you want call this function
*/

#include<string>
#include<iostream>
using namespace std;
string parseRString(istream& input) {
    string nextStr = "";
    string ret = "{ ";
    int count = 1;
    while (!input.fail()&&count!=0)
    {
        input >> nextStr;
        if (input.fail())
            continue;
        ret += nextStr + " ";
        if (nextStr == "{")
            count++;
        else if (nextStr == "}") {
            --count;
            if (count > 0)
                continue;
            else if (count == 0) {
	continue;
            }
            else
                throw runtime_error("parseRString error unexcepted situation with count <0");
        }
    }
    if (count != 0) //read the eof but has not match all the { 
        throw runtime_error("parseRString error mismatch }");
    ret.pop_back();//remove the last space  "{ 2 3 + } " -> "{ 2 3 + }"
    return ret;
}