/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 30, 2019, 12:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << left << setw(13) << "Number"  << setw(13) << "Binary"  << setw(13) << "Octal" << setw(13) << "Hex" << setw(13) << "Floating" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << setw(13) << 2.875 << setw(13) << 10.111 << setw(13) << 2.7 << setw(13) << "2.E" << setw(13) << 40000007 << endl;
    cout << setw(13) << 0.1796875 << setw(13) << 0.0010111 << setw(13) << 0.134 << setw(13) << "0.2E" << setw(13) << "00000017" << endl;
    cout << setw(13) << "-2.875" << setw(13) << "-10.111" << setw(13) << "-2.7" << setw(13) << "-2.E" << setw(13) << "C0000007" << endl;
    cout << setw(13) << "-0.1796875" << setw(13) << "-0.0010111" << setw(13) << "-0.134" << setw(13) << "-0.2E" << setw(13) << "80000017" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << setw(13) << "Floating"  << setw(35) << "Binary" << setw(13) << "Number" << endl;
    cout << setw(13) << "59999901"  << setw(35) << "01011001100110011001100100000001" << setw(13) << "5.404237626343424e15" << endl;
    cout << setw(13) << "59999902"  << setw(35) << "01011001100110011001100100000010" << setw(13) << "5.404238163214336e15" << endl;
    cout << setw(13) << "A66667FE"  << setw(35) << "10100110011001100110011111111110" << setw(13) << "-7.99382155894444012406152566541e-16" << endl;

    return 0;
}

