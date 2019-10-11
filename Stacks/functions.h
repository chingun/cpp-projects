//  author: Chingun Khasar
//  functions.h
//  EECS281:Project1
//
//  Created by Chingun Khasar on 9/7/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#ifndef functions_h
#define functions_h

// Reason for using ints: pointers use too much memory 16 bytes or some shit

struct coord{
    int room;
    int row;
    int col;
};

struct blocks{
    char prev;
    char chara;
    bool was_found;
};

struct maze_type{
    int N;
    int R;
    vector<vector<vector<blocks> > > map;
    coord loc_S;
    coord loc_C;
};

// REQUIRES: nothing
// MODIFIES: nothing
// EFFECTS: returns a blank room with '.'s inside
vector<vector<blocks> > blank_room(int axis);

// REQUIRES: 0 <= room_num < 10
// MODIFIES:
// EFFECTS:
vector<vector<vector<blocks> > > blank_rooms(int room_num,int axis);

// REQUIRES:
// MODIFIES:
// EFFECTS:
//void print_map(vector<vector<vector<blocks> > > map, int N, int rooms, bool print_mode);
void print_map(maze_type& the_maze, bool print_type);

// REQUIRES:
// MODIFIES:
// EFFECTS:
void read_input_in(maze_type& return_maze);

// REQUIRES:
// MODIFIES:
// EFFECTS:
void map_in_modeL(vector<vector<vector<blocks> > >& map, coord &locS_in, coord &locC_in, int N, int R);

// REQUIRES:
// MODIFIES:
// EFFECTS:
void map_in_modeM(vector<vector<vector<blocks> > >& map, coord &locS_in,coord &locC_in);

#endif /* functions_h */

