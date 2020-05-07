// weakPtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include <memory>

struct A
{
	A() : v(0) { printf("A(%p)\n", this); }
	~A() { printf("~A(%p)\n", this); }
	int v;
	void setVal(int v) { printf("A::setVal(%p => %d)\n", this, v); this->v = v; }
	int getVal() { printf("A::getVal(%p => %d)\n", this, v); return v; }
};

struct B
{
	B() { printf("B(%p)\n", this); }
	~B() { printf("~B(%p)\n", this); }
	std::weak_ptr<A> a;
	void setA(std::shared_ptr<A> a) { this->a = a; }
	std::shared_ptr<A> getA() { return a.lock(); }
};

int main()
{
	auto b = std::make_unique<B>();
	{
		auto a = std::make_shared<A>();
		b->setA(a);
		b->getA()->getVal();
		b->getA()->setVal(1337);
		b->getA()->getVal();
	}

	if (b->getA())
		b->getA()->getVal();
	else
		printf("b->getA() is not valid smart pointer\n");
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
