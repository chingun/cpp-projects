#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include "p2.h"

// EFFECTS: Returns true if the two specified lists are equivalent.
bool list_equal(list_t first, list_t second);

// EFFECTS: Returns true if the two specified trees are equivalent.
bool tree_equal(tree_t first, tree_t second);

#endif
