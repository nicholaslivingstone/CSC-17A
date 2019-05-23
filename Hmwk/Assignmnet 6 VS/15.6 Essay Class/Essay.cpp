#include "Essay.h"

Essay::Essay(int _grammar, int _spelling, int _length, int _content)
{
	this->setScore(_grammar + _spelling + _length + _content);
}
