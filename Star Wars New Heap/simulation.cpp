//
//  simulation.cpp
//  281P2
//
//  Created by Chingun Khasar on 10/17/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#include "simulation.h"

void planet::jedi_input(battalion &jedi, ostringstream &os, int &num_battles,
                        vector<generals> &gen_eval,	const sim_type &simu){
    int num = jedi.num_sdrs;
    bool looper = true;
    int saved_gen_num = -1;
    if ((!siths.empty())&&((siths.top()).force > jedi.force)&&(looper)){
        //if v
        while(((siths.top()).force >= jedi.force)&&(looper)){
            //if v
			
            if(simu.v){
        	    os << "General " << (siths.top()).gen_num;
            		saved_gen_num = (siths.top()).gen_num;
			}
            looper = ambush(jedi);
			if(simu.v){
           		 os << "'s battalion attacked General " <<
           			 jedi.gen_num << "'s battalion on planet " << jedi.planet_num << ". "
            		<< (num - jedi.num_sdrs)*2 << " troops were lost.\n";
			}
            med.push_back((num - jedi.num_sdrs)*2);

            
            //if GENERAL EVALUATION
            if(simu.g){
				gen_eval[saved_gen_num].num_dead += (num - jedi.num_sdrs);
            	gen_eval[jedi.gen_num].num_dead += (num - jedi.num_sdrs);
            	num = jedi.num_sdrs;
            }
            //Required for all
            num_battles++;
        }
    }
    if(((siths.empty())||((siths.top()).force < jedi.force))
       &&(jedi.num_sdrs != 0)){
        jedis.push(jedi);
    }
}

void planet::sith_input(battalion &sith, ostringstream &os, int &num_battles,
                        vector<generals> &gen_eval, const sim_type &simu){
    int num = sith.num_sdrs;
    bool looper = true;
    int saved_num = -1;
    if ((!jedis.empty())&&(sith.force > (jedis.top()).force)){
        while((sith.force >= (jedis.top()).force)&&(looper)){
            //if v
            if(simu.v){
        	    os << "General " << sith.gen_num;
				saved_num = sith.gen_num;
			}
			looper = attack(sith);
    	    if(simu.v){
			    os << "'s battalion attacked General " << (jedis.top()).gen_num
        	   	   << "'s battalion on planet " << sith.planet_num << ". " << (num - sith.num_sdrs)*2
        		   << " troops were lost.\n";
       		    med.push_back((num - sith.num_sdrs)*2);
            }
            //if GENERAL EVALUATION
        	if(simu.g){ 
				gen_eval[saved_num].num_dead += (num - sith.num_sdrs);
           		gen_eval[sith.gen_num].num_dead += (num - sith.num_sdrs);
            	num = sith.num_sdrs;
            }
            //Required for all
            num_battles++;
        }
    }
    else if (((jedis.empty())||(sith.force < (jedis.top()).force))
             &&(sith.num_sdrs != 0)){
        siths.push(sith);
    }
}

