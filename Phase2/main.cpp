#include <iostream>
#include <string>
#include <sstream>
#include "Datum.h"
#include <vector>
#include "RPNCalc.h"
using namespace std;


int main(int argc, char* argv[]) {
	(void)argc;
	string program_name = argv[0];
	RPNCalc clac;
	clac.run();
	return 0;
}