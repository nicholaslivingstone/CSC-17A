/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 29, 2019, 3:07 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Circle{
private:
    double radius,
            pi = 3.14159;
public:
    Circle(){
        radius = 0.0;
    }
    
    Circle(double r){
        radius = r;
    }
    
    void setRadius(double r){
        radius = r;
    }
    
    double getRadius(){
        return radius; 
    }
    
    double getArea(){
        return pi * radius * radius;
    }
    
    double getDiameter(){
        return radius * 2;
    }
    
    double getCircumference(){
        return 2 * pi * radius;
    }
};

int main(int argc, char** argv) {
    double r;
    cout << "Enter radius of the circle: ";
    cin >> r;
    
    Circle circ(r);
    
    cout << "Area:          " << circ.getArea() << endl; 
    cout << "Diameter:      " << circ.getDiameter() << endl; 
    cout << "Circumference: " << circ.getCircumference() << endl;
    
    return 0;
}

