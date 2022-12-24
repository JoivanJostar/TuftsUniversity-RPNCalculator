/*
* this is a simple unit_test driver to 
* test all the function in unit_tests.h
*/
#include "unit_tests.h"
void testDatumStackClear();
int main() {

		testDatumStackClear();
		testDatumStackDeafultConstuctor();
		testDatumStackGetSize();
		testDatumStackIsEmpty();
		testDatumStackVecotorConstuctor();
		testParseRString1();
		testParseRString2();
		testPop();
		testPush();
		testTop();

		std::cout << "all tests passed\n";
	return 0;
}