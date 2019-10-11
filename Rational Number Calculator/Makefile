# Makefile for EECS 280 Project 5

CXX := g++
CXXFLAGS := -Wall -Werror -pedantic -O1

list_test_srcs = $(wildcard List_test_*.cpp)
list_test_exes = $(list_test_srcs:.cpp=.exe)

all: test

test: calc Rational_public_test List_tests List_compile_check Stack_public_test
	./Rational_public_test
	./List_compile_check
	./Stack_public_test

	./calc < calc_test00.in > calc_test00.out
	diff -q calc_test00.out calc_test00.out.correct

	./calc < calc_test01.in > calc_test01.out
	diff -q calc_test01.out calc_test01.out.correct

List_tests: $(list_test_exes)
	./run_my_tests.py

calc: calc.cpp Rational.cpp List.h Stack.h
	$(CXX) $(CXXFLAGS) calc.cpp Rational.cpp -o $@

Rational_public_test: Rational_public_test.cpp Rational.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

List_test_%.exe: List_test_%.cpp List.h
	$(CXX) $(CXXFLAGS) List_test_$*.cpp -o $@

List_compile_check: List_compile_check.cpp List.h
	$(CXX) $(CXXFLAGS) List_compile_check.cpp -o $@

Stack_public_test: Stack_public_test.cpp Stack.h List.h
	$(CXX) $(CXXFLAGS) Stack_public_test.cpp -o $@

# disable built-in rules
.SUFFIXES:

# these targets do not create any files
.PHONY: clean test List_tests

clean :
	rm -vf *.o *.exe *.gch calc \
    List_tests \
    List_compile_check \
    Rational_public_test \
    Stack_public_test 
