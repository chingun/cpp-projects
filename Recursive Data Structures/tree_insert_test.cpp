#include "p2.h"

#include "test_helpers.h"

#include <iostream>

using namespace std;

int main()
{
    tree_t start = tree_make(2,
			     tree_make(1, tree_make(), tree_make()),
			     tree_make(4, tree_make(), tree_make()));
    tree_t end = tree_make(2,
			   tree_make(1, tree_make(), tree_make()),
			   tree_make(4,
				     tree_make(3, tree_make(), tree_make()),
				     tree_make()));

    tree_t candidate = insert_tree(3, start);
    tree_print(end);
    cout << endl;

    tree_print(candidate);
    cout << endl;

    if (tree_equal(candidate, end))
    {
	   cout << "Success!\n";
	   return 0;
    }
	cout << "Failed\n";
	return -1;
}
