/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradedActivity.h
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:28 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
protected:
	char letter;            // To hold the letter grade
	double score;           // To hold the numeric score
	void determineGrade();  // Determines the letter grade
public:
	// Default constructor
	GradedActivity()
	{
		letter = ' '; score = 0.0;
	}

	// Mutator function
	void setScore(double s)
	{
		score = s;
		determineGrade();
	}

	// Accessor functions
	double getScore() const
	{
		return score;
	}

	char getLetterGrade() const
	{
		return letter;
	}
};


#endif /* GRADEDACTIVITY_H */
