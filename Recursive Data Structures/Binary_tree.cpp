/*
 * Binary_tree.h
 *
 *  Created on: Feb 2, 2014
 *      Author: James Perretta
 *       Email: jameslp@umich.edu
 */

#include "Binary_tree.h"

#include <cassert>

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath> // pow
#include <set>
#include <stack> // used in get_max_elt_width()

using std::cout;
using std::endl;

using std::string;
using std::ostream;
using std::ostringstream;
using std::setw;
using std::left;
using std::right;

using std::set;
using std::stack;

using std::exception;

const char* const c_leaf_branch_special = "/\\";

/*
 * A class to represent the non-whitespace squares of output using
 * a grid-based tree printing scheme.
 * Holds x and y coordinates and a value, which could be either the value
 * held by a particular tree node or one of / or \ to improve readability
 * of the printed tree.
 */
class Binary_tree::Tree_grid_square
{
public:
  template<typename T>
  Tree_grid_square(int x_, int y_, T value_) :
  x(x_), y(y_)
  {
    std::ostringstream oss;
    oss << value_;
    value = oss.str();
  }

  // Probe ctor
  Tree_grid_square(int x_, int y_) :
    x(x_), y(y_)
  {
  }

  /*
   * A square is considered less than another if it is closer to
   * the root of the tree. If two squares are at the same y coordinate,
   * whichever one is farthest left is considered less.
   * This ordering is solely for the purpose of storing in a sorted container.
   */
  bool operator<(const Tree_grid_square& rhs) const
  {
    if( y < rhs.y )
    {
      return true;
    }
    if( y == rhs.y )
    {
      return x < rhs.x;
    }
    return false;
  }

  /*
   * Sends the value held at this coordinate to the given string stream.
   */
  std::string get_value() const
  {
    return value;
  }

  int get_x() const
  {
    return x;
  }

  int get_y() const
  {
    return y;
  }

private:
  int x;
  int y;
  std::string value;
};

/*
 * Container to build and hold a set of Tree_grid_squares.
 */
class Binary_tree::Tree_grid
{
public:

  Tree_grid(const Binary_tree& tree) :
    num_levels(tree.get_height(tree.root)), leftmost_x(0), rightmost_x(0)
{
    build(tree.root);
}

  /*
   * Convenience wrapper of set::find(). Returns a pointer to the
   * Tree_grid_square in the set or 0 if not found.
   */
  const Tree_grid_square* find(const Tree_grid_square& coordinate) const
  {
    std::set<Tree_grid_square>::iterator it = coordinates.find(coordinate);
    if( it == coordinates.end() )
    {
      return 0;
    }
    return &*it;
  } // find wrapper

  /*
   * Returns the number of levels in the traversed tree.
   */
  int get_num_levels() const
  {
    return num_levels;
  } // get_num_levels

  /*
   * Returns the leftmost x coordinate in the traversed tree.
   */
  int get_leftmost_x() const
  {
    return leftmost_x;
  } // get_lowest_x

  /*
   * Returns the rightmost x coordinate in the traversed tree.
   */
  int get_rightmost_x() const
  {
    return rightmost_x;
  }

private:
  set<Tree_grid_square> coordinates;
  int num_levels;
  int leftmost_x;
  int rightmost_x;

