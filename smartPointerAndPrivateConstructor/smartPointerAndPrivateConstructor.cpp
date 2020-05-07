// smartPointerAndPrivateConstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <memory>
#include <iostream>

struct IB
{
	virtual void meow() = 0;
};

class B : IB
{
	friend class A;
	friend std::unique_ptr<B> std::make_unique<B>();

	B();
	static std::unique_ptr<B> create();
	static B* createRaw();
public:
	void meow() override;
};

class A
{
public:
	std::unique_ptr<B> createB()
	{	
		return nullptr;
		//return std::unique_ptr<B>(nullptr);
		//return B::create();
		//return std::make_unique<B>(b);	// private access violation
	}

	B* createBRaw()
	{
		return B::createRaw();
	}
};

// B impl
B::B() {}
std::unique_ptr<B>B::create() { return std::make_unique<B>(); }
B* B::createRaw() { return new B(); }
void B::meow() { std::cout << "meow" << std::endl; }

//
int main()
{
	auto a = A();
	auto b = a.createBRaw();

	b->meow();

	delete b;
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
