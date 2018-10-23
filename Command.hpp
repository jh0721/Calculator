/*
 * Command.hpp
 *
 *  Created on: 2018. 10. 20.
 *      Author: jh
 */

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include<iostream>
#include <string>
#include "StringProc.hpp"

using namespace std;

class Command
{
private:
	long double m_pData;
	StringProc m_strProc;

private:
	Command(const long double pData=0);
	~Command();

public:
	// string
	string AddCommand(char);


private:
	static Command *pcmd;

public:
	static Command& CMD();
};




#endif /* COMMAND_HPP_ */
