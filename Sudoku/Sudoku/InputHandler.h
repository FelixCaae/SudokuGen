#pragma once
class ArgumentHandler
{

public:
	enum State { GEN, SOV, INV };
	ArgumentHandler();
	void ParseInput(int argc, char **argv);
	State GetState();
	unsigned int GetCount();
	char * GetPathName();
	~ArgumentHandler();
private:
	State state;
	unsigned int count;
	char* pathname;
};