  /*
   * Recursively fills the set of Node_coordinates
   */
  void build(const Node* root_node, int cur_x = 0, int cur_y = 0)
  {
    if( !root_node )
    {
      return;
    }
    coordinates.insert(Tree_grid_square(cur_x, cur_y, root_node->elt));
    if( cur_x < leftmost_x )
    {
      leftmost_x = cur_x;
    }
    if( cur_x > rightmost_x )
    {
      rightmost_x = cur_x;
    }

    int x_offset = calculate_x_offset(num_levels, cur_y / 2);

    // Slashes indicating parent-child relationships.
    int branch_x_offset = (x_offset) <= 1 ? 1 : x_offset / 2;

    int left_branch_x = cur_x - branch_x_offset;
    int left_branch_y = cur_y + 1;
    Tree_grid_square left_branch(left_branch_x, left_branch_y, "/");

    int right_branch_x = cur_x + branch_x_offset;
    int right_branch_y = cur_y + 1;
    Tree_grid_square right_branch(right_branch_x, right_branch_y, "\\");


    // Special case where leaf branches collide.
    set<Tree_grid_square>::iterator collision_iter = coordinates.find(left_branch);
    if (collision_iter != coordinates.end())
    {
      coordinates.erase(collision_iter);
      coordinates.insert(
        Tree_grid_square(left_branch.get_x(), left_branch.get_y(),
                         c_leaf_branch_special));
    }
    else
    {
      coordinates.insert(left_branch);
    }

    coordinates.insert(right_branch);

    build(root_node->left, cur_x - x_offset, cur_y + 2);
    build(root_node->right, cur_x + x_offset, cur_y + 2);
  } // build
};

//-----------------------------------------------------------------------------

/* Assignment operator overload */
const Binary_tree& Binary_tree::operator=(const Binary_tree& rhs)
{
  Binary_tree temp(rhs);
  swap(temp);
  return *this;
} // copy assignment

/*
 * Returns the elt of the root node.
 * Throws Binary_tree_exception if three is empty.
 */
int Binary_tree::get_elt() const
{
  verify_tree_not_empty();
  return root->elt;
} // get_elt

/*
 * Returns a binary tree that is a copy of this tree's left subtree.
 */
Binary_tree Binary_tree::get_left_tree() const
{
  verify_tree_not_empty();
  Binary_tree new_tree(root->left);
  return new_tree;
} // get_left_tree

/*
 * Returns a binary tree that is a copy of this tree's right subtree.
 */
Binary_tree Binary_tree::get_right_tree() const
{
  if( !root )
  {
    throw Tree_exception("Error: tree empty");
  }
  Binary_tree new_tree(root->right);
  return new_tree;
} // get_right_tree

/*
 * Swaps the contents of rhs with this.
 */
void Binary_tree::swap(Binary_tree& rhs)
{
  std::swap(this->root, rhs.root);
} // swap

/* Returns an (actually) human-readable string representation of the tree */
string Binary_tree::to_string() const
{
  if( !root )
  {
    return "( )";
  }
  int node_width = get_max_elt_width();
  Tree_grid coordinates(*this);

  ostringstream oss;
  string padding(node_width, ' ');
  int farthest_left = coordinates.get_leftmost_x() - node_width;
  int farthest_right = coordinates.get_rightmost_x() + node_width;
  // Two printed lines per tree level: one for the values, one for the
  // slash characters (branches).
  for( int y = 0; y <= coordinates.get_num_levels() * 2; ++y )
  {
    oss << "\n";
    for( int x = farthest_left; x <= farthest_right; ++x )
    {
      const Tree_grid_square* tgs_ptr = coordinates.find(
          Tree_grid_square(x, y));
      if( tgs_ptr )
      {
        // TODO width field in square?
        if( tgs_ptr->get_value() == "/" )
        {
          oss << right;
          oss << setw(node_width);
          oss << tgs_ptr->get_value();
        }
        else if( tgs_ptr->get_value() == "\\" )
        {
          oss << left;
          oss << setw(node_width);
          oss << tgs_ptr->get_value();
        }
        else if( tgs_ptr->get_value() == c_leaf_branch_special )
        {
          oss << '\\' << string(node_width - 2, ' ') << '/';
        }
        else
        {
          oss << setw(node_width);
          oss << tgs_ptr->get_value();
        }
      }
      else
      {
        oss << padding;
      }
    } // for x
//    oss << "\n";
  } // for y
  return oss.str();
} // to_string

