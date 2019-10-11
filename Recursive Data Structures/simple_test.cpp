#include "p2.h"

#include <iostream>

using namespace std;

int main()
{
    int i;
    list_t listA;
    list_t listB;

    listA = list_make();
    listB = list_make();

    for (i = 5; i > 0; --i)
    {
    	listA = list_make(i, listA);
    	listB = list_make(i + 10, listB);
    }

    list_print(listA);
    list_print(listB);

    list_print(reverse(listA));
    list_print(append(listA, listB));
}
