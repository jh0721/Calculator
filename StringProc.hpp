/*
 * StringPro.hpp
 *
 *  Created on: 2018. 10. 20.
 *      Author: jh
 */

#ifndef STRINGPROC_HPP_
#define STRINGPROC_HPP_

#include <string>

using namespace std;

class StringProc
{
private:


public:
	StringProc(){};
	~StringProc(){};

	long double strTolongdouble(string);
	string longdoubleToString(long double);

	// 숫자 문자 변환
	// TODO

};



#endif /* STRINGPROC_HPP_ */