void simulation_DL_helper(const int &NUM_GEN, const int &NUM_PLANETS, string &type,
                          char &trash, battalion &this_time, ostringstream &os,
                          vector<generals> &gen_eval, const sim_type &simu){
    vector<planet> planet_arr;
    planet.resize(NUM_PLANETS);
    int num_battles = 0;
    cout << "\n";
    int num_planet = 0;
    int current_time = 0;
    while(cin >> this_time.timestamp){
        read_DL_inputs(type, trash, this_time.gen_num, this_time.planet_num, this_time.force, this_time.num_sdrs, cin);
        //if m
        if(simu.w){
			if(current_time != this_time.timestamp){
      	      current_time = this_time.timestamp;
      	     	for (int i = 0; i < NUM_PLANETS; i++) {
            	    if(!(((planet_arr + i))->med).empty()){
        	            os << "Median troops lost on planet " << i << " at time "
        	            << current_time << " is "
        	            << ((planet_arr + i))->check_medium() << '\n';
        	        }
        	    }
    	    }
		}
        
        if(type == "JEDI"){
            //if GENERAL EVAUATION
            gen_eval[this_time.gen_num].jedi_depd += this_time.num_sdrs;
            
            (planet_arr + this_time.planet_num) ->
            jedi_input(this_time, os, num_battles, gen_eval, simu);
            
            //if Movie Watcher
            if(simu.w){
					//Attack WORKS DONT CHANGE UNTIL YOU CHANGE
					if((((planet_arr + this_time.planet_num) -> w).pad_f < this_time.force)
					   &&(((planet_arr + this_time.planet_num) -> w).pad_f != -1)){}
					else if(((planet_arr + this_time.planet_num) -> w).ad_f > this_time.force){
						((planet_arr + this_time.planet_num) -> w).pad_f = this_time.force;
						((planet_arr + this_time.planet_num) -> w).pad_t = this_time.timestamp;
					}
					else if(((planet_arr + this_time.planet_num) -> w).ad_f == -1){
						((planet_arr + this_time.planet_num) -> w).ad_f = this_time.force;
						((planet_arr + this_time.planet_num) -> w).ad_t = this_time.timestamp;
					}
					//Ambush WORKS DONT CHANGE UNTIL YOU CHANGE
					if(((((planet_arr + this_time.planet_num) -> w).pamd_f - this_time.force) >
						(((planet_arr + this_time.planet_num) -> w).am_f) - this_time.force)||
					   (((planet_arr + this_time.planet_num) -> w).amd_f > this_time.force)){
							((planet_arr + this_time.planet_num) -> w).amd_f = this_time.force;
							((planet_arr + this_time.planet_num) -> w).amd_t = this_time.timestamp;
						
						if(((planet_arr + this_time.planet_num) -> w).pamd_f != -1){
							((planet_arr + this_time.planet_num) -> w).am_f =
							((planet_arr + this_time.planet_num) -> w).pamd_f;
							((planet_arr + this_time.planet_num) -> w).am_t =
							((planet_arr + this_time.planet_num) -> w).pamd_t;
							((planet_arr + this_time.planet_num) -> w).pamd_f = -1;
							((planet_arr + this_time.planet_num) -> w).pamd_t = -1;
						}
            	}
			}
        }
        else if(type == "SITH"){
            
            //if GENERAL EVAUATION
            gen_eval[this_time.gen_num].sith_depd += this_time.num_sdrs;
            
            (planet_arr + this_time.planet_num) -> sith_input(this_time, os, num_battles, gen_eval, simu);
            if(simu.w){
					//if MOVIE WATCHER
					//Attack WORKS DONT CHANGE UNTIL YOU CHANGE
					if((((planet_arr + this_time.planet_num) -> w).a_f < this_time.force)&&
					   (((planet_arr + this_time.planet_num) -> w).ad_f != -1)){
						((planet_arr + this_time.planet_num) -> w).a_f = this_time.force;
						((planet_arr + this_time.planet_num) -> w).a_t = this_time.timestamp;
						if(((planet_arr + this_time.planet_num) -> w).pad_f != -1){
							((planet_arr + this_time.planet_num) -> w).ad_f = ((planet_arr + this_time.planet_num) -> w).pad_f;ttles++;
							((planet_arr + this_time.planet_num) -> w).ad_t = ((planet_arr + this_time.planet_num) -> w).pad_t;
							((planet_arr + this_time.planet_num) -> w).pad_f = -1;
							((planet_arr + this_time.planet_num) -> w).pad_t = -1;
						}
					}
					//Ambush WORKS DONT CHANGE UNTIL YOU CHANGE
					if(((planet_arr + this_time.planet_num) -> w).am_f < this_time.force){
						if(((planet_arr + this_time.planet_num) -> w).pamd_f == -1){
							((planet_arr + this_time.planet_num) -> w).pamd_f = this_time.force;
							((planet_arr + this_time.planet_num) -> w).pamd_t = this_time.timestamp;
						}
						else if(((planet_arr + this_time.planet_num) -> w).pamd_f < this_time.force){
							((planet_arr + this_time.planet_num) -> w).pamd_f = this_time.force;
							((planet_arr + this_time.planet_num) -> w).pamd_t = this_time.timestamp;
						}
					}
			}
        }
        else{
            cerr << "Neither SITH nor JEDI: input" << type << "is unknown \n";
            exit(1);
        }
        if(this_time.planet_num > num_planet){
            num_planet = this_time.planet_num;
        }
    }
    
    
    //if MEDIAN
	if(simu.m){ 
	   for (int i = 0; i < NUM_PLANETS; i++) {
    	    if(!(((planet_arr + i))->med).empty()){
        	    os << "Median troops lost on planet " << i << " at time "
        	   	   << current_time << " is "
     	 	       << ((planet_arr + i))->check_medium() << '\n';
      		}	
    	}
	}
    
    os << "---End of Day---\n" << "Battles: " << num_battles << '\n';
    //if GENERAL EVALUATION
    if(simu.g){
		os << "---General Evaluation---\n";
		for(int i = 0; i < NUM_GEN; i++){
	        os << "General " << i << " deployed " << gen_eval[i].jedi_depd << " Jedi troops and " <<
	        gen_eval[i].sith_depd << " Sith troops, and " <<
	        gen_eval[i].jedi_depd + gen_eval[i].sith_depd - gen_eval[i].num_dead << "/" <<
	        gen_eval[i].sith_depd + gen_eval[i].jedi_depd << " troops survived.\n";
	
   		}
	}

    //if MOVIE WATCHER
  	if(simu.w){
		os << "---Movie Watcher---\n";
    	for(int i = 0; i <= num_planet; i++){
        	os << "A movie watcher would enjoy an ambush on planet " << i
   		    << " with Sith at time " <<
	        ((planet_arr + i) -> w).am_t
	        << " and Jedi at time " <<
	        ((planet_arr + i) -> w).amd_t
	        << ".\n";
        
	        os << "A movie watcher would enjoy an attack on planet " << i
	        << " with Jedi at time " <<
	        ((planet_arr + i) -> w).ad_t
	        << " and Sith at time " <<
	        ((planet_arr + i) -> w).a_t
	        << ".\n";
    	}
	}
    delete [] planet_arr;
}

void simulation(ostringstream &os, const sim_type &simu){
    string junk;
    string MODE;
    int NUM_GEN = -1;
    int NUM_PLANETS = -1;
    read_MODES(junk, MODE, NUM_GEN, NUM_PLANETS);
    //if general evaluation
    vector<generals> gen_eval;
    gen_eval.resize(NUM_GEN);
    
    if(MODE == "DL"){
        //DL DATA
        string type;
        char trash;
        battalion this_time;
        os << "Deploying troops...\n";
        simulation_DL_helper(NUM_GEN, NUM_PLANETS, type, trash, this_time, os, gen_eval, simu);
    }
    else if(MODE == "PR"){
        cout << "implement with help \n";
    }
    else{
        cerr << "Wrong mode input \n";
        exit(1);
    }
}

