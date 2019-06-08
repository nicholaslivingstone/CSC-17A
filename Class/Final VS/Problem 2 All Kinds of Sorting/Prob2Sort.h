#pragma once
using namespace std;

template<class T>
class Prob2Sort
{
private:
	int* index;                                 //Index that is utilized in the sort
public:
	Prob2Sort() { index = nullptr; };           //Constructor
	~Prob2Sort() { delete [] index; };          //Destructor
	T* sortArray(T*, int, bool);				//Sorts a single column array
	T* sortArray(T*, int, int, int, bool);		//Sorts a 2 dimensional array represented as a 1 dim array
};

template<class T>
inline T* Prob2Sort<T>::sortArray(T* _arr, int size, bool _ASC){
	T* arr = _arr;
	int start, minIndex;
	T min;

	for(start = 0; start < (size - 1); start++){
		minIndex = start;
		min = arr[start];
		for (int i = start + 1; i < size; i++) {
			if ((arr[i] < min && _ASC) || (arr[i] > min && !_ASC)) {
				min = arr[i];
				minIndex = i;
			}
		}
		arr[minIndex] = arr[start];
		arr[start] = min;
	}

	if (_ASC)
		return arr;
}

template<class T>
inline T* Prob2Sort<T>::sortArray(T* _arr, int ROWMAX, int COLMAX, int _col, bool _ASC)
{
	T* arr = _arr;
	bool swp;
	T tmp;

	do {
		swp = false;
		for (int i = 0; i < ROWMAX - 1; i++) {
			if (((arr[i * 16 + _col - 1] > arr[(i + 1) * 16 + _col - 1]) && !_ASC) || ((arr[i * 16 + _col - 1] < arr[(i + 1) * 16 + _col - 1]) && _ASC)) {
				for (int j = 0; j < COLMAX; j++) {
					tmp = arr[i * 16 + j];
					arr[i * 16 + j] = arr[(i + 1) * 16 + j];
					arr[(i + 1) * 16 + j] = tmp;
						swp = true; 
				}
			}
		}
	}while(swp);


	return arr;
}
