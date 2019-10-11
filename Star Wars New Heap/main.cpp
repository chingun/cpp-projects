//
//  main.cpp
//  281P2
//
//  Created by Chingun Khasar on 10/6/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.

    
#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include "P2.h"
#include <sstream>
#include "read_in.h"
#include "simulation.h"
#include "Eecs281PQ.h"
#include "BinaryPQ.h"
using namespace std;

static struct option longopts[] = {
	{"verbose", no_argument,       nullptr, 'v'},
    {"median", no_argument,        nullptr, 'm'},
    {"general", no_argument,       nullptr, 'g'},
    {"watcher", no_argument,       nullptr, 'w'},
    {"queue", required_argument,   nullptr, 'q'},
    {nullptr, 0, nullptr, 0}
};
        

int main(int argc, char * argv[]){
    ios_base::sync_with_stdio(false);
    int c;
	int option_index = 0;
    sim_type simu;
    while(true){
		if((c = getopt_long(argc, argv, "vmgwq:", longopts, &option_index)) == -1){
        		break;
		}
		
		switch(c){
            case 'v':
                simu.v = true;
				break;
            case 'm':
                simu.m = true;
				break;
            case 'g':
                simu.g = true;
				break;
            case 'w':
                simu.w = true;
				break;
            case 'q':
                if(string(optarg) == "SORTED"){
                    simu.sort = true;
					simu.bin = false;
					simu.pair = false;
					simu.jar = false;
                }
                else if(string(optarg) == "BINARY"){
                    simu.bin = true;
                    simu.sort = false;
					simu.pair = false;
					simu.jar = false;
                }
                else if(string(optarg) == "PAIRING"){
                    simu.pair = true;
                    simu.bin = false;
                    simu.sort = false;
					simu.jar = false;
                }
				else{
					simu.jar = true;
                    simu.pair = false;
                    simu.bin = false;
                    simu.sort = false;
				}
                break;
            default:
                cout << "Output mode manual Map" << endl;
        }
    }
    
    std::ios_base::sync_with_stdio(false);
    ostringstream os;
    simulation(os, simu);
    cout << os.str();
}
