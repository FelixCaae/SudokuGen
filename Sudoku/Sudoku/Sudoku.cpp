// Sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "FileHandler.h"
#include "InputHandler.h"
#include "SdkBuffer.h"
#include "Table.h"
#include <time.h>
using namespace std;
typedef ArgumentHandler::State state;
const unsigned  int BufferSize = 10000;    
const int MaxCounts = 100000;
int main(int argc,char**args)
{
	clock_t start = clock();
	ArgumentHandler* ah = new ArgumentHandler();
	ah->ParseInput(argc,args);
	state st = ah->GetState();
	if (st == state::INV)
	{
		cout << "Input Error"<<endl;
		delete ah;
		return 1;
	}
	FileHandler *fh = new FileHandler();
	Table *tb = new Table();
	SdkBuffer *sdb = new SdkBuffer(BufferSize);
	if (st == state::GEN)
	{
		do {
			unsigned int count = ah->GetCount();
			if (count > MaxCounts)
			{
				cout << "Count is too big" << endl;
				break;
			}
			if (!fh->Open("sudoku.txt","w")) {
				cout << "File IO error!" << endl;
				break;
			}
			tb->SetZero();
			tb->Set(0, 0, 6);
			tb->Generate(count,fh);
		} while (false);
	}
	else
	{
		FileHandler* dst = new FileHandler();
		dst->Open("sudoku.txt","w");
		do {
			fh->Open(ah->GetPathName(),"r");
			tb->Solve(fh, dst);
		} while (false);
		dst->Close();
		delete dst;
	}
	fh->Close();
	delete fh;
	delete tb;
	delete sdb;
	cout << "elapsed" << (float(clock()) - start) / 1000;
	getchar();
	return 0;
}

