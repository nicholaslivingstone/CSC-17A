/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on April 5, 2019, 8:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream file("data.txt");
    ofstream fileEncrypt("data_encrypt.txt");
    char ch, current, last; 
    string str;
    string strEncrypt; 
    int n; 
     
    file.get(ch);
    
    while(file){
        bitset<8> bin(ch);
        str = bin.to_string();
        
        for(int i = 0; i < 8; i++){
            strEncrypt[i] = (str[i] == '0' ? '1' : '0');
        }
        
        last = strEncrypt[0];
        n = 1; 
        for(int i = 1; i < 8; i++){
            current = strEncrypt[i];
            cout << current; 
            if(current == last){
                n++;
            }
            else{
                if (last = '0')
                    fileEncrypt.put('-');
                fileEncrypt.put(n + '0');
                n = 1; 
            }
            last = current;
        }
        
        
        file.get(ch);
    }
    
    file.close(); 
    fileEncrypt.close(); 

    return 0;
}

