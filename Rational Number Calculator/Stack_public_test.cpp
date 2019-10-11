#include "Stack.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


void test1() {
  Stack<int> s;
  assert(s.empty());
}

void test2() {
  Stack<int> s;
  s.push(3);
  s.push(5);
  assert(!s.empty());
  assert(s.pop() == 5);
  assert(!s.empty());
  assert(s.pop() == 3);
  assert(s.empty());
}

/* Helpers.  */
bool compareWith2(int n) {
  return (n == 2);
}

bool compareWith3(int n) {
  return (n == 3);
}


bool compareWithFive(int n) {
  return (n == 5);
}

bool compareWithTwenty(int n) {
  return (n == 20);
}

/* End of helpers */

void test_countitem() {
  Stack<int> s;
  s.push(2);
  s.push(3);
  s.push(2);
  s.push(2);
  s.push(4);
  s.push(5);
  s.push(2);
  // We are using function pointers in the following tests. Functors will be
  // more convenient to avoid writing a function for every possible value that
  // we may want to compare with.
  assert(s.count_if(compareWith2) == 4);
  assert(s.count_if(compareWith3) == 1);
  assert(s.count_if(compareWithFive) == 1);
  assert(s.count_if(compareWithTwenty) == 0);
}




int main() {
  test1();
  test2();
  test_countitem();

  Stack<int> my_stack;
  my_stack.size();
  cout << my_stack << endl;
  my_stack.push(42);
  my_stack.top();
  Stack<int> stack_cpy(my_stack);
  my_stack = stack_cpy;


  // You should add more tests to make sure your list works correctly. Not all the functions are tested in the above
  // tests. Also, you may want to make the tests more thorough than above.

  return 0;
}
