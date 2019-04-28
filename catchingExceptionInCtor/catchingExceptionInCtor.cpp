// catchingExceptionInCtor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <tchar.h>

struct A {
	A(int a) {
		_tprintf(_T("A::A(a => %d)\n"), a);
		throw true;
		m_a = a;
	}

	~A() {
		_tprintf(_T("A::~A()\n"));
	}

	int m_a;
};

struct B {
	B(int b) {
		_tprintf(_T("B::B(b => %d)\n"), b);
		m_b = b;
	}

	~B() {
		_tprintf(_T("B::~B()\n"));
	}

	int m_b;
};

struct C : B {
	C(int c) try : B(-c), m_a(666) {

		_tprintf(_T("C::C(c => %d)\n"), c);
		m_c = c;
	}
	catch (bool e) {

		_tprintf(_T("exception catched in B constructor: %d\n"), e);
	}

	~C() {
		_tprintf(_T("C::~C()\n"));
	}

	A m_a;
	int m_c;
};

int main()
{
	try {

		C x(42);

	}
	catch (bool e) {

		_tprintf(_T("global exception: %d\n"), e);
	}

	_tprintf(_T("done\n"));

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
