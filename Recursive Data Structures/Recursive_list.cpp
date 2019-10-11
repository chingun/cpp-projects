/*
 * Recursive_list.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: James Perretta
 *       Email: jameslp@umich.edu
 */

#include "Recursive_list.h"

#include <sstream>
#include <iostream>
#include <exception>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::exception;

// Constructs a list from the given element and a copy of
// the elements of the given list.
Recursive_list::Recursive_list(int elt, const Recursive_list& lst) :
    first(new Node(elt))
{
  copy_nodes(first->next, lst.first);
}

Recursive_list::Recursive_list(const Recursive_list& other) :
    first(0)
{
  copy_nodes(first, other.first);
} // copy ctor

Recursive_list& Recursive_list::operator=(const Recursive_list& rhs)
{
  Recursive_list lst(rhs);
  swap(lst);
  return *this;
}

void Recursive_list::swap(Recursive_list& rhs)
{
  std::swap(first, rhs.first);
}

Recursive_list::~Recursive_list()
{
  delete_nodes(first);
} // dtor

// Returns the first element of the list. Throws List_exception
// if list is empty.
int Recursive_list::get_first_elt() const
{
  verify_list_not_empty();
  return first->elt;
} // get_first_elt

// Returns a copy of the rest of the list. Throws List_exception
// if list is empty.
Recursive_list Recursive_list::get_rest_list() const
{
  verify_list_not_empty();
  return Recursive_list(first->next);
} // get_rest_list

// Returns a string representation of the list.
string Recursive_list::to_string() const
{
  Node* iter = first;
  ostringstream oss;
  oss << "( ";
  while( iter )
  {
    oss << iter->elt << " ";
    iter = iter->next;
  }
  oss << ")";
  return oss.str();
} // to_string

// Prints the list
void Recursive_list::print() const
{
  cout << to_string() << endl;
} // print

//-----------------------------------------------------------------------------

// Constructs a list by making a copy of the given node and all subsequent
// nodes.
Recursive_list::Recursive_list(const Node* node_ptr) :
    first(0)
{
  copy_nodes(first, node_ptr);
}

// Copies copy_from and all of its subsequent nodes to copy_to.
void Recursive_list::copy_nodes(Node*& copy_to, const Node* copy_from)
{
  try
  {
    if( !copy_from )
    {
      copy_to = 0;
      return;
    }
    copy_to = new Node(copy_from->elt);
    copy_nodes(copy_to->next, copy_from->next);
  }
  catch( exception& e )
  {
    delete_nodes(copy_to);
    throw;
  }
} // copy_nodes

// Deletes start and all its subsequent nodes.
void Recursive_list::delete_nodes(Node*& start)
{
  if( !start )
  {
    return;
  }
  delete_nodes(start->next);
  delete start;
  start = 0;
} // delete_nodes

// Throws List_exception if the list is empty.
void Recursive_list::verify_list_not_empty() const
{
  if( !first )
  {
    throw List_exception("Error: Empty list");
  }
}

