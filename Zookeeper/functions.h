//
//  functions.h
//  Proj4
//
//  Created by Chingun Khasar on 12/3/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//
#ifndef functions_h
#define functions_h

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;


double distance(const pair<int,int> &a, const pair<int,int> &b){
    return sqrt(pow((a.first - b.first),2) + pow((a.second - b.second),2));
}
bool reachable(const pair<int,int> &a, const pair<int,int> &b){
    if((a.first < 0)&&(a.second < 0)){
        /*if((b.first >= 0)&&(b.second >= 0)){
            if((b.first > 0)||(b.second > 0)){
                return false;
            }
        }*/
        if ((b.first == 0 && b.second <= 0) || (b.second == 0 && b.first <= 0)) {
            return true;
        }
        else if (b.first < 0 && b.second < 0) {
            return true;
        } else {
            return false;
        }
    }
    else if (((b.first < 0)&&(b.second < 0))){
        if ((a.first == 0 && a.second <= 0) || (a.second == 0 && a.first <= 0)) {
            return true;
        }
        else if (a.first < 0 && a.second < 0) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}



class da_zoo{
public:
    // prims algorithm struct
    class V{
    public:
        bool Kv; //has v been visited
        double Dv; //minimal edge weight to v
        int Pv; //parent of v
        //pair<int,int> index;
    };
    struct lessThan{
        bool operator()(const V& lhs, const V& rhs) const{
            return lhs.Dv > rhs.Dv;
        }
    };
    
    unsigned int size;
    vector<pair<int,int> > cages;
    //Whole part A of project
    void MST();
//    bool solvable(){
//        
//    }
};

void da_zoo::MST(){
    V value;
    
    value.Dv = 0;
    value.Kv = false;
    value.Pv = -1;

    vector<V> table;
    
    table.reserve(size);  //reserve the memory
    table.push_back(value); //pushback first vector and the distance to it is 0
    
    value.Dv = numeric_limits<double>::infinity(); //change the distance to everything else to be infinity
    for (unsigned int i = 1; i < size; ++i){  //push them into the table
        table.push_back(value);
    }
    
    int pivot = -1;
    vector<int> edges;
    for(unsigned int i = 0; i < size; ++i){
        for (unsigned int j = 0; j < size; ++j){ //finds the least distance and sets the value
            if((pivot < 0)||table[(uint)pivot].Kv){
                if(!table[j].Kv)
                    pivot = (int)j;
            }
            else if((!table[j].Kv)&&(table[j].Dv < table[(uint)pivot].Dv)){
                pivot = (int)j;
            }
        }
        if(pivot < 0)
            exit(0);
        edges.push_back(pivot);
        table[(uint)pivot].Kv = true;
        // cout << " pivot is == " << pivot << '\n' << '\n';
        
        for (unsigned int j = 0; j < size; ++j){
            if((!table[j].Kv)&&(reachable(cages[j], cages[(uint)pivot]))){ //possible that reachable is wrong
                if(distance(cages[j], cages[(uint)pivot]) < table[j].Dv){
                    table[j].Dv = distance(cages[j], cages[(uint)pivot]);
                    table[j].Pv = pivot;
                }
            }
        }
    }
    //cout << "Wish it works... :P\n";
    double total_weight = 0;
    for(unsigned int i = 1; i < size; ++i){
        total_weight += table[i].Dv;
    }
    cout << total_weight << '\n';
    for(unsigned int i = 1; i < size; ++i){
        if(table[(uint)edges[i]].Pv < edges[i]){
            cout << table[(uint)edges[i]].Pv << ' ' << edges[i] << '\n';
        }
        else{
            cout << edges[i] << ' ' << table[(uint)edges[i]].Pv << '\n';
        }
        //cout << " - dist is "<< (table[edges[i]]).Dv <<'\n';
    }
}
#endif /* functions_h */


//5 6 1 2 3 -5 -4 -1 6 0 -1

