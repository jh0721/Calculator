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
#include "SymbolConvertor.hpp"

using namespace std;

class Command
{
private:
	long double m_pData;

	StringProc m_strProc;
	StringStack m_strStack;
	SymbolConvertor m_symbolconvertor;
	char m_operateSymbol;
	bool m_isFirst;

	Command(const long double pData=0)
		:m_pData(pData),
		 m_strProc(StringProc()),
		 m_strStack(StringStack()),
		 m_symbolconvertor(SymbolConvertor()),
		 m_operateSymbol(0),
		 m_isFirst(true)
	{ }
	~Command(){};

	void calcNonOperationSymbol(char);
	void calcOperationSymbol(char);
	void operate(char);

public:
	string AddCommand(char);

private:
	static Command *pcmd;

public:
	static Command& CMD();
};


#endif /* COMMAND_HPP_ */
