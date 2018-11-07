/*
 * ConvertInput.hpp
 *
 *  Created on: 2018. 10. 31.
 *      Author: jh
 */

#ifndef SYMBOLCONVERTOR_HPP_
#define SYMBOLCONVERTOR_HPP_

#include<map>
#include "Common.hpp"

using namespace std;

class SymbolConvertor
{
private:
	map<char,SYMBOL> inputMap;

public:
	SymbolConvertor();

	SYMBOL getSYMBOL(char);
	char SYMBOLtoChar(SYMBOL);


};



#endif /* SYMBOLCONVERTOR_HPP_ */
