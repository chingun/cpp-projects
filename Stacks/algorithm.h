//
//  algorithm.h
//  EECS281:Project1
//
//  Created by Chingun Khasar on 9/11/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#include "functions.h"
#include <deque>
#ifndef algorithm_h
#define algorithm_h

//two types of finding
// 1. using stack
//      You push an element onto the top of the stack,
//      and you can only access the top element of the stack
// 2. using queue
//      You can push an element onto the back of the queue,
//      and can only access the top element of the queue.


// REQUIRES: the_maze to have a valid path from S
//           to C
// MODIFIES: the_maze
// EFFECTS: finds the location of the Countess and
//          the path to reach her
void the_navigator(maze_type& the_maze, bool method);

//REQUIRES: nothing
//MODIFIES: the register
//EFFECTS: checks one item on maze and puts it in stack
void block_coll(deque<coord>& reg, coord check_here, maze_type& the_maze, bool& is_C_found, coord from, bool col_type);

//REQUIRES: nothing
//MODIFIES: the register
//EFFECTS: checks one item on maze and puts it in the queue

void the_backtracker(maze_type& the_maze, coord the_loc, coord loc_S);


#endif /* algorithm_h */
