//
//  main.cpp
//  Proj4
//
//  Created by Chingun Khasar on 12/3/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>
#include "functions.h"
using namespace std;

struct mode_select{
    bool MST;
    bool OPTTSP;
    bool FASTTSP;
};

int main(int argc,  char *argv[]) {
    // insert code here...
    
    mode_select mode;
    
    mode.MST = false;
    mode.OPTTSP = false;
    mode.FASTTSP = false;
    
    if(!argc){//DELETE THIS AFTER FINISHED:
        cerr << "False input read dumbass \n";
        exit(0);
    }
    if (!(strcmp(*(argv + 1), "-m")) || !(strcmp(*(argv + 1), "--mode"))){
        if(!strcmp(*(argv + 2), "MST")){
            mode.MST = true;
        }
        else if(!strcmp(*(argv + 2), "OPTTSP")){
            mode.OPTTSP = true;
        }
        else if(!strcmp(*(argv + 2), "FASTTSP")){
            mode.FASTTSP = true;
        }
        else{
            cerr << "Wrong mode input dumbass\n";
            exit(0);
        }
    }
    else if(!(strcmp(*(argv + 1), "-h")) || !(strcmp(*(argv + 1), "--help"))){
        cout << "I wont help you :D \n";
        exit(0);
    }
    else{
        cerr << "False command dumbass \n";
        exit(0);
    }
//    cout << mode.MST << " " << mode.OPTTSP << " " << mode.FASTTSP << '\n';
    
    
    
    da_zoo zoo;
    cin >> zoo.size;
    cout << setprecision(2); // Always show 2 decimal places
    cout << fixed; // Disable scientific notation for large numbers
    
    pair<int,int> i;
    i.first = -1;
    i.second = -1;
    string a;
    zoo.cages.reserve(zoo.size);

    
//    cout << "Reading input... \n";
    for(unsigned int j = 0; j < zoo.size; j++){
        cin >> i.first >> i.second;
        zoo.cages.push_back(i);
    }
//    for(unsigned int j = 0; j < zoo.size; j++){
//        cout << j <<" - "<< zoo.cages[j].first << ',' << zoo.cages[j].second << '\n';
//    }

//    cout << "dist between first and second input is = "
//         << distance(zoo.cages[0],zoo.cages[zoo.size - 1]) << '\n';
    if(mode.MST){
        zoo.MST();
    }
    else{
        exit(0);
    }
}

