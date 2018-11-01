//============================================================================
// Name        : Study.cpp
// Author      : JH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Command.hpp"

#include <map>

using namespace std;

void inputCommand(char);
void stringCommand(const char*);

int main() {

// input은 정해진 문자열만 들어온다고 가정

	stringCommand("123+3*-=*1=1-");

	return 0;

}

void stringCommand(const char* str)
{
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		inputCommand(str[i]);
	}
}

void inputCommand(char input)
{
	printf("%s \n",Command::CMD().AddCommand(input).data());
}
