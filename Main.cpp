//============================================================================
// Name        : Study.cpp
// Author      : JH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Command.hpp"

using namespace std;



int main() {


//	scanf("%c",&input);
//	printf("%s",Command::CMD().AddCommand(input));

	cout << Command::CMD().AddCommand('1') << endl;
	cout << Command::CMD().AddCommand('+') << endl;
	cout << Command::CMD().AddCommand('2') << endl;
	cout << Command::CMD().AddCommand(38) << endl;

//	const char str[10] = "td";
//
//	printf("%s",str);


	return 0;

}
