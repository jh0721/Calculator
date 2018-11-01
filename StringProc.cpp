/*
 * StringProc.cpp
 *
 *  Created on: 2018. 10. 20.
 *      Author: jh
 */

#include "StringProc.hpp"

// StringProc::

#include <iostream>

using namespace std;

int exponentiation_base10(int);

int StringProc::checkDouble(const char* str,int length)
{
	for(int i=0;i<length;i++)
	{
		if(str[i] == 46) return i;
	}

	return 0;
}


long double StringProc::strTolongdouble(string str)
{
	long double result;
	const char* data = str.data();
	int strLength = str.length()-1;
	int dotPosition = checkDouble(data,strLength);

	int integer = 0;
	double decimal = 0;

	for(int i=0;i<strLength;i++)
	{
		integer = integer + (data[i+1]-48)*exponentiation_base10(strLength-i-1);
	}

	if(dotPosition)
	{
		integer = 0;
		for(int i=0;i<dotPosition;i++)
		{
			integer = integer+ (data[i+1]-48)+10*(dotPosition-i-1);
		}

		for(int i=0;dotPosition<i<strLength;i++)
		{
			decimal = decimal+(data[dotPosition+2]-48)+0.1*(i);
		}
	}

	result = integer + decimal;

	bool checkSign = str.data()[0] == 45;
	if(checkSign){ result = result*(-1); }

	return result;
}

string StringProc::longdoubleToString(long double data)
{
	return to_string(data);
}

int exponentiation_base10(int exponent)
{
	int result = 1;

	if(exponent > 0)
	{
		for(int i=0;i<exponent;i++)
		{
			result *= 10;
		}
	}

	return result;
}

