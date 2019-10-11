/*
 * recursive.cpp
 *
 *  Created on: March 12, 2014
 *      Author: James Perretta
 *       Email: jameslp@umich.edu
 *
 *  Re-implementation of EECS 280 course materials.
 *  The Recursive_list and Binary_tree implementations used are my own.
 */

#include "recursive.h"

#include <iostream>

using std::cout;
using std::endl;

// EFFECTS: returns true if list is empty, false otherwise
bool list_isEmpty(const list_t& list)
{
  return list.is_empty();
}

// EFFECTS: returns an empty list.
list_t list_make()
{
  return Recursive_list();
}

// EFFECTS: given the list (list) make a new list consisting of
//          the new element followed by the elements of the
//          original list.
list_t list_make(int elt, const list_t& list)
{
  return Recursive_list(elt, list);
}

// REQUIRES: list is not empty
// EFFECTS: returns the first element of list
int list_first(const list_t& list)
{
  return list.get_first_elt();
}

// REQUIRES: list is not empty
// EFFECTS: returns the list containing all but the first element of list
list_t list_rest(const list_t& list)
{
  return list.get_rest_list();
}

// MODIFIES: cout
// EFFECTS: prints list to cout.
void list_print(const list_t& list)
{
  list.print();
}

/* ------------------------------------------------------------------------ */

// EFFECTS: returns true if tree is empty, false otherwise
bool tree_isEmpty(const tree_t& tree)
{
  return tree.is_empty();
}

// EFFECTS: creates an empty tree.
tree_t tree_make()
{
  return tree_t();
}

// EFFECTS: creates a new tree, with elt as it's element, left as
//          its left subtree, and right as its right subtree
tree_t tree_make(int elt, const tree_t& left, const tree_t& right)
{
  return tree_t(elt, left, right);
}

// REQUIRES: tree is not empty
// EFFECTS: returns the element at the top of tree.
int tree_elt(const tree_t& tree)
{
  return tree.get_elt();
}

// REQUIRES: tree is not empty
// EFFECTS: returns the left subtree of tree
tree_t tree_left(const tree_t& tree)
{
  return tree.get_left_tree();
}

// REQUIRES: tree is not empty
// EFFECTS: returns the right subtree of tree
tree_t tree_right(const tree_t& tree)
{
  return tree.get_right_tree();
}

// MODIFIES: cout
// EFFECTS: prints tree to cout.
void tree_print(const tree_t& tree)
{
  cout << tree << endl;
}

