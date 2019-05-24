/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.cpp
 * Author: Nicholas
 * 
 * Created on May 23, 2019, 10:27 PM
 */

#include "Essay.h"

Essay::Essay(int _grammar, int _spelling, int _length, int _content)
{
	this->setScore(_grammar + _spelling + _length + _content);
}
