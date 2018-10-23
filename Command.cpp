/*
 * Command.cpp
 *
 *  Created on: 2018. 10. 20.
 *      Author: jh
 */

#include "Command.hpp"

Command::Command(const long double pData) :m_pData(pData){}

Command::~Command() {}

Command* Command::pcmd = NULL;

Command& Command::CMD()
{
	if(NULL== pcmd) { pcmd = new Command; }
	return *pcmd;
}

string Command::AddCommand(char input)
{

	return "test";
}



