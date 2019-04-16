// overriddenMethodCall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//class Base;
//class Derived;

class Base
{
public:

	const char* foo() {
		return "Base::foo()";
	}

	virtual const char* bar() {
		return "Base::bar()";
	}
};

class Derived : public Base
{
public:

	// uncommenting the "override" keyword will discover the bug
	const char* foo() /*override*/ {
		return "Derived::foo()";
	}

	virtual const char* bar() override {
		return "Derived::bar()";
	}
};

int main()
{
	Base *b = new Base();
	Derived *d = new Derived();
	Base *derivedAsBase = dynamic_cast<Base*>(d);

	printf("(new Base())->foo(): %s\n", b->foo());
	printf("(new Base())->bar(): %s\n", b->bar());

	printf("(new Derived())->foo(): %s\n", d->foo());
	printf("(new Derived())->bar(): %s\n", d->bar());

	printf("(dynamic_cast<Base*>(new Derived()))->foo(): %s\n", derivedAsBase->foo());
	printf("(dynamic_cast<Base*>(new Derived()))->bar(): %s\n", derivedAsBase->bar());

	delete b;
	delete d;

	/*

	Output:
		(new Base())->foo(): Base::foo()
		(new Base())->bar(): Base::bar()
		(new Derived())->foo(): Derived::foo()
		(new Derived())->bar(): Derived::bar()
		(dynamic_cast<Base*>(new Derived()))->foo(): Base::foo()
		(dynamic_cast<Base*>(new Derived()))->bar(): Derived::bar()
	*/
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
