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

float exponentiation_base10(int);

int checkDecimal(const char* str,int length)
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
	int dotPosition = checkDecimal(data,strLength);

	int integer = 0;
	double decimal = 0;

	if(dotPosition)
	{
		integer = 0;
		for(int i=dotPosition;i>1;i--)
		{
			integer = integer+ (data[i-1]-48)*exponentiation_base10(dotPosition - i);
		}

		for(int i=0; i < (strLength - dotPosition) ;i++)
		{
			decimal = decimal+(data[dotPosition+1+i]-48)*exponentiation_base10(-1-i);
		}



	}else{

		for(int i=0;i<strLength;i++)
		{
			integer = integer + (data[i+1]-48)*exponentiation_base10(strLength-i-1);
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

float exponentiation_base10(int exponent)
{
	float result = 1;

	if(exponent > 0)
	{
		for(int i=0;i<exponent;i++)
		{
			result *= 10;
		}
	}else if(exponent == 0)
	{

	}else{
		for(int i=0;i<(exponent*(-1));i++)
		{
			result = result * 0.1;
		}

	}



	return result;
}

