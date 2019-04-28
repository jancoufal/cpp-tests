// constexprEnum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>

enum EPrinterColors {
	PRN_CYAN = 0,
	PRN_MAGENTA = 1,
	PRN_YELLOW = 2,
	PRN_KEY = 3,
};

constexpr unsigned char MakeFlag(unsigned char value)
{
	return ((1 << value) - 1);
}

enum EPrinterColorsCodes {
	CODE_CYAN = MakeFlag(PRN_CYAN),
	CODE_MAGENTA = MakeFlag(PRN_MAGENTA),
	CODE_YELLOW = MakeFlag(PRN_YELLOW),
	CODE_KEY = MakeFlag(PRN_KEY),
};

int main()
{
	printf("EPrinterColors::PRN_CYAN: %d\n", EPrinterColors::PRN_CYAN);			// 0
	printf("EPrinterColors::PRN_MAGENTA: %d\n", EPrinterColors::PRN_MAGENTA);	// 1
	printf("EPrinterColors::PRN_YELLOW: %d\n", EPrinterColors::PRN_YELLOW);		// 2
	printf("EPrinterColors::PRN_KEY: %d\n", EPrinterColors::PRN_KEY);			// 3

	printf("EPrinterColorsCodes::CODE_CYAN: %d\n", EPrinterColorsCodes::CODE_CYAN);			// 0
	printf("EPrinterColorsCodes::CODE_MAGENTA: %d\n", EPrinterColorsCodes::CODE_MAGENTA);	// 1
	printf("EPrinterColorsCodes::CODE_YELLOW: %d\n", EPrinterColorsCodes::CODE_YELLOW);		// 3
	printf("EPrinterColorsCodes::CODE_KEY: %d\n", EPrinterColorsCodes::CODE_KEY);			// 7

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
