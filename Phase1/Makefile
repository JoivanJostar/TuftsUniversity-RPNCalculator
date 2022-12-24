
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow 
LDFLAGS  = -g3 
unit_test: parser.o DatumStack.o Datum.o unit_test_driver.o
	$(CXX) $(CXXFLAGS) $^ 
parser.o: parser.cpp
	$(CXX) $(CXXFLAGS) -c parser.cpp
DatumStack.o: DatumStack.cpp DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp


# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj2_calcyoulater_phase1 DatumStack.h \
				    DatumStack.cpp parser.cpp \
				    unit_tests.h Makefile README
clean: 
	rm DatumStack.o parser.o  *~ *.gch a.out 
