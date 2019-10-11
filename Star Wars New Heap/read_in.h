//
//  read_in.h
//  281P2
//
//  Created by Chingun Khasar on 10/17/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#ifndef read_in_h
#define read_in_h

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include "P2.h"
#include "JarJarPQ.h"
using namespace std;


// REQUIRES: inputs be valid, this time already initialized
// MODIFIES: the inputs
// EFFECTS: saves the modes
void read_MODES(string &junk, string &mode, int &num_gen, int &num_planets);



// REQUIRES: inputs be valid, this time already initialized
// MODIFIES: priority queue
// EFFECTS: saves the DL input
void read_DL_inputs(string &type, char &trash, int &gen_num,
                    int &planet_num, int &force_sens, int &num_sdrs, istream &is);

// REQUIRES: inputs be valid, this time already initialized
// MODIFIES: priority queue
// EFFECTS: saves the PR input randomly
void read_PR_inputs(ostringstream &is, const int &num_gen,
                    const int &num_planets);



#endif /* read_in_h */

