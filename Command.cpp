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

	if(checkInput(input))
	{
		m_strStack.push(input);
		return m_strStack.getString();
	}

	string result = calcSymbol(input);

	return result;
}

bool Command::checkInput(char input)
{
	// type enum check ...

	return (input > 47);
}

string Command::calcSymbol(char input)
{
	string result;
	result = calcNonOperationSymbol(input);

	if(result == "")
	{
		result = calcOperationSymbol(input);
		m_strStack = StringStack();
	}

	return result;
}

string Command::calcNonOperationSymbol(char input)
{
	string result;
	switch(input)
	{
		case 39: // SYMBOL_CALC_AC
		{
			m_pData = 0;
			result = m_strStack.getString();
			break;
		}
		case 46: // SYMBOL_CALC_DOT
		{
			m_strStack.push(input);
			result = m_strStack.getString();
			break;
		}

		case 36: // SYMBOL_CALC_REMOVE
		{
			m_strStack.remove();
			result = m_strStack.getString();
			break;
		}

		case 35: // SYMBOL_CALC_SIGNED
		{
			m_strStack.addSigned();
			result = m_strStack.getString();
			break;
		}
		default:
		{
			result = "";
		}
	}
	return result;
}

string Command::calcOperationSymbol(char input)
{
	string result;
	if(m_operateSymbol != 0)
	{
		result = operate(m_operateSymbol);
	}else{
		m_pData = m_strProc.strTolongdouble(m_strStack.getString());
		result = m_strStack.getString();
	}

	m_operateSymbol = input;

	return result;
}

string Command::operate(char operateSymbol)
{
	string result;
	switch(operateSymbol)
	{

		case 37: // SYMBOL_CALC_PERCENT
		{
			m_pData = m_strProc.strTolongdouble(m_strStack.getString());
			result = m_strStack.getString();
			break;
		}

		case 43: // SYMBOL_CALC_PLUS
		{
			m_pData = m_pData+m_strProc.strTolongdouble(m_strStack.getString());
			result = m_strProc.longdoubleToString(m_pData);
			break;
		}

		case 45: // SYMBOL_CALC_MUNIUS
		{
			m_pData = m_pData-m_strProc.strTolongdouble(m_strStack.getString());
			result = m_strProc.longdoubleToString(m_pData);
			break;
		}

		case 47: // SYMBOL_CALC_DIVIDE
		{
			m_pData = m_pData/m_strProc.strTolongdouble(m_strStack.getString());
			result = m_strProc.longdoubleToString(m_pData);
			break;
		}

		case 42: // SYMBOL_CALC_MULTYPLE
		{
			m_pData = m_pData*m_strProc.strTolongdouble(m_strStack.getString());
			result = m_strProc.longdoubleToString(m_pData);
			break;
		}

		case 38: // SYMBOL_CALC_EQUAL
		{
			m_operateSymbol = 0;
			m_pData = m_strProc.strTolongdouble(m_strStack.getString());
			result = m_strStack.getString();
			break;
		}


	}

	return result;
}

