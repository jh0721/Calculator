/*
 * ConvertInput.cpp
 *
 *  Created on: 2018. 10. 31.
 *      Author: jh
 */

#include "SymbolConvertor.hpp"

SymbolConvertor::SymbolConvertor()
{
	inputMap['0'] = SYMBOL_NUM_0;
	inputMap['1'] = SYMBOL_NUM_1;
	inputMap['2'] = SYMBOL_NUM_2;
	inputMap['3'] = SYMBOL_NUM_3;
	inputMap['4'] = SYMBOL_NUM_4;
	inputMap['5'] = SYMBOL_NUM_5;
	inputMap['6'] = SYMBOL_NUM_6;
	inputMap['7'] = SYMBOL_NUM_7;
	inputMap['8'] = SYMBOL_NUM_8;
	inputMap['9'] = SYMBOL_NUM_9;


	inputMap['a'] = SYMBOL_AC;
	inputMap['c'] = SYMBOL_C;
	inputMap['.'] = SYMBOL_DOT;
	inputMap['r'] = SYMBOL_REMOVE;


	inputMap['!'] = SYMBOL_CALC_SIGNED;
	inputMap['%'] = SYMBOL_CALC_PERCENT;
	inputMap['+'] = SYMBOL_CALC_PLUS;
	inputMap['-'] = SYMBOL_CALC_MUNIUS;
	inputMap['/'] = SYMBOL_CALC_DIVIDE;
	inputMap['*'] = SYMBOL_CALC_MULTYPLE;
	inputMap['='] = SYMBOL_CALC_EQUAL;
}

SYMBOL SymbolConvertor::getSYMBOL(char input)
{
	return inputMap[input];
}

char SymbolConvertor::SYMBOLtoChar(SYMBOL input)
{
	char highest = inputMap.rbegin()->first;
	map<char,SYMBOL>::key_compare mycomp = inputMap.key_comp();

	map<char,SYMBOL>::iterator it = inputMap.begin();
	do {
		if( (it->second) == input)
		{
			return it->first;
		}
	} while ( mycomp((*it++).first, highest) );


	return 0;
}
