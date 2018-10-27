/*
 * StringStack.cpp
 *
 *  Created on: 2018. 10. 27.
 *      Author: jh
 */

#include "StringStack.hpp"

// StringStack::

void StringStack::push(char input)
{
	strStack[top] = input;
	top++;
}

void StringStack::remove()
{
	if(top != 0)
	{
		strStack[top] = NULL;
		top--;
	}else{
		strStack[0] = '0';
	}


}

string StringStack::getString()
{
	return string(strStack);
}


void StringStack::addSigned()
{
	if(strStack[0] == 32)
	{
		strStack[0] = 45;
	}else{
		strStack[0] = 32;
	}
}

