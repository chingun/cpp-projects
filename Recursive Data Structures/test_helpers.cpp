#include "test_helpers.h"

// EFFECTS: Returns true if the two specified lists are equivalent.
bool list_equal(list_t first, list_t second)
{
    if (list_isEmpty(first) && list_isEmpty(second))
    {
        return true;
    }
    if (list_isEmpty(first) || list_isEmpty(second))
    {
        return false;
    }
    if (list_first(first) != list_first(second))
    {
        return false;
    }
    return list_equal(list_rest(first), list_rest(second));
}

//------------------------------------------------------------------------------

// EFFECTS: Returns true if the two specified trees are equivalent.
bool tree_equal(tree_t first, tree_t second)
{
    if (tree_isEmpty(first) && tree_isEmpty(second))
    {
        return true;
    }
    if (tree_isEmpty(first) || tree_isEmpty(second))
    {
        return false;
    }
    return ((tree_elt(first) == tree_elt(second))
        && tree_equal(tree_left(first), tree_left(second))
        && tree_equal(tree_right(first), tree_right(second)));
}
