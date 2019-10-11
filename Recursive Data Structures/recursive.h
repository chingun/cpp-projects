/*
 * recursive.h
 * 
 * A simple interface to two recursively-defined, applicative
 * structures, lists and trees.
 */

#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "Recursive_list.h"
#include "Binary_tree.h"

/*
 * lists
 *
 * A well-formed list is either:
 *      the empty list
 *   or an integer followed by a well-formed list.
 *
 * Lists are applicative (functional) data structures---in other
 * words, they are immutable.
 */

/*
 * We define lists using the following type declaration.  Don't worry
 * if you don't understand what this means---we haven't covered the
 * syntax for this sort of declaration yet.  For the purposes of this
 * project, just assume that "list_t" is the name of a type that you can
 * use just like "int" or "double".
 */

typedef Recursive_list list_t;

// EFFECTS: returns true if list is empty, false otherwise
bool list_isEmpty(const list_t& list);

// EFFECTS: returns an empty list.
list_t list_make();

// EFFECTS: given the list (list) make a new list consisting of
//          the new element followed by the elements of the
//          original list. 
list_t list_make(int elt, const list_t& list);

// REQUIRES: list is not empty
// EFFECTS: returns the first element of list
int list_first(const list_t& list);

// REQUIRES: list is not empty
// EFFECTS: returns the list containing all but the first element of list
list_t list_rest(const list_t& list);

// MODIFIES: cout
// EFFECTS: prints list to cout.
void list_print(const list_t& list);

/* ------------------------------------------------------------------------ */

/*
 * Trees
 *
 * A well-formed tree is either:
 *      the empty tree
 * or   an integer element with two well-formed trees as "children",
 *        a left "subtree" and a right subtree.
 * 
 * Here is an example of a well-formed tree:
 *
 *                     2
 *                   /   \
 *                  1    MT 
 *                /  \   
 *               MT  MT 
 *
 * This tree has two "internal" nodes (1 and 2), and three "external"
 * nodes.  By our definition, all external nodes are precisely the
 * empty tree.
 */

typedef Binary_tree tree_t;

// EFFECTS: returns true if tree is empty, false otherwise
bool tree_isEmpty(const tree_t& tree);

// EFFECTS: creates an empty tree.
tree_t tree_make();

// EFFECTS: creates a new tree, with elt as it's element, left as
// its left subtree, and right as its right subtree
tree_t tree_make(int elt, const tree_t& left, const tree_t& right);

// REQUIRES: tree is not empty
// EFFECTS: returns the element at the top of tree.
int tree_elt(const tree_t& tree);

// REQUIRES: tree is not empty
// EFFECTS: returns the left subtree of tree
tree_t tree_left(const tree_t& tree);

// REQUIRES: tree is not empty
// EFFECTS: returns the right subtree of tree
tree_t tree_right(const tree_t& tree);

// MODIFIES: cout
// EFFECTS: prints tree to cout.
void tree_print(const tree_t& tree);

#endif
