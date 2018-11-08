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
	if(top != 1)
	{
		top--;
		strStack[top] = 0;

	}

	if(top == 1)
	{
		strStack[1] = '0';
	}

}

bool StringStack::isEmpty()
{

	return (top == 1);
}

bool StringStack::hasDot()
{
	for(int i=0;i<50;i++)
	{
		if(strStack[i] == '.')
		{
			return true;
		}
	}

	return false;
}

const int StringStack::strLength()
{
	return top;
}

const string StringStack::getString()
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


void StringStack::clear()
{
	strStack[0] = ' ';
	strStack[1] = '0';
	for(int i=2;i<50;i++)
	{
		strStack[i] = 0;
	}
	top = 1;
}

void StringStack::setString(string str)
{
	clear();

	for(int i=0;i<str.length();i++)
	{
		push(str.data()[i]);
	}

}


