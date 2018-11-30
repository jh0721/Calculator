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
	long double m_ppData;

	bool m_operateState;
	bool m_pOperateState;

	StringProc m_strProc;
	StringStack m_strStack;
	SymbolConvertor m_symbolconvertor;

	SYMBOL m_pOperator;
	SYMBOL m_ppOperator;

	string m_print;



	Command(const long double pData=0)
		:m_pData(pData),
		 m_ppData(0),

		 m_operateState(false),
		 m_pOperateState(false),

		 m_strProc(StringProc()),
		 m_strStack(StringStack()),
		 m_symbolconvertor(SymbolConvertor()),

		 m_pOperator(SYMBOL_CALC_EQUAL),
		 m_ppOperator(SYMBOL_CALC_EQUAL),

		 m_print("0")
	{ }
	~Command(){};

	void calcSymbol(SYMBOL);

	void calcOperationSymbol(SYMBOL);
	bool isOperate(SYMBOL);
	long double operate(int,int,SYMBOL);

	void clear(SYMBOL);


public:
	string AddCommand(char);

private:
	static Command *pcmd;

public:
	static Command& CMD();
};


#endif /* COMMAND_HPP_ */
