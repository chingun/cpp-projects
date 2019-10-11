//  author: Chingun Khasar
//  functions.cpp
//  EECS281:Project1
//
//  Created by Chingun Khasar on 9/7/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#include "functions.h"
using namespace std;

// < using string streams >
// ostringstream , as described in class, to help optimize your
// performance when writing output
// walls and minions are the same thing with different characters

//might not work?? check quickly

vector<vector<blocks> > blank_room(int axis){
    blocks i;
    i.prev = 'x';
    i.chara = '.';
    i.was_found = false;
   
    vector<blocks> onedimarray(axis,i);
    vector<vector<blocks> > twoDimArray(axis,onedimarray);
    return twoDimArray;
}

//might not work?? check quickly
vector<vector<vector<blocks> > > blank_rooms(int room_num, int axis){
    vector<vector<vector<blocks> > > map(room_num, blank_room(axis));
    return map;
}


//Check for whether the input was already entered?
//Check for whether the room numbers are < than the number of rooms inside?
//If S is in memory stop checking it anymore!
void map_in_modeL(vector<vector<vector<blocks> > >& map, coord &locS_in,coord &locC_in, int N, int R){
    int row = 0;
    int col = 0;
    int room = 0;
    char symb;
    char first;
    char junk;
    string trash;
    while((cin >> first)){ // execute only if new_line read properly
        //cout << '\n' << first << '\n' << '\n';
        //if(first == 'x') {
        //    break; //used for debugging
        //    return;
        //}
        if(first == '/'){
            getline(cin, trash);
	    if(trash[0] != '/'){
    	 	cerr << "Error 1.2: mode L wrong line input \n";
    	        exit(1);
	    }
        }
        else if(first == '('){
            cin >> room >> junk >> row >> junk >> col >> junk >> symb >> junk;
            //cout << room << ',' << row << ',' << col << ',' << symb << '\n';
            if((row < N)&&(col < N)&&(room < R)){
	   	    if (symb == '.') {}
		    else if(('0' <= symb && symb <= '9') || (symb == '#')|| (symb == '!')){ //Changed R + '0' to '9' due to error, shouldnt the portal give you error when you do that, this means you have to do extra checking when inputting to register!!!!!
			map[room][row][col].chara = symb;
			//cout <<  '\n' << symb << '\n';
		    }
		    else if(symb == 'S'){//new
			locS_in.room = room;
			locS_in.row = row;
			locS_in.col = col;
			map[room][row][col].chara = symb;
			map[room][row][col].was_found = true;
		    }
		    else if(symb == 'C'){
			locC_in.room= room;
			locC_in.row = row;
			locC_in.col = col;
			map[room][row][col].chara = symb;
			map[room][row][col].was_found = false;
		    }
		    else{
			cout << "Error 1.3: mode L wrong input CHARACTER: " << symb << "\n";
			exit(1);
		    }
	   }
	   else{
		cerr << "Error 1.4: incorrect input line margin \n";
		exit(1);
	   }	
	}
        else{
            cerr << "Error 1.2: mode L wrong line input \n";
            exit(1);
        }
    }
}

void map_in_modeM(int N, int R, vector<vector<vector<blocks> > >& map,
                  coord &locS_in,coord &locC_in){
    int row = 0;
    int col = 0;
    int room = 0;
    string line;

    /*
    If you are referring to the resize functions, you can try the following: set up nested loops such that first you assign the needed number of columns to all rows on the first level, then do the same on the second level, and so on until you have done that on all levels.
    */
    while(room < R){
        if((getline(cin, line)) && (line != "")){
            //if(line[0] == 'x') break;
            if(line[0] == '/'){
		if(line[1] != '/'){
		    cerr <<"Wrong input line \n";
		    exit(1);
	    	}
	    }
            else{
                for (col = 0; col < N; ++col){
		    if(line[col] == '.'){}
		    else if((line[col] == '#')||(line[col] == '!')
			||(('0' <= line[col])&&(line[col] <= '9'))){
                        (map[room][row][col]).chara = line[col];
		    }
                    else if(line[col] == 'S'){
                        locS_in.room = room;
                        locS_in.row = row;
                        locS_in.col = col;
        	        (map[room][row][col]).chara = line[col];             
		    }
                    else if(line[col] == 'C'){
                        locC_in.room = room;
                        locC_in.row = row;
                    	locC_in.col = col;
                        (map[room][row][col]).chara = line[col];  
		    }
		    else{
			cerr << "Error 1.5: Wrong character in map input \n";
			exit(1);
		    } 
                }
                row += 1;
                if(row == N){
                    row = 0;
                    room += 1;
                }
            }
        }
    }
}


