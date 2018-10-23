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

using namespace std;

int main() {


	char input;

	scanf("%c",&input);

//	printf("%s",Command::CMD().AddCommand(input));

	cout << Command::CMD().AddCommand('a') << endl;

	return 0;

}
