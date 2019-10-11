//
//  main.cpp
//  Project #3
//
//  Created by Chingun Khasar on 11/5/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//
/*
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "Data_classes.h"
using namespace std;

int main(int argc, char * argv[]) {
    /*
    if (getenv("INPUT")){
        freopen(getenv("INPUT"), "r", stdin);
        //freopen(getenv("OUTPUT"), "w", stdout);
    } // if
    */
	ios_base::sync_with_stdio(false);
    
	string input_file;
  	fstream logger;
    
    if(!argc){//DELETE THIS AFTER FINISHED:
        cerr << "input file name not read \n";
        exit(0);
    }
    if(!(strcmp(*(argv + 1), "-h")) || !(strcmp(*(argv + 1), "--help"))){    
    	cout << "Commands you can use to read log file: search: t,m,c,k list_edit: a,r,d,b,e,s,l output: g,p,q,# \n";
        exit(0);
    }
    else{
    	input_file = *(argv + 1);
    }
    logger.open(input_file);
  	if(!logger.is_open()){
        cerr << "File not found \n";
        exit(0);
    }
    log_files master_log;
    master_log.add_file_from_input(logger);
    //master_log.print_sorted();
    master_log.main_function();
    logger.close();

}

