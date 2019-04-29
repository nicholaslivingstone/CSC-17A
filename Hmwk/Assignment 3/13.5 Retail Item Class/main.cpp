/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 29, 2019, 2:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class RetailItem{
private:
    string description;
    int unitsOnHand;
    double price; 
public:
    RetailItem(string desc, int units, double prc){
        description = desc; 
        unitsOnHand = units; 
        price = prc; 
    }
    
    void setDescription(string desc){
        description = desc; 
    }
    
    void setUnits(int units){
        unitsOnHand = units; 
    }
    
    void setPrice(double prc){
        price = prc;
    }
    
    string getDecsription(){
        return description;
    }
    
    int getUnits(){
        return unitsOnHand;
    }
    
    double getPrice(){
        return price;
    }
    
};

void showItemInfo(RetailItem, int);

int main(int argc, char** argv) {
    
    RetailItem jacket("Jacket", 12, 59.95);
    RetailItem jeans("Designer Jeans", 40, 34.95);
    RetailItem shirt("Shirt", 20, 24.95);
    
    showItemInfo(jacket, 1);
    showItemInfo(jeans, 2);
    showItemInfo(shirt, 3);
    
}

void showItemInfo(RetailItem item, int n){
    cout << left << "Item #" <<  setw(5) << n << setw(25) << item.getDecsription() << setw (15) << item.getUnits() << item.getPrice() << endl;
}

