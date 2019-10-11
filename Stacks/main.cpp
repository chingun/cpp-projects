//
//  main.cpp
//  EECS281_Project1
//
//  Created by Chingun Khasar on 9/23/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#include <iostream>
#include <getopt.h>
#include "functions.h"
#include "algorithm.h"
using namespace std;


static struct option longopts[] = {
    {"stack", no_argument, nullptr, 's'},
    {"queue", no_argument, nullptr, 'q'},
    {"output", required_argument, nullptr, 'o'},
    {"help", no_argument, nullptr, 'h'},
    {nullptr, 0, nullptr, 0}
};
 
// Declare function main() with parameters:
// argc: count of arguments on the command line
// argv: array of char pointers to the command line arguments (an array of C-strings)
int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	bool navigate_type = false; //false is queue else stack
    bool print_type = false; //false if print mode is map mode

    
    while ((c = getopt_long(argc, argv, "sqo:h", longopts, &idx)) != -1){
        switch(c){
            case 's':
		x += 1;
                navigate_type = true; 
			break;
            case 'q':
		x += 1;
                break;
            case 'o':
                if(*optarg == 'L') print_type = true;
		else if(*optarg == 'M') print_type = false;
		else{
			cerr << "False map output mode \n";
			exit(1);
		}
		break;
            case 'h':
		cout << "(--stack or --queue) -o (M or L)./superMarco <input.txt> output.txt \n"
		     << "depending on what output you want choose either M or L and depending on \n"
		     << "And depending on which route you want choose between --stack or --queue \n"
		     << "You can also simplify it with -s or -q(one or the other you cant use both).\n"
		     << "Thank you for using superMarco!" << endl;
		exit(0);
            default:
                cout << "Output mode manual Map" << endl;
        }
    }
    if ((x > 1) || (x == 0)){
	cerr << " false input mode \n";
	exit(1);
    }
    
    //the maze
    maze_type the_maze;
    
	the_maze.N = -1;
	the_maze.R = -1;
   
	//locations of start and finish
	(the_maze.loc_S).room = -1;
	(the_maze.loc_S).row = -1;
	(the_maze.loc_S).col = -1;
	(the_maze.loc_C).room = -1;
	(the_maze.loc_C).row = -1;
	(the_maze.loc_C).col = -1;
   
	read_input_in(the_maze);
    //The algorithm of where it is going
    the_navigator(the_maze, navigate_type);
    //Backtracks where it came from
    //the_backtracker(the_maze, the_maze.loc_C, the_maze.loc_S);
    //couts the map
    //print_map(the_maze.map, the_maze.N, the_maze.R, print_type);
    print_map(the_maze, print_type);

    exit(0);
}

