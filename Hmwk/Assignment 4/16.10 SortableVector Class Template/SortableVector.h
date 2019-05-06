// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortableVector.
 * Author: Nicholas
 *
 * Created on May 5, 2019, 10:31 PM
 */

#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H
#include "SimpleVector.h"

template<class T>
class SortableVector : public SimpleVector<T>
{
public:
	void sort();
	SortableVector(int size) : SimpleVector<T>(size)
		{ }
	
};

template<class T>
void SortableVector<T>::sort()
{
	int i, j, minIndex, tmp;

	for (i = 0; i < SimpleVector<T>::size() - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < SimpleVector<T>::size(); j++)
			if (SimpleVector<T>::getElementAt(j) < SimpleVector<T>::getElementAt(minIndex))
				minIndex = j;
		if (minIndex != i) {
			tmp = SimpleVector<T>::getElementAt(i);
			SimpleVector<T>::setElement(i, SimpleVector<T>::getElementAt(minIndex));
			SimpleVector<T>::setElement(minIndex, tmp);
		}
	}
}

#endif