/* Prints an (actually) human-readable representation of the tree */
void Binary_tree::print() const
{
  assert(false);
  cout << to_string() << endl;
} // print

ostream& operator<<(ostream& os, const Binary_tree& tree)
{
  os << tree.to_string();
  return os;
} // operator<<

//----------------------------------------------------------------------------

/* Prints an in order traversal of this tree */
void Binary_tree::print_traversal() const
{
  cout << traversal_str() << endl;
} // print_traversal

/*
 * Returns a string representation of this tree's traversal.
 */
string Binary_tree::traversal_str() const
{
  return "(" + traversal_str(root) + " )";
} // traversal_str

/*
 * Prints an in order traversal of the tree starting with the given root.
 */
string Binary_tree::traversal_str(Node* root_) const
{
  if( !root_ )
  {
    return "";
  }
  ostringstream result;
  result << traversal_str(root_->left) << "";
  result << ' ' << root_->elt;
  result << "" << traversal_str(root_->right);
  return result.str();
} // traversal_str

/*
 * Copies root_copy_to and all of its child nodes to root_copy_from.
 * Requires that root_copy_to has been cleared first.
 */
void Binary_tree::copy_tree(Node*& root_copy_to, const Node* root_copy_from)
{
  try
  {
    if( !root_copy_from )
    {
      root_copy_to = 0;
      return;
    }
    root_copy_to = new Node(root_copy_from->elt);
    copy_tree(root_copy_to->left, root_copy_from->left);
    copy_tree(root_copy_to->right, root_copy_from->right);
  }
  catch( exception& e )
  {
    delete_tree(root_copy_to);
    throw;
//    throw Tree_exception("An unexpected error occurred copying trees");
  }
} // copy_tree

/*
 * Deletes the root_ node and all its children.
 */
void Binary_tree::delete_tree(Node* root_)
{
  if( !root_ )
  {
    return;
  }
  delete_tree(root_->left);
  delete_tree(root_->right);
  delete root_;
  root_ = 0;
} // delete_tree

/*
 * Throws Tree_exception if the tree is empty.
 */
void Binary_tree::verify_tree_not_empty() const
{
  if( !root )
  {
    throw Tree_exception("Error: tree empty");
  }
} // verify_tree_not_empty

/*
 * Returns the height (number of levels) in this tree.
 * The empty tree is of height 0, whereas a single node tree is of height 1.
 */
int Binary_tree::get_height(const Node* root) const
{
  if( !root )
  {
    return 0;
  }
  int left_depth = get_height(root->left);
  int right_depth = get_height(root->right);

  return 1 + (left_depth > right_depth ? left_depth : right_depth);
} // get_height

namespace
{
  int num_digits(int num)
  {
    if( !num )
    {
      return 1;
    }
    int count = 0;
    while( num )
    {
      ++count;
      num /= 10;
    }
    return count;
  }
}

const int c_min_elt_width = 2;

/*
 * Returns the width (number of digits) of the widest elt in this tree.
 */
int Binary_tree::get_max_elt_width() const
{
  int current_max = c_min_elt_width;
  stack<Node*> nodes;
  nodes.push(root);
  while( !nodes.empty() )
  {
    Node* current = nodes.top();
    nodes.pop();
    if( !current )
    {
      continue;
    }
    int width = num_digits(current->elt);
    if( width > current_max )
    {
      current_max = width;
    }
    nodes.push(current->left);
    nodes.push(current->right);
  } // while
  return current_max;
} // get_max_elt_width

/*
 * Given the height of a tree and the index of the current level (0 being the
 * root level), returns the horizontal distance (number of grid squares)
 * between the current node and one of its two children.
 *
 * Note that in order for the tree to be printed elegantly, the horizontal
 * distance between nodes must increase as the tree becomes taller.
 */
int Binary_tree::calculate_x_offset(int tree_height, int current_level)
{
  return pow(2, tree_height) / pow(2, current_level + 2);
}
