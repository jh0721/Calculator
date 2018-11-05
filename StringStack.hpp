/*
 * StringStack.hpp
 *
 *  Created on: 2018. 10. 27.
 *      Author: jh
 */

#ifndef STRINGSTACK_HPP_
#define STRINGSTACK_HPP_

#include<string>
#include<iostream>

using namespace std;

class StringStack
{
private:
	char strStack[50];
	int top;

public:
	StringStack():strStack(" 0"),top(1) {};
	~StringStack(){};

	void push(char);
	void remove();
	bool isEmpty();
	bool hasDot();

	const int strLength();
	const string getString();

	void addSigned();
	void clear();
	void setString(string);

};



#endif /* STRINGSTACK_HPP_ */
