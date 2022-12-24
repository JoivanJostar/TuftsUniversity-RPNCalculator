
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow 
LDFLAGS  = -g3 
CalcYouLater: main.o Datum.o DatumStack.o RPNCalc.o parser.o
	$(CXX) $(CXXFLAGS) -o CalcYouLater $^ 




DatumStack.o: DatumStack.cpp DatumStack.h Datum.h 
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp
RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.h Datum.h parser.o
	$(CXX) $(CXXFLAGS) -c RPNCalc.cpp

parser.o:: parser.cpp
	$(CXX) $(CXXFLAGS) -c parser.cpp
main.o: main.cpp RPNCalc.h
	$(CXX) $(CXXFLAGS) -c main.cpp

unit_test: unit_test_driver.o DatumStack.o Datum.o RPNCalc.o parser.o
	$(CXX) $(CXXFLAGS) $^



# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj2_calcyoulater DatumStack.h DatumStack.cpp \
				RPNCalc.cpp RPNCalc.h \
				unit_tests.h main.cpp \
				Datum.h	cylc \
				add.cylc fact.cylc \
				fib.cylc mytest.cylc \
				n_fibs.cylc parser.cpp \
				Makefile README
clean: 
	rm DatumStack.o RPNCalc.o main.o parser.o *~ *.gch a.out 
