#include "List.h"

#include <iostream>

using std::cout;
using std::endl;

// THIS TEST CASE WILL ONLY TELL YOU IF YOUR CODE COMPILES.
// YOU NEED TO WRITE YOUR OWN COMPREHENSIVE TEST CASES IN List_tests.cpp

int main()
{
    List<int> my_list;

    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front();
    my_list.back();

    my_list.pop_front();
    my_list.pop_back();

    List<int> list2(my_list);
    list2 = my_list;

    List<int>::Iterator iter = my_list.begin();
    my_list.insert(iter, 42);
    iter = my_list.begin();
    my_list.erase(iter);
    iter = my_list.begin();

    List<int>::Iterator iter2 = my_list.end();

    bool b = iter == iter2;
    my_list.push_front(42);
    my_list.push_back(42);
    iter = my_list.begin();
    b = iter != iter2;
    cout << b << endl;
    ++iter;

    cout << *iter << endl;

    List<int>::Iterator iter_cpy(iter);
    iter_cpy = iter;

    --iter;

    return 0;
}
