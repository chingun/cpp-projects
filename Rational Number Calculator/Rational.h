#ifndef RATIONAL_H
#define RATIONAL_H
/* Rational.h
 *
 * Representation of a rational number
 * EECS 280 Project 5
 *
 * DO NOT MODIFY THIS FILE!  Write your function implementations in
 * Rational.cpp
 */

#include <iostream>
#include <cstdlib>
#include <cassert>


class Rational {
  /*OVERVIEW
    Represent a rational number as a ratio of two integers, numerator and
    denominator.
    Think of the rational number as equivalent to numerator/denominator.
    You want to avoid
    running into unnecessary overflow problems since C++ limits
    the range of integers. Observe the following rules to keep
    your rational numbers in "reduced form" to
    avoid unnecessary integer overflows and wrong results:

    Invariant #1: Keep denominator as always >= 0. numerator can be negative,
    0, or positive.

    Invariant #2: numerator and denominator should not have a common factor
    other than 1.
    Eliminate any common factors.

    Invariant#3: When the rational number is equivalent to an integer,
    including 0, denominator must be 1.

    Invariant#4: When denominator is 0, numerator must be -1, 0, or 1.

    Note: You can assume that for all caculations that we will give
    you, both numerator and denominator for all rational numbers will
    be small enough to not cause integer overflows. But, your code
    should be able to handle situations like 2/3 being repeatedly multiplied
    by 100/100 without overflowing. You will be fine as long as you always
    keep your rational numbers in reduced form.
  */

 private:
  int numerator;
  int denominator;

 public:
  // EFFECTS: Constructor for rational number that is equivalent to integer 0.
  Rational();

  // EFFECTS: Constructor for rational number that is equivalent
  // to integer val.
  Rational(int val);

  // EFFECTS: Constructor for a rational number that is equivalent to
  // numerator_in/denominator_in.
  // Remember to ensure the Invariants.
  Rational(int numerator_in, int denominator_in);

  // EFFECTS: Returns numerator that is consistent with the invariants.
  int get_numerator() const;

  // EFFECTS: Returns denominator that is consistent with the invariants.
  // after eliminating any common factors. See invariants.
  int get_denominator() const;
};

// Overloaded operators on Rational numbers. Note that these are defined
// outside the class. It is possible to make these member functions, but
// this may be more intuititve.

// MODIFIES: output stream os
// EFFECTS: Prints out a rational number in reduced form
// without any spaces or newlines.
// Printing is done as
// follows. If the rational number is equivalent to an integer, just
// print the the integer value.
// Otherwise, print out numerator/denominator.
// For example, if numerator is 3 and denominator is 1, then print out 3.
// If numerator is 3 and denominator
// is 2, print out 3/2. If numerator is -4 and denominator is 3, print out -4/3.
// The function should also return the output stream os as its result
// so that << operations can be chained on a single line.
std::ostream& operator<<(std::ostream& os, const Rational& obj);

// EFFECTS: Returns a rational number equivalent to lhs + rhs.
// Note that (a/b + c/d) is algebraically equivalent to (ad+bc)/bd.
Rational operator+(const Rational &lhs, const Rational &rhs);

// EFFECTS: Returns a rational number equivalent to lhs - rhs.
//   Note that (a/b + c/d) is algebraically
// equivalent to (ad-bc)/bd.
Rational operator-(const Rational &lhs, const Rational &rhs);

// EFFECTS: Returns a rational number equivalent to lhs * rhs.
//   Note that (a/b * c/d) is algebraically
// equivalent to ac/bd.
Rational operator*(const Rational &lhs, const Rational &rhs);

// EFFECTS: Returns a rational number equivalent to lhs / rhs.
//   Note that (a/b / c/d) is algebraically
// equivalent to ad/bc.
Rational operator/(const Rational &lhs, const Rational &rhs);

// EFFECTS: Returns true if the two rational numbers are equal.  Otherwise,
//   returns false.
bool operator==(const Rational &lhs, const Rational &rhs);

#endif //RATIONAL_H
