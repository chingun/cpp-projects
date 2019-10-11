// algorithm try 2
//

#include "algorithm.h"

void block_coll(deque<coord>& reg, coord check_here, maze_type& the_maze, bool& is_C_found, coord from, bool col_type){
	char chara = (the_maze.map)[check_here.room][check_here.row][check_here.col].chara;
	if(!((the_maze.map)[check_here.room][check_here.row][check_here.col].was_found)){
		if((chara == '.')||('0' <= chara && chara < the_maze.R + '0' )){
			if(col_type) reg.push_front(check_here);
			else reg.push_back(check_here);
			
		        if(check_here.row != from.row){                                                       	
                            if (check_here.row > from.row){
                                (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 'n';
                            }
                            else{
                                (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 's';
                            }
                        }
                        else if(check_here.col != from.col){
                            if (check_here.col > (from.col)){
                                (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 'w';
                            }
                            else{
                                (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 'e';
                            }
                        }
                        else{
                            (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = (char)(from.room + '0');
                        }
			((the_maze.map)[check_here.room][check_here.row][check_here.col]).was_found = true;

 
		}
		else if(chara == 'C'){
			is_C_found = true;
			((the_maze.map)[check_here.room][check_here.row][check_here.col]).was_found = true; 				
		        if(check_here.row != from.row){                                                       			
                             if (check_here.row > from.row){
                                 (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 'n';
                             }
                             else{
                                 (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 's';
                             }
                         }
                         else if(check_here.col != from.col){
                             if (check_here.col > (from.col)){
                                 (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 'w';
                             }
                             else{
                                 (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = 'e';
                             }
                         }
                         else{
                             (the_maze.map)[check_here.room][check_here.row][check_here.col].prev = (char)(from.room + '0');
			} 
			 return;

		}
		else if((chara == '!') || (chara == '#') || (the_maze.R + '0' <= chara)){}
		else{
			cout << "~ Here is the character: " << chara << '\n';
		}
	}	
}

void the_navigator(maze_type& the_maze, bool method){
	deque<coord> reg;
	reg.push_back(the_maze.loc_S);
	(the_maze.map)[(the_maze.loc_S).room][(the_maze.loc_S).row][(the_maze.loc_S).col].was_found = true;
	bool is_C_found = false;
	coord loc;
	loc.row = -1;
	loc.col = -1;
	loc.room = -1;
	coord check_here;	
	check_here.row = -1;
	check_here.col = -1;
	check_here.room = -1;

	while(!is_C_found){
		if(reg.empty()){
			cout << "no solution\n";
			exit(0);
		}
		else{
			loc = reg.front();
			reg.pop_front();
		}
			
		if((((the_maze.map)[loc.room][loc.row][loc.col]).chara == '.')||
			(((the_maze.map)[loc.room][loc.row][loc.col]).chara == 'S')){
			//check north
			if((loc.row - 1 >= 0)&&(!is_C_found)){
		            check_here.room = loc.room;
		            check_here.row = loc.row - 1;
		            check_here.col = loc.col;
		            block_coll(reg, check_here, the_maze, is_C_found, loc, method);
		        }
		        //check east
		        if((loc.col + 1 < the_maze.N)&&(!is_C_found)){
		            check_here.room = loc.room;
		            check_here.row = loc.row;
		            check_here.col = loc.col + 1;
		            block_coll(reg, check_here, the_maze, is_C_found, loc, method);
		        }
			//check south
		        if((loc.row + 1 < the_maze.N)&&(!is_C_found)){
		            check_here.room = loc.room;
		            check_here.row = loc.row + 1;
		            check_here.col = loc.col;
		            block_coll(reg, check_here, the_maze, is_C_found, loc, method);
		        }
			//check west
		        if((loc.col - 1 >= 0)&&(!is_C_found)){
		            check_here.room = loc.room;
		            check_here.row = loc.row;
		            check_here.col = loc.col - 1;
		            block_coll(reg, check_here, the_maze, is_C_found, loc, method);
		        }
		}
		else if((((the_maze.map)[loc.room][loc.row][loc.col]).chara >= '0')&&
			(((the_maze.map)[loc.room][loc.row][loc.col]).chara < '0' + the_maze.R)){
			check_here.room = (((the_maze.map)[loc.room][loc.row][loc.col]).chara) - '0';
			check_here.row = loc.row;
			check_here.col = loc.col;
			block_coll(reg, check_here, the_maze, is_C_found, loc, method);
		}
		else{
			cerr << "WRONG \n";
			exit(1);
		}
	}
}






