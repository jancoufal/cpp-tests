// callMethodByFunctionReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Callables
{
public:

	int run() {

		int result = 0;

		struct {
			FN_PTR fn; int a; int b;
		} callies[] = {
			{ &Callables::fn1, 1, 2 },
			{ &Callables::fn2, 3, 4 },
			{ &Callables::fn3, 5, 6 },
			{ &Callables::fn4, 7, 8 },
		};

		for (auto & callie : callies) {

			result += (this->*(callie.fn))(callie.a, callie.b);
		}

		return result;
	};

private:
	typedef int (Callables::*FN_PTR)(int, int);

	int fn1(int a, int b) { return a + b; }
	int fn2(int a, int b) { return a - b; }
	int fn3(int a, int b) { return a * b; }
	int fn4(int a, int b) { return a / b; }	// don't use zero :)
};


int main()
{
	int result = Callables().run();

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
