#include "stdafx.h"
#include "ArgumentHandler.h"
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
	if (argc != 3)
	{
		cout << "The number of arguments is not correct" << endl;
		return;
	}
	if (strcmp(args[1] , "-c")==0)
	{
		state = State::GEN;
		try
		{
			sscanf_s(args[2], "%d", &count);
		}
		catch (exception ex)
		{
			cout << "Argument error";
		}
	}
	else if (strcmp(args[1], "-s")==0)
	{
		state = State::SOV;
		pathname = args[2];
	}


}

