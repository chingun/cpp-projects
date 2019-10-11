#include "Rational.h"
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;


static void test_constructors() {
  Rational r;
  assert(r.get_numerator() == 0 && r.get_denominator() == 1);
  r = Rational(2, 4);
  assert(r.get_numerator() == 1 && r.get_denominator() == 2);
  r = Rational(2, -4);
  assert(r.get_numerator() == -1 && r.get_denominator() == 2);
  r = Rational(-2, -4);
  assert(r.get_numerator() == 1 && r.get_denominator() == 2);
  r = Rational(0, -4);
  assert(r.get_numerator() == 0 && r.get_denominator() == 1);
  r = Rational(-3);
  assert(r.get_numerator() == -3 && r.get_denominator() == 1);
  cout << "test_constructors passed" << endl;
}


static void test_operators() {
  Rational r1(1,2);
  Rational r2(1,4);
  assert(r1+r2 == Rational(3,4));
  assert(r1-r2 == r2);
  assert(r1*r2 == r2*r1);
  assert(r1*r2 == Rational(1,8));
  assert(r1/r2 == Rational(2, 1));
  assert(r2-r1 == Rational(-1, 4));
  assert(r1*r1 == r2);
  assert(Rational(1) / r2 == Rational(4));
  cout << "test_operators passed" << endl;
}

static string readall(stringstream &s) {
  string result = "";
  char c;
  while (s >> noskipws >> c) {   // Read characters, not skipping whitespaces
    result = result + c;       // Append character c to the the result
  }
  s.clear();                   // Reset error so that we can continue to use the stream s.
  return result;
}

static void test_io()
{
  stringstream s;
  Rational r(2,4);
  string stringr;
  s << r;
  stringr = readall(s);
  assert(stringr == "1/2");
  r = Rational(2,-4);
  s << r;
  stringr = readall(s);
  assert(stringr == "-1/2");
  r = Rational(20,5);
  s << r;
  stringr = readall(s);
  assert(stringr == "4");
  r = Rational(0,4);
  s << r;
  stringr = readall(s);
  assert(stringr == "0");
  r = Rational(-0,4);
  s << r;
  stringr = readall(s);
  assert(stringr == "0");
  cout << "test_io passed" << endl;
}

void test_overflow() {
  // Let's make sure that numerator and denominator don't blow up.
  Rational r1(3,3);
  Rational r2(2,4);
  Rational result = r2;
  for (int i = 0; i < 1000; i++) {
    result = result * r1;
  }
  assert(result == r2);
  assert(!(result == r1));

  // More tests should be added


}


int main() {
  test_constructors();
  test_operators();
  test_io();
  test_overflow();
}