void read_input_in(maze_type& return_maze){//make it return pointer
    // read from first 3 lines
	char mode = 'x' ; // M = map L = List
   
    cin >> mode >> return_maze.N >> return_maze.R;
    
	if(return_maze.R >= 10 || return_maze.R < 0){
        cerr << "Error 1.1: wrong number of ROOMS input \n";
        exit(1);
    }
	if(return_maze.R < 0){
		cerr << "Error 1.1: wrong AXIS number \n";
		exit(1);
	}
    
    // initialization of the rooms
    return_maze.map = blank_rooms(return_maze.R, return_maze.N);
    
    // used in the loop
    string trash;
    string infos;
    
    if (mode == 'M'){
        map_in_modeM(return_maze.N, return_maze.R, return_maze.map,  return_maze.loc_S, return_maze.loc_C);
    }
    else if (mode == 'L'){
        map_in_modeL(return_maze.map, return_maze.loc_S,  return_maze.loc_C, return_maze.N, return_maze.R);
    }
    else{
        cerr << "Error 1.0: wrong MODE input \n";
        exit(1);
    }
}


void print_map(maze_type& the_maze, bool print_type){
    ostringstream os;
        coord C = the_maze.loc_C;
        vector<coord> output;
        os << the_maze.N << '\n' << the_maze.R << '\n';
	if(print_type) os << "//path taken\n"; // wrong at this point
        int i = -1;

	output.push_back(the_maze.loc_C);

	while(!((C.room == (the_maze.loc_S).room)
	       &&(C.row == (the_maze.loc_S).row)
	       &&(C.col == (the_maze.loc_S).col))){
		if (((the_maze.map)[C.room][C.row][C.col]).prev == 'n'){
			C.row -= 1;		
		}
		else if (((the_maze.map)[C.room][C.row][C.col]).prev == 'e'){
			C.col += 1;
		}
		else if (((the_maze.map)[C.room][C.row][C.col]).prev == 's'){
			C.row += 1;
		}
		else if (((the_maze.map)[C.room][C.row][C.col]).prev == 'w'){
			C.col -= 1;
		}
		else if (('0' <= ((the_maze.map)[C.room][C.row][C.col]).prev)&&(((the_maze.map)[C.room][C.row][C.col]).prev < the_maze.R + '0')){
			C.room = (int)(((the_maze.map)[C.room][C.row][C.col]).prev - '0');
		}
		else{
			cerr << "FUCK \n";
			exit(1);
		}
		output.push_back(C);
		i += 1;
	} //DO NOT TOUCH THE ABOVE
	output.push_back(the_maze.loc_S);
	i += 1;

        for (; i > 0; i--) {
		if((output[i-1]).row != (output[i]).row){
		    if ((output[i-1]).row > (output[i]).row){
				(the_maze.map)[(output[i]).room][(output[i]).row][(output[i]).col].chara = 's';
		    }
		    else{
				(the_maze.map)[(output[i]).room][(output[i]).row][(output[i]).col].chara = 'n';
			}
		}
		else if((output[i-1]).col != (output[i]).col){
			if ((output[i-1]).col > ((output[i]).col)){
				(the_maze.map)[(output[i]).room][(output[i]).row][(output[i]).col].chara = 'e';
			}
			else{
				(the_maze.map)[output[i].room][output[i].row][output[i].col].chara = 'w';
			}
		}
		else{
			(the_maze.map)[(output[i]).room][(output[i]).row][(output[i]).col].chara = 'p';
		}	
		if(print_type){
			os << '(' << (output[i]).room << ',' << (output[i]).row << ',' <<  (output[i]).col << ',' 
			   << ((the_maze.map)[(output[i]).room][(output[i]).row][(output[i]).col]).chara << ')' <<'\n';
		}
	}
	if(print_type){
		cout << os.str();
	}
	if(!print_type){
		for (int i = 0; i < the_maze.R; i++) {
			os << "//castle room " << i << '\n';
			for (int j = 0; j < the_maze.N; j++) {
				for (int k = 0; k < the_maze.N; k++) {
				    os << (the_maze.map[i][j][k]).chara;
				}
				os << '\n';
			}
		}
		cout << os.str();
	}
}



