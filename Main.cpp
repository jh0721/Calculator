//============================================================================
// Name        : Study.cpp
// Author      : JH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Command.hpp"
#include "SymbolConvertor.hpp"

#include <map>

using namespace std;

template<class T>
void print(T text)
{
	cout << text << endl;
}

void inputCommand(const char*);
void runCommand(char);

void case1();
void case2();
void case3();
void case4();
void case5();
void case6();
void case7();
void case8();
void case9();


int main() {

// input은 정해진 문자열만 들어온다고 가정

	case1();
	case2();
	case3();
	case4();
	case5();
	case6();
	case7();
	case8();
	case9();

	return 0;

}

void inputCommand(const char* str)
{
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		runCommand(str[i]);
	}

	print(" ");
}

void runCommand(char input)
{
	printf("%s \n",Command::CMD().AddCommand(input).data());
}

// 사칙연산
void case1()
{
	print("case1");
	print(" ");

	inputCommand("5+6=");
	inputCommand("5-6=");
	inputCommand("5*6=");
	inputCommand("5/6=");

	print("end");
	print(" ");
}

// 소수점 연산
void case2()
{
	print("case2");
	print(" ");

	inputCommand("5.1+6.4=");
	inputCommand("5.2-6.3=");
	inputCommand("5.4*6.5=");
	inputCommand("5.2/6.3=");

	print("end");
	print(" ");
}

// SYMBOL ac
void case3()
{
	print("case3");
	print(" ");

	inputCommand("a");
	inputCommand("5a");
	inputCommand("3+4*a3+3=a");

//	inputCommand("3+4aa3+3=a");
	inputCommand("3+4ca3+3=a");
	inputCommand("3+4.a3+3=a");
	inputCommand("3+4ra3+3=a");
	inputCommand("3+4!a4+3=a");
	inputCommand("3+4%a4+3=a");
	inputCommand("3+4=a4+3=a");

	print("end");
	print(" ");
}

// SYMBOL c
void case4()
{
	print("case4");
	print(" ");

	inputCommand("c");
	inputCommand("5c");

	// 결과값 ?
	// 1+4c 1+
	// 4*c  4*
	inputCommand("3+4*c3+3=a");

	inputCommand("3+4ac3+3=a");
//	inputCommand("3+4cc3+3=a");
	inputCommand("3+4.c3+3=a");
	inputCommand("3+4rc3+3=a");
	inputCommand("3+4!c4+3=a");
	inputCommand("3+4%c4+3=a");
	inputCommand("3+4=c4+3=a");

	print("end");
	print(" ");
}

// SYMBOL dot
void case5()
{
	print("case5");
	print(" ");

	inputCommand(".a");
	inputCommand("5.a");
	// 계산기 7.2 연산우선순위
	// 5.1
	inputCommand("3+4*.3+3=a");

	inputCommand("3+4a.3+3=a");
	inputCommand("3+4c.3+3=a");
//	inputCommand("3+4..3+3=a");
	inputCommand("3+4r.3+3=a");
	inputCommand("3+4!.4+3=a");

	// 계산기 6.4
	// 6.04
	inputCommand("3+4%.4+3=a");
	inputCommand("3+4=.4+3=a");

	print("end");
	print(" ");
}

// SYMBOL REMOVE
void case6()
{
	print("case6");
	print(" ");

	inputCommand("ra");
	inputCommand("5ra");
	// 계산기 18 연산 우선순위
	// 24
	inputCommand("3+4*r3+3=a");

	inputCommand("3+4ar3+3=a");
	inputCommand("3+4cr3+3=a");
	inputCommand("3+4.r3+3=a");
//	inputCommand("3+4rr3+3=a");
	// -0
	inputCommand("3+4!r4+3=a");
	// 4%r -> 0.04
	inputCommand("3+4%r4+3=a");
	inputCommand("3+4=r4+3=a");

	print("end");
	print(" ");
}

// SYMBOL signed
void case7()
{
	print("case7");
	print(" ");

	inputCommand("!a");
	inputCommand("5!a");
	// 연산우선순위
	inputCommand("3+4*!3+3=a");

	inputCommand("3+4a!3+3=a");
	inputCommand("3+4c!3+3=a");
	inputCommand("3+4.!3+3=a");
	inputCommand("3+4r!3+3=a");
//	inputCommand("3+4!!4+3=a");
	inputCommand("3+4%!4+3=a");
	// 계산기 =! -7
	// 7
	inputCommand("3+4=!4+3=a");

	print("end");
	print(" ");
}

// SYMBOL percent
void case8()
{
	print("case8");
	print(" ");

	inputCommand("%a");
	inputCommand("5%a");
	// 연산자 우선순위
	inputCommand("3+4*%3+3=a");

	inputCommand("3+4a%3+3=a");
	inputCommand("3+4c%3+3=a");
	// 4. // 0.38??
	inputCommand("3+4.%3+3=a");
	inputCommand("3+4r%3+3=a");
	// -26.96???
	inputCommand("3+4!%4+3=a");
//	inputCommand("3+4%%4+3=a");
	// 연산결과의 % ...
	inputCommand("3+4=%4+3=a");

	print("end");
	print(" ");
}

// SYMBOL equal
void case9()
{
	print("case9");
	print(" ");

	inputCommand("=a");
	inputCommand("5=a");
	inputCommand("3+4*=3+3=a");

	inputCommand("3+4a=3+3=a");
	inputCommand("3+4c=3+3=a");
	// 4. 숫자변환시 40으로 변환...
	inputCommand("3+4.=3+3=a");
	inputCommand("3+4r=3+3=a");
	inputCommand("3+4!=4+3=a");
	inputCommand("3+4%=4+3=a");
//	inputCommand("3+4==4+3=a");

	print("end");
	print(" ");
}
