// commandPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <tchar.h>

struct A
{
	void foo()
	{
		_tprintf(_T("(%p) A::foo()\n"), this);
	}
};

struct B
{
	void bar(int i)
	{
		_tprintf(_T("(%p) B::bar(%d)\n"), this, i);
	}
};


template<typename Cls>
class Command
{
public:
	typedef void (Cls::*PFN_METHOD)(void);

	template<typename Cls>
	Command(Cls * cls, PFN_METHOD clsMethod)
	{
		m_cls = cls;
		m_method = clsMethod;
	}

	void execute()
	{
		if (m_cls && m_method)
		{
			(m_cls->*m_method)();
		}
	}

private:

	Cls * m_cls;
	PFN_METHOD m_method;
};


class CommandFn
{
public:

	//std::mem_fn()

};


int main()
{
	A a;

	Command<A> commandA(&a, &A::foo);

	commandA.execute();
	commandA.execute();
	commandA.execute();

	_tprintf(_T("done"));
	_gettch();

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
