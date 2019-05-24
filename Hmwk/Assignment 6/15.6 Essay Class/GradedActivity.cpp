/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradedActivity.cpp
 * Author: Nicholas
 * 
 * Created on May 23, 2019, 10:28 PM
 */

#include "GradedActivity.h"

void GradedActivity::determineGrade()
{
	if (score > 89)
		letter = 'A';
	else if (score > 79)
		letter = 'B';
	else if (score > 69)
		letter = 'C';
	else if (score > 59)
		letter = 'D';
	else
		letter = 'F';
}