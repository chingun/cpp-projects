/*
 * Recursive_list.h
 *
 *  Created on: Apr 6, 2014
 *      Author: James Perretta
 *       Email: jameslp@umich.edu
 */

#ifndef RECURSIVE_LIST_H
#define RECURSIVE_LIST_H

#include <string>
#include <stdexcept>

class Recursive_list
{
public:
  // Constructs an empty list
  Recursive_list() :
    first(0)
  {
  }

  // Constructs a single element list.
  explicit Recursive_list(int elt) :
    first(new Node(elt))
  {
  }

  // Constructs a list from the given element and a copy of
  // the elements of the given list.
  Recursive_list(int elt, const Recursive_list& lst);

  Recursive_list(const Recursive_list& other);

  Recursive_list& operator=(const Recursive_list& rhs);

  void swap(Recursive_list& rhs);

  ~Recursive_list();

  // Returns true if the list is empty, false otherwise.
  bool is_empty() const
  {
    return !first;
  }

  // Returns the first element of the list. Throws List_exception
  // if list is empty.
  int get_first_elt() const;

  // Returns a copy of the rest of the list. Throws List_exception
  // if list is empty.
  Recursive_list get_rest_list() const;

  // Returns a string representation of the list.
  std::string to_string() const;

  // Prints the list
  void print() const;

private:
  struct Node
  {
    int elt;
    Node* next;

    Node(int elt_) :
      elt(elt_), next(0)
    {
    }
  };

  Node* first;

private:
  // Constructs a list by making a copy of the given node and all subsequent
  // nodes.
  Recursive_list(const Node* node_ptr);

  // Copies copy_from and all of its subsequent nodes to copy_to.
  void copy_nodes(Node*& copy_to, const Node* copy_from);

  // Deletes start and all its subsequent nodes.
  void delete_nodes(Node*& start);

  // Throws List_exception if the list is empty.
  void verify_list_not_empty() const;
};

//-----------------------------------------------------------------------------

class List_exception: public std::runtime_error
{
public:
  List_exception(const std::string& error_msg_) :
      std::runtime_error(error_msg_)
  {
  }

};

#endif
