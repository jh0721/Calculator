/*
 * Command.hpp
 *
 *  Created on: 2018. 10. 20.
 *      Author: jh
 */

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include<iostream>
#include "StringProc.hpp"
#include "StringStack.hpp"
#include "Common.hpp"

using namespace std;

class Command
{
private:
	long double m_pData;
	StringProc m_strProc;
	StringStack m_strStack;
	char m_operateSymbol;

	Command(const long double pData=0)
		:m_pData(pData),m_strProc(StringProc()),m_strStack(StringStack()),m_operateSymbol(0)
	{ }
	~Command(){};

	bool checkInput(char);
	string calcSymbol(char);

	string calcNonOperationSymbol(char);
	string calcOperationSymbol(char);
	string operate(char);

public:
	string AddCommand(char);

private:
	static Command *pcmd;

public:
	static Command& CMD();
};


#endif /* COMMAND_HPP_ */
