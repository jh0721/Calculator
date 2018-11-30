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

	// 숫자가 들어오는 경우
	if(symbol < 10)
	{
		// 스택에 저장
		m_strStack.push(input);
		m_print = m_strStack.getString();
	}

	calcSymbol(symbol);

	return m_print;

}

void Command::calcSymbol(SYMBOL input)
{
	switch(input)
	{
		case SYMBOL_CALC_PLUS:
		case SYMBOL_CALC_MUNIUS:
		case SYMBOL_CALC_MULTYPLE:
		case SYMBOL_CALC_DIVIDE:
		{
			calcOperationSymbol(input);
			break;
		}

		case SYMBOL_CALC_EQUAL:
		{
			if(isOperate(input))
			{
				long double cData = m_strProc.strTolongdouble(m_strStack.getString());
				m_pData = operate(m_pData,cData,m_pOperator);
				m_print = m_strProc.longdoubleToString(m_pData);
				m_pOperator = input;
				m_pData = 0;
				m_strStack.clear();

			}else{

			}

			break;
		}

		case SYMBOL_AC:
		case SYMBOL_C:
		{
			clear(input);
			break;
		}

		case SYMBOL_DOT: // SYMBOL_CALC_DOT
		{
			// .이 있는 상태에서 붙이는 경 우
			if(m_strStack.hasDot())
			{
				break;
			}

			// 0 다음에 붙이는 경우
			if(m_strStack.strLength() == 1)
			{
				m_strStack.push('0');
			}

			// 일반숫자에 붙이는경우
			// 방법1
			//m_strStack.push(m_symbolconvertor.SYMBOLtoChar(input));
			// 방법2
			m_strStack.push('.');
			m_print = m_strStack.getString();

			break;
		}

		case SYMBOL_REMOVE: // SYMBOL_CALC_REMOVE
		{
			// 0 다음에 지우기 stack -> '0'
			// 연산기호 다음 지우기 stack -> '0'
			// 연산 완료 후 지우기 stack -> '0'
			// 그대로 출력
			if(m_strStack.isEmpty())
			{
				//m_pData
				m_print = m_strProc.longdoubleToString(m_pData);
				break;
			}

			// 일반숫자 다음 지우기
			m_strStack.remove();

			m_print = m_strStack.getString();

			break;
		}

		case SYMBOL_CALC_SIGNED:
		{

			// 0, 연산기호 다음, 연산 완료 후
			// 그대로 출력
			if(m_strStack.isEmpty())
			{
				m_print = m_strProc.longdoubleToString(m_pData);
				break;
			}

			// 일반 숫자
			m_strStack.addSigned();
			m_print = m_strStack.getString();

			break;
		}

		case SYMBOL_CALC_PERCENT:
		{
			// 0, 연산기호 다음, 연산 완료 후
			// 그대로 출력
			if(m_strStack.isEmpty())
			{
				m_print = m_strProc.longdoubleToString(m_pData);
				break;
			}

			long double temp = m_strProc.strTolongdouble(m_strStack.getString());
			m_print = m_strProc.longdoubleToString(temp*0.01);

			break;
		}

		default:
		{
			break;
		}

	}
}


void Command::calcOperationSymbol(SYMBOL input)
{
	// 1. 이전 데이터, 이전 연산자, 현재데이터가 있는상태에서 연산자가 들어온 경우
	// 우선순위 연산자
	// 전 전연산자가 +/- 이고 이전 연산자가*,/ 인 경우
	if(isOperate(input))
	{
		long double cData = m_strProc.strTolongdouble(m_strStack.getString());
		m_pData = operate(m_pData,cData,m_pOperator);
		m_print = m_strProc.longdoubleToString(m_pData);

	}else{
		m_pData = m_strProc.strTolongdouble(m_strStack.getString());
		m_print = m_strStack.getString();
	}

	m_pOperator = input;
	m_strStack.clear();

}

bool Command::isOperate(SYMBOL input)
{
	long double cData = m_strProc.strTolongdouble(m_strStack.getString());

	if( m_pData * cData ) return true;

	return false;
}

long double Command::operate(int pData,int cData,SYMBOL Operator)
{

	switch(Operator)
	{

		case SYMBOL_CALC_PLUS: // SYMBOL_CALC_PLUS
		{	return pData+cData; }

		case SYMBOL_CALC_MUNIUS: // SYMBOL_CALC_MUNIUS
		{	return pData - cData; }

		case SYMBOL_CALC_DIVIDE: // SYMBOL_CALC_DIVIDE
		{	return pData/cData;	}

		case SYMBOL_CALC_MULTYPLE: // SYMBOL_CALC_MULTYPLE
		{	return pData*cData; }

		default:
		{
			break;
		}

	}

	return 0;
}

void Command::clear(SYMBOL input)
{
	if(input == SYMBOL_AC )
	{
		m_pData = 0;
		m_pOperator = SYMBOL_CALC_EQUAL;

	}

	m_strStack.clear();
	m_print = m_strStack.getString();
}


