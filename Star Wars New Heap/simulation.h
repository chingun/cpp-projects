//
//  simulation.hpp
//  281P2
//
//  Created by Chingun Khasar on 10/17/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#ifndef simulation_hpp
#define simulation_hpp
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include "P2.h"
#include "JarJarPQ.h"
#include "read_in.h"
#include <stdio.h>
using namespace std;

struct sim_type{
    bool v;
    bool m;
    bool g;
    bool w;
    bool bin;
    bool jar;
    bool sort;
    bool pair;
    sim_type(){
        v = false;
        m = false;
        g = false;
        w = false;
        bin = false;
        jar = true;
        sort = false;
        pair = false;
    }
};

//Simulator
class battalion{
public:
    int timestamp;
    int num_sdrs;
    int gen_num;
    int planet_num;
    int force;
    
    battalion(){ //Initialize
        timestamp = -1;
        num_sdrs = -1;
        gen_num = -1;
        planet_num = -1;
        force = -1;
    }
    battalion(const battalion &two){
        timestamp = two.timestamp;
        num_sdrs = two.num_sdrs;
        gen_num = two.gen_num;
        planet_num = two.planet_num;
        force = two.force;
    }
    
};
/*
class Medians{
public:
    int num_planets = 0;
    int* per_planets = new int[num_planets];
    int* count_planets = new int[num_planets];
    
    ~Medians(){
        delete [] per_planets;
        delete [] count_planets;
    }
};
*/
//General Evaluation
struct generals{
    int sith_depd;
    int jedi_depd;
    int num_dead;
    generals(){
        sith_depd = 0;
        jedi_depd = 0;
        num_dead = 0;
    
    }
};


//Watcher
class MovieWatcher{
public:
    int a_f;
    int a_t;
    int ad_f;
    int ad_t;
    int pad_f;
    int pad_t;
    
    int am_f;
    int am_t;
    int amd_f;
    int amd_t;
    int pamd_f;
    int pamd_t;
    MovieWatcher(){
        a_f = -1;
        a_t = -1;
        ad_f = -1;
        ad_t = -1;
        pad_f = -1;
        pad_t = -1;
        
        am_f = -1;
        am_t = -1;
        amd_f = -1;
        amd_t = -1;
        pamd_f = -1;
        pamd_t = -1;

    }
};


//Comparators, possibly false
struct jediComparator{ // Check Comparators
    bool operator()(const battalion &jedi1, const battalion &jedi2){
        if(jedi1.force > jedi2.force){
            return true;
        }
        else if(jedi1.force < jedi2.force){
            return false;
        }
        else{
            if(jedi1.timestamp < jedi2.timestamp){
                return false;
            }
            else{
                return true;
            }
        }
    }
};
struct sithComparator{ //Check comparators
    bool operator()(const battalion &sith1, const battalion &sith2){
        if(sith1.force < sith2.force){
            return true;
        }
        else if(sith1.force > sith2.force){
            return false;
        }
        else{
            if(sith1.timestamp < sith2.timestamp){
                return false;
            }
            else{
                return true;
            }
        }
    }
};

class planet{
private:
    Eecs281PQ<battalion, jediComparator> jedis; //weakest first
    Eecs281PQ<battalion, sithComparator> siths; //strongest first

    bool ambush(battalion &jedi){ //insert Moviewatcher
        if(jedi.num_sdrs > (siths.top()).num_sdrs){
            jedi.num_sdrs -= (siths.top()).num_sdrs;
            siths.pop();
            //sith lost
            return true;
        }
        else if (jedi.num_sdrs < (siths.top()).num_sdrs){
            battalion sith_rep(siths.top());
            sith_rep.num_sdrs = (siths.top()).num_sdrs - jedi.num_sdrs;
            siths.pop();
            siths.push(sith_rep);
            jedi.num_sdrs = 0;
            //jedi lost
            return false;
        }
        else{
            siths.pop();
            jedi.num_sdrs = 0;
            //both lost
            return false;
        }
    }
    bool attack(battalion &sith){ //insert Moviewatcher
        if((jedis.top()).num_sdrs < sith.num_sdrs){
            sith.num_sdrs -= (jedis.top()).num_sdrs;
            jedis.pop();
            //jedi lost
            return true;
        }
        else if((jedis.top()).num_sdrs > sith.num_sdrs){
            battalion jedi_rep(jedis.top());
            jedi_rep.num_sdrs = (jedis.top()).num_sdrs - sith.num_sdrs;
            jedis.pop();
            jedis.push(jedi_rep);
            sith.num_sdrs = 0;
            //sith lost
            return false;
        }
        else{
            jedis.pop();
            sith.num_sdrs = 0;
            //both lost
            return false;
        }
    }
    
public:
    vector<int> med;
    int check_medium(){
        size_t size = med.size();
        sort(med.begin(), med.end());
        
        if (size  % 2 == 0){
            return (med[size / 2 - 1] + med[size / 2]) / 2;
        }
        else{
            return med[size / 2];
        }
    }
    
    MovieWatcher w;
    void jedi_input(battalion &jedi, ostringstream &os, int &num_battles,
                    vector<generals> &gen_eval, const sim_type &simu);
    void sith_input(battalion &sith, ostringstream &os, int &num_battles,
                    vector<generals> &gen_eval, const sim_type &simu);
    int return_battle_count();
    /*
    planet(bool mov_watcher){
        vector<int> vals;
        vals.resize(10);
        //attacked_jedi, attacked jedi time
        //possible_attacker, possible attacker time
        //attacker_sith, attacker sith time
        //possible_attacker, possible attacker time
        //ambusher_sith, ambusher sith time
        //ambushed_sith, ambushed sith time
        vals = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    }*/
    void print_median();
    planet(sim_type &simu){
	if(simu.bin){
	    siths =  new BinaryPQ<battalion, jediComparator>;
	    jedis = new BinaryPQ<battalion, jediComparator>;
	}
	else if(simu.jar){
	    siths =  new JarJarPQ<battalion, jediComparator>;
	    jedis = new JarJarPQ<battalion, jediComparator>;
	}
	else if(simu.sort){
	    siths =  new SortedPQ<battalion, jediComparator>;
	    jedis = new SortedPQ<battalion, jediComparator>;
	}
	else if(simu.pair){
	    siths =  new BinaryPQ<battalion, jediComparator>;
	    jedis = new BinaryPQ<battalion, jediComparator>;
	}
    }
};


//if DL mode is chosen at input this simulation method will be run
void simulation_DL_helper(const int &NUM_GEN, const int &NUM_PLANETS,
                          string &type,char &trash, battalion &this_time,
                          ostringstream &os, vector<generals> &gen_eval,
							sim_type &simu);

//if PR mode is chosen at input this simulation method will be run
void simulation_PR_helper();

//The main simulation
void simulation(ostringstream &os, const sim_type &simu);

//Median?
void calc_median(int &median, int &count);
//G

//Q? what to do

#endif /* simulation_hpp */

