#include "stdafx.h"
#include "InputHandler.h"
#include <iostream>
using namespace std;

ArgumentHandler::ArgumentHandler()
{
	state = INV;
	count = 0;
	pathname = NULL;
}
ArgumentHandler::~ArgumentHandler()
{
}
char *ArgumentHandler::GetPathName()
{
	return pathname;
}
unsigned int ArgumentHandler::GetCount()
{
	return count;
}
ArgumentHandler::State ArgumentHandler::GetState()
{
	return state;
}
void ArgumentHandler::ParseInput(int argc,char** args)
{
	if (argc != 3) {
		cout << "too much arguments" << endl;
		return;
	}
	if (args[1] == "-c")
	{
		state = State::GEN;
		sscanf_s(args[2], "%d", &count);
	}
	else if (args[1] == "-s")
	{
		state = State::SOV;
		pathname = args[2];
	}


}
