// interfaceWaterfall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>

struct IFoo
{
	virtual void foo() = 0;
};

class FooImpl : public IFoo
{
protected:
	virtual ~FooImpl() = default;
	void foo() override { printf("FooImpl::foo()\n"); }
};

struct IBar : IFoo
{
	virtual void bar() = 0;
};

class BarImpl : public IBar, FooImpl
{
public:
	virtual ~BarImpl() = default;
	void foo() override { FooImpl::foo(); }
	//using FooImpl::foo;	// doesn't work :(
	void bar() override { printf("BarImpl::bar()\n");  }
};

int main()
{
	IBar* bar = new BarImpl();

	bar->foo();
	bar->bar();

	delete bar;
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
