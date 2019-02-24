/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 23, 2019, 1:26 PM
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int NUM_NAMES = 20;
    string name, lastn, firstn;
    
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" };
    
    vector<string> vnames(names, names + sizeof names / sizeof names[0]);
    sort(vnames.begin(), vnames.end());
    
    cout << "What name are you searching for? (last, first): ";
    cin >> lastn;
    cin >> firstn;
    name =  lastn + " " + firstn;
    
    int first = 0,
            last = 19,
            pos = -1,
            mid;
    bool found = false; 
    
    
    while(!found && first <= last){
        mid = (first + last) / 2; 
        if (vnames[mid] == name){
            found = true;
            pos = mid;
        }
        else if (vnames[mid] > name){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
    
    if (found)
        cout << "Found at: " << pos; 
    else
        cout << "Not found";
    
    return 0;
}

