#include "stdafx.h"
#include "FileHandler.h"
#include "SdkBuffer.h"

FileHandler::FileHandler()
{
	 
}
bool FileHandler::Open(const char * pathname,const char *mode )
{
	fopen_s(&file, pathname, mode);
	if (file == NULL)
	{
		return false;
	}
	return true;
}
void FileHandler::ReadSdb(SdkBuffer* sdb)
{
	static int buffer[9][9];
	char c;
	while (true) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				c = fgetc(file);
				if (c == ' ')buffer[i][j] = 0;//FILE error proccess
				else buffer[i][j] = c - '0';
			}
			fgetc(file);
		}
		bool r=sdb->Fill(buffer);
		if (fgetc(file) == EOF)break;
	}
}
void FileHandler::WriteSdb(SdkBuffer* sdb)
{
	const char *buffer = sdb->GetBuffer();
	unsigned int index = 0;
	for (; index < sdb->GetSize(); index++) {
		for (int i = 0; i < 9; i++)
		{
			fwrite(buffer + index * 81 + i * 9, 9, sizeof(char), file);
			fputc('\n',file);
		}
		fputc('\n', file);
	}
}
void FileHandler::Close()
{
	if (file != NULL)
	{
		fclose(file);
	}
}
bool FileHandler::HasNext()
{
	return feof(file)==0;
}
FileHandler::~FileHandler()
{
}
