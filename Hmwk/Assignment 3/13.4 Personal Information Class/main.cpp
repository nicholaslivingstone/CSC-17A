/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 28, 2019, 9:55 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class personalInfo{
private:
    string name,
            address;
    int age;
    long phone;

public:
    void setName(string n){
        name = n; 
    }
    void setAdress(string addr){
        address = addr;
    }
    void setAge(int A){
        age = A;
    }
    void setPhone(long P){
        phone = P;
    }
    string getName(){
        return name; 
    }
    string getAddress(){
        return address;
    }
    int getAge(){
        return age;
    }
    long getPhone(){
        return phone;
    }
    
};

void outputInfo(personalInfo);

int main(int argc, char** argv) {
    
    personalInfo me,
            friends,
            family;
    me.setName("Nick");
    me.setAdress("123 Road Ave");
    me.setAge(20);
    me.setPhone(9993332222);
            
    friends.setName("John Smith");
    friends.setAdress("404 Street Dr");
    friends.setAge(25);
    friends.setPhone(3439920038);
    
    family.setName("Relative's Name");
    family.setAdress("800 Avenue CT");
    family.setAge(60);
    family.setPhone(2229041233);
    
    
    outputInfo(me);
    cout << endl; 
    outputInfo(friends);
    cout << endl; 
    outputInfo(family);
    return 0;
}

void outputInfo(personalInfo person){
    cout << "Name: " << person.getName() << endl;
    cout << "Address: " << person.getAddress() << endl;
    cout << "Age: " << person.getAge() << endl;
    cout << "Phone Number: " << person.getPhone() << endl; 
            
}

