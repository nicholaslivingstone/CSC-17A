#include <iostream>
#include <iomanip>

using namespace std;



struct MovieData{
    string title; 
    string director;
    int year;
    int runningTime;
};

void prntInfo(MovieData &);
void setInfo(MovieData &);


int main(){
    int n; 
    cout << "This program reviews structures\n";
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes).\n";
    
    cin >> n; 
    MovieData movies[n];
    
        
    for(int i = 0; i < n; i++){
        cout << endl; 
        setInfo(movies[i]);
        prntInfo(movies[i]);
    }
        
    return 0;
}

void prntInfo(MovieData &movie){
    cout << "Title:     " << movie.title << endl;
    cout << "Director:  " << movie.director << endl; 
    cout << "Year:      " << movie.year << endl; 
    cout << "Length:    " << movie.runningTime << endl; 
}

void setInfo(MovieData &movie){
    cin.ignore();
    getline(cin, movie.title);
    getline(cin, movie.director);
    cin >> movie.year; 
    cin >> movie.runningTime;
}


