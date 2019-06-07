// Cicaida.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std; 

void StartMenu(); 

int main()
{
	int key; 
	StartMenu(); 



}

void dispMenu(int, int []);

void StartMenu() {
	string name;
	cout << "Welcome player\n Enter your name to begin:";
	cin >> name; 
	cout << "Thank You " << name;
	cout << "Welcome to The Dungeon(32BIT)\n Try to save the princess\n";
	int code[3] = { 0, 1, 2 };
	dispMenu(3, code);

}

void dispMenu(int size, int code[]) {
	string mainItems[3] = {"Start", "Exit", "difficulty"};
	
	for (int i = 0; i < size; i++) {
		cout << mainItems[code[i]] << endl; 
	}
}