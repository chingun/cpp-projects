//
//  read_in.cpp
//  281P2
//
//  Created by Chingun Khasar on 10/17/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#include "read_in.h"

void read_MODES(string &junk, string &mode, int &num_gen, int &num_planets){
    getline(cin, junk);
    cin >> junk >> mode;
    cin >> junk >> num_gen;
    cin >> junk >> num_planets; //should I check the junks ?????
    if ((mode != "DL")&&(mode != "PR")){
        cerr << "Wrong mode input \"" << mode << "\" \n";
        exit(1);
    }
}

void read_DL_inputs(string &type, char &trash, int &gen_num,
                    int &planet_num, int &force_sens, int &num_sdrs, istream &is){
    is >> type >> trash >> gen_num >> trash >> planet_num >>
    trash >> force_sens >> trash >> num_sdrs;
    //cout << "\n     Gen:" << gen_num << "     \n";
}

/*
void read_PR_inputs(stringstream &is, const int &num_gen,
                    const int &num_planets){
    int SEED;
    int NUM_DEPLOYMENTS;
    int ARRIVAL_RATE;
    P2::PR_init(is, SEED, num_gen, num_planets, NUM_DEPLOYMENTS, ARRIVAL_RATE);
}*/



