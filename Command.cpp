/*
 * Command.cpp
 *
 *  Created on: 2018. 10. 20.
 *      Author: jh
 */

#include "Command.hpp"

Command* Command::pcmd = NULL;

Command& Command::CMD()
{
	if(NULL== pcmd) { pcmd = new Command; }
	return *pcmd;
}

string Command::AddCommand(char input)
{
	SYMBOL symbol = m_symbolconvertor.getSYMBOL(input);

	if(symbol < 10)
	{
		m_strStack.push(input);
	}

	if(10 < symbol < 15)
	{
		calcNonOperationSymbol(input);
	}

	if(14 < symbol)
	{
		calcOperationSymbol(input);
		m_strStack = StringStack();
		return m_strProc.longdoubleToString(m_pData);
	}

	return m_strStack.getString();

}

void Command::calcNonOperationSymbol(char input)
{
	switch(input)
	{
		case 'a': // SYMBOL_CALC_AC
		{
			m_pData = 0;
		}
		/* no break */
		case 'c':
		{
			m_strStack = StringStack();
			break;
		}
		case '.': // SYMBOL_CALC_DOT
		{
			m_strStack.push(input);
			break;
		}

		case 'r': // SYMBOL_CALC_REMOVE
		{
			m_strStack.remove();
			break;
		}

	}

}

void Command::calcOperationSymbol(char input)
{
	if(m_isFirst)
	{
		m_pData = m_strProc.strTolongdouble(m_strStack.getString());
		m_isFirst = false;
	}

	if(!m_isFirst && !(m_strStack.isEmpty()) )
	{
		operate(m_operateSymbol);
	}

	m_operateSymbol = input;

}

void Command::operate(char operateSymbol)
{

	switch(m_operateSymbol)
	{

		case 37: // SYMBOL_CALC_PERCENT
		{
			m_pData = m_strProc.strTolongdouble(m_strStack.getString());
			break;
		}

		case '+': // SYMBOL_CALC_PLUS
		{
			m_pData = m_pData+m_strProc.strTolongdouble(m_strStack.getString());
			break;
		}

		case '-': // SYMBOL_CALC_MUNIUS
		{
			m_pData = m_pData-m_strProc.strTolongdouble(m_strStack.getString());
			break;
		}

		case '/': // SYMBOL_CALC_DIVIDE
		{
			m_pData = m_pData/m_strProc.strTolongdouble(m_strStack.getString());
			break;
		}

		case '*': // SYMBOL_CALC_MULTYPLE
		{
			m_pData = m_pData*m_strProc.strTolongdouble(m_strStack.getString());
			break;
		}

		case '=':
		{
			m_pData = m_strProc.strTolongdouble(m_strStack.getString());

			break;
		}

	}


}

