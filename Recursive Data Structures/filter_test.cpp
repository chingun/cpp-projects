#include "p2.h"

#include "test_helpers.h"

#include <iostream>

using namespace std;

bool isPrime(int x)
    // EFFECTS: returns true if x is prime, false otherwise.
{
    const int limit = x/2;
    for (int i = 2; i<=limit; i++) {
	if ((x%i) == 0) {
	    return false;
	}
    }
    return true;
}

int main()
{
    int numbers[] = { 3, 20, 46, 43, 9, 17, 103, 102 };
    const int numSize = sizeof(numbers) / sizeof(int);
    int primes[] = { 3, 43, 17, 103 };
    const int primeSize = sizeof(primes) / sizeof(int);

    list_t listNums = list_make();
    list_t listPrimes = list_make();
    list_t candidate;


    for (int i = 0; i<numSize; i++) {
	listNums = list_make(numbers[numSize-i-1], listNums);
    }

    for (int i = 0; i<primeSize; i++) {
	listPrimes = list_make(primes[primeSize-i-1], listPrimes);
    }

    candidate = filter(listNums, isPrime);

    list_print(candidate);
    cout << endl;

    list_print(listPrimes);
    cout << endl;

    if (list_equal(candidate, listPrimes)) {
	cout << "Success!\n";
	return 0;
    } else {
	cout << "Failed\n";
	return -1;
    }
}
