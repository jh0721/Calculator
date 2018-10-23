/*
 * ConverInput.hpp
 *
 *  Created on: 2018. 10. 20.
 *      Author: jh
 */

#ifndef CONVERINPUT_HPP_
#define CONVERINPUT_HPP_

class Convert
{
public:
	Convert(){};
	virtual ~Convert(){};

};

class ConverInputString:public Convert
{
private:
	long double m_data;

public:
	ConverInputString(const long double& data):m_data(data){};
	virtual ~ConverInputString(){};

	const long double toNumber();

};

class ConverInputNum:public Convert
{
private:
	long double m_data;

public:
	ConverInputNum(const long double& data):m_data(data){};
	virtual ~ConverInputNum(){};

	const char* toString();

};


#endif /* CONVERINPUT_HPP_ */
