// rvalueReferences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class XNoMove {
public:
	XNoMove() { printf("  XNoMove::XNoMove();\n"); }
	XNoMove(const XNoMove &) { printf("  XNoMove::XNoMove(const XNoMove &);\n"); }
	XNoMove& operator=(const XNoMove &) { printf("  XNoMove::operator=(const XNoMove &);\n"); return *this; }
};

class XMove {
public:
	XMove() { printf("  XMove::XMove();\n"); }
	XMove(const XMove &) { printf("  XMove::XMove(const XMove &);\n"); }
	XMove(const XMove &&) { printf("  XMove::XMove(const XMove &&);\n"); }
	XMove& operator=(const XMove &) { printf("  XNoMove::operator=(const XMove &);\n"); return *this; }
	XMove& operator=(const XMove &&) { printf("  XNoMove::operator=(const XMove &&);\n"); return *this; }
};

template<typename T>
T factory()
{
	T item;
	printf(" factory() => done\n");
	return item;
}

template<typename T>
T factoryStdMove()
{
	T item;
	printf(" factoryStdMove() => done\n");
	return std::move(item);
}



int main()
{
	printf("\nTesting with copy constructor:\n");

	printf("\nXNoMove testing with ::factory:\n");
	{ XNoMove x = ::factory<XNoMove>(); }

	printf("\nXMove testing with ::factory:\n");
	{ XMove x = ::factory<XMove>(); }

	printf("\nXNoMove testing with ::factoryStdMove:\n");
	{ XNoMove x = ::factoryStdMove<XNoMove>(); }

	printf("\nXMove testing with ::factoryStdMove:\n");
	{ XMove x = ::factoryStdMove<XMove>(); }

	printf("\n\nTesting with assign operator:\n");

	printf("\nXNoMove testing with ::factory:\n");
	{ XNoMove x; x = ::factory<XNoMove>(); }

	printf("\nXMove testing with ::factory:\n");
	{ XMove x; x = ::factory<XMove>(); }

	printf("\nXNoMove testing with ::factoryStdMove:\n");
	{ XNoMove x; x = ::factoryStdMove<XNoMove>(); }

	printf("\nXMove testing with ::factoryStdMove:\n");
	{ XMove x; x = ::factoryStdMove<XMove>(); }


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
