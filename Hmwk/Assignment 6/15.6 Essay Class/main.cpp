/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:27 PM
 */

#include <cstdlib>
#include "Essay.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int gram, spell, len, cont; 
    cout << "Grammar:";
    cin >> gram; 
    cout << "Spelling:";
    cin >> spell; 
    cout << "Length:"; 
    cin >> len; 
    cout << "Content:";
    cin >> cont; 
    Essay essayDemo(gram, spell, len, cont);
    cout << "Letter Grade: " << essayDemo.getLetterGrade(); 
    return 0;
}

