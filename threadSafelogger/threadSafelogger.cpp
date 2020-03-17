// threadSafelogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <stdarg.h>

int main()
{
}

struct ILogger
{
	virtual int log(char16_t * fmt, ...) = 0;
};

struct LoggerStdout
	: public ILogger
{
public:

	virtual int log(char16_t * fmt, ...) override
	{
		va_list ap;
		va_start(ap, fmt);

		int ret = wprintf(fmt, );

		va_end(ap);

		return ret;
	}

};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
