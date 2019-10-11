//
//  Data_classes.h
//  Project #3
//
//  Created by Chingun Khasar on 11/6/16.
//  Copyright © 2016 Chingun Khasar. All rights reserved.
//

#ifndef Data_classes_h
#define Data_classes_h
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <map>
#include <fstream>
#include <string.h>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <locale>
#include <queue>
//using namespace std;

class log_files{
public:
    struct log{  //Why is there an error when you define it outside of the class?
        unsigned long long timestamp;
        std::string category;
        std::string message;
        std::string t;
        unsigned int entry_ID;
    };
    
    // struct excerpt_log{  //Why is there an error when you define it outside of the class?
    //     //unsigned int entry_ID;
    //     unsigned int list_number;
    // };
    // Create
    std::vector<log> Master_log;
    //unordered_map<long long,vector<int>> t_search;
    std::unordered_map<std::string, std::vector<int>> c_search;
    std::unordered_map<std::string, std::vector<int>> k_search;
    std::deque<unsigned int> excerpt_list;
    
    struct log_compare{
        bool operator()(log& a, log& b) const{ //const after means function doesnt modify a and b
            //return a.timestamp < b.timestamp;  //function doesnt work WHY?
            if(a.timestamp < b.timestamp){
                return true;
            }
            else if(a.timestamp > b.timestamp){
                return false;
            }
            else if(strcasecmp((a.category).c_str(), (b.category).c_str()) < 0){
                return true;
            }
            else if(strcasecmp((a.category).c_str(), (b.category).c_str()) > 0){
                return false;
            }
            else{
                return a.entry_ID < b.entry_ID;
            }
        }   
    };
    
    struct excerpt_compare{
        bool operator()(int a, int b) const{
            return a < b;
        }


        /*
        bool operator()(int a, int b) const{ //const after means function doesnt modify a and b
            //return a.timestamp < b.timestamp;  //function doesnt work WHY?
            if((Master_log[a]).timestamp < (Master_log[b]).timestamp){
                return true;
            }
            else if((Master_log[a]).timestamp > (Master_log[b]).timestamp){
                return false;
            }
            else if(strcasecmp(((Master_log[a]).category).c_str(), ((Master_log[b]).category).c_str()) < 0){
                return true;
            }
            else if(strcasecmp(((Master_log[a]).category).c_str(), ((Master_log[b]).category).c_str()) > 0){
                return false;
            }
            else{
                return (Master_log[a]).entry_ID < (Master_log[b]).entry_ID;
            }
        }*/   
    };
    
    
    struct log_compare_U{
        bool operator()(unsigned long long t, const log& b) const{ //const after means function doesnt modify a and b
            return t < b.timestamp;  //function doesnt work WHY?
        }   
    };
    struct log_compare_L{
        bool operator()(const log& a, unsigned long long t) const{ //const after means function doesnt modify a and b
            return a.timestamp < t;  //function doesnt work WHY?
        }   
    };
    // operator overload
    //call it first in main to input file from file
    void add_file_from_input(std::fstream& inputStream);
    //The main function to run the simulation
    void main_function();
    //Searches the master log depending on what the timestamp is
    void timestamp_search(std::vector<int>& bus);
    void matching_search(std::vector<int>& bus);
    //Inputs to the category unordered map
    void key_search(std::vector<int>& bus);
    //return a string with front and back whitespaces deleted
    std::string cleanup_category(std::string a);
	//searches the category for the given keywords.
	void category_search(std::vector<int>& bus);
    //delete log entries
    void delete_log_entry();
    //save keys in
    void save_keys(std::string& a, const int& i);
    void append_entryID(std::vector<int>& bus);
    void append_search_results(std::vector<int>& bus);
    //sort the excerpt file
    void sort_excerpt();



    void print_sorted(){
        std::cout << "printing..." << '\n';
        for (unsigned int i = 0; i < Master_log.size(); i++){
           std::cout << (Master_log[i]).t << '\n';
        }
        std::cout << "print ended" << '\n';
    }

    void print_timestamp(const unsigned long long& a){
        //std::cout << a/100000000 << ':' << a/1000000 << ':' 
        //          << a/10000 << ':' << a/100 << ':' << a;
        std::cout << a;
    }
    
    void print_excerpt(){
        //std::cout << "printing..." << '\n';
        for (unsigned int i = 0; i < excerpt_list.size(); i++){
            std::cout << i << '|' << (Master_log[(excerpt_list[i])]).entry_ID 
                    << '|' << (Master_log[(excerpt_list[i])]).t << '|'
                    << (Master_log[(excerpt_list[i])]).category << '|'
                    << (Master_log[(excerpt_list[i])]).message<< '\n';
        }
        //std::cout << "print ended" << '\n';
    }

    void print_recent(const std::vector<int>& bus){
        for (unsigned int i = 0; i < bus.size(); i++){
                std::cout << (Master_log[(uint)bus[i]]).entry_ID << '|'
                          << (Master_log[(uint)bus[i]]).t << '|' 
                          << (Master_log[(uint)bus[i]]).category << '|'
                          << (Master_log[(uint)bus[i]]).message << '\n';
        }
    }

    void move_to_end(){
        unsigned int addr;
        std::cin >> addr;
        if(addr > Master_log.size()){
            std::cerr << "Move index wrooong \n";
            exit(0);
        }
        unsigned int dummy = excerpt_list[addr];
        excerpt_list.erase(excerpt_list.begin() + addr);
        excerpt_list.push_back(dummy);
        std::cout << "Moved excerpt list entry " << addr << '\n' ;
    }

    void move_to_beg(){
        unsigned int addr;
        std::cin >> addr;
        if(addr > Master_log.size()){
            std::cerr << "Move index wrooong \n";
            exit(0);
        }
        unsigned int dummy = excerpt_list[addr];
        excerpt_list.erase(excerpt_list.begin() + addr);
        excerpt_list.push_front(dummy);
        std::cout << "Moved excerpt list entry " << addr << '\n' ;
    }
};
//check timestamps
void check_timestamp(const std::string& a);
//convert timestamp string to long long value
unsigned long long strin_to_long(std::string a);
//receive a string and delete all white spaces
//i is the ith string in alrl of variables

//HOW TO COMPARE STRINGS
// , int i , unordered_map<string, int> k_search


/*
 bool operator<(const log& a, const log& b){
 return a.timestamp < b.timestamp;
 }
*/

#endif /* Data_classes_h */
