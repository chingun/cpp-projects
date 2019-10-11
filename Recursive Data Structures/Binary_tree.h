/*
 * Binary_tree.h
 *
 *  Created on: Feb 2, 2014
 *      Author: James Perretta
 *       Email: jameslp@umich.edu
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdexcept>
#include <string>
#include <iosfwd>

/* A simple, non-balancing binary tree */
class Binary_tree
{
public:

  /* Default ctor, creates an empty Binary_tree */
  Binary_tree() :
      root(0)
  {
  }

  /* Ctor for single node tree with the given root elt. */
  explicit Binary_tree(int elt_) :
      root(new Node(elt_))
  {
  }

  /*
   * Ctor for Binary_tree with given root and copies of left and right as its
   * left and right subtrees.
   */
  Binary_tree(int elt_, const Binary_tree& left_, const Binary_tree& right_) :
      root(new Node(elt_))
  {
    copy_tree(root->left, left_.root);
    copy_tree(root->right, right_.root);
  } // Root, left, and right ctor

  /* Copy ctor */
  Binary_tree(const Binary_tree& binary_tree_) :
      root(0)
  {
    copy_tree(root, binary_tree_.root);
  }

  ~Binary_tree()
  {
    delete_tree(root);
  } // dtor

  /* Assignment operator overload */
  const Binary_tree& operator=(const Binary_tree& copy_from);

  /*
   * Returns the elt of the root node.
   * Throws Binary_tree_exception if three is empty.
   */
  int get_elt() const;

  /*
   * Returns a binary tree that is a copy of this tree's left subtree.
   */
  Binary_tree get_left_tree() const;

  /*
   * Returns a binary tree that is a copy of this tree's right subtree.
   */
  Binary_tree get_right_tree() const;

  /*
   * Swaps the contents of rhs with this.
   */
  void swap(Binary_tree& rhs);

  bool is_empty() const
  {
    return !root;
  }

  /* Prints an (actually) human-readable representation of the tree */
  void print() const;

  /* Returns an (actually) human-readable string representation of the tree */
  std::string to_string() const;

  /* Prints an in order traversal of this tree */
  void print_traversal() const;

  /*
   * Returns a string representation of this tree's traversal.
   */
  std::string traversal_str() const;

private:
  struct Node
  {
  public:
    Node(int elt_) :
      elt(elt_), left(0), right(0)
  {
  }

    int elt;
    Node* left;
    Node* right;

  private:
    Node();
  };

  class Tree_grid;
  class Tree_grid_square;

  friend class Tree_grid;

private:
  /* The root of this Binary_tree */
  Node* root;

private:

  /*
   * Returns an in order traversal of the tree starting with the given root.
   */
  std::string traversal_str(Node* root_) const;

  /*
   * Constructor that copies root_ and all its child nodes.
   */
  Binary_tree(const Node* root_)
  {
    copy_tree(root, root_);
  }

  /*
   * Copies root_copy_to and all of its child nodes to root_copy_from.
   */
  void copy_tree(Node*& root_copy_to, const Node* root_copy_from);

  /*
   * Deletes the root_ node and all its children.
   */
  void delete_tree(Node* root_);

  /*
   * Throws Tree_exception if the tree is empty.
   */
  void verify_tree_not_empty() const;

  /*
   * Returns the height (number of levels) in this tree.
   * The empty tree is of height 0, whereas a single node tree is of height 1.
   */
  int get_height(const Node* root) const;

  /*
   * Returns the width (number of digits) of the widest elt in this tree.
   */
  int get_max_elt_width() const;

  /*
   * Given the height of a tree and the index of the current level (0 being the
   * root level), returns the number of grid spaces horizontally separating
   * the current node from one of its children.
   */
  static int calculate_x_offset(int tree_height, int current_level);
};

std::ostream& operator<<(std::ostream& os, const Binary_tree& tree);

// ---------------------------------------------------------------------------

class Tree_exception: public std::runtime_error
{
public:
  Tree_exception(const std::string& error_msg_) :
      std::runtime_error(error_msg_)
  {
  }

private:
//  std::string error_msg;
};

#endif
