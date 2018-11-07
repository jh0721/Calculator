//============================================================================
// Name        : Study.cpp
// Author      : JH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Command.hpp"
#include "SymbolConvertor.hpp"

#include <map>

using namespace std;

void inputCommand(const char*);
void runCommand(char);

int main() {

// input은 정해진 문자열만 들어온다고 가정

	inputCommand("1*0=");

	return 0;

}

void inputCommand(const char* str)
{
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		runCommand(str[i]);
	}
}

void runCommand(char input)
{
	printf("%s \n",Command::CMD().AddCommand(input).data());
}
