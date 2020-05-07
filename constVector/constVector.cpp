// constVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <vector>

class A
{
public:
	A(int v) noexcept : v(v) { printf("A(%p, %d)\n", this, v); }
	A(const A& a) noexcept : v(a.v) { printf("A(%p from &%p, %d)\n", this, &a, v); }
	A(const A&& a) noexcept : v(a.v) { printf("A(%p from &&%p, %d)\n", this, &a, v); }
	~A() { printf("~A(%p, %d)\n", this, v); }
	int get() const { return v; };
	void set(int v) { this->v = v; }
private:
	int v;
};

class B
{
public:
	B(int c)
	{
		printf("B(%d)\n", c);
		for (int i = 0; i < c; i++)
			a.push_back(A(i));
		printf("end of B(%d)\n", c);
	}

	const std::vector<A>* get() const
	{
		printf("B::get(%p)\n", &a);
		return &a;
	}

private:
	std::vector<A> a;
};

int main()
{
	auto b = B(3);

	printf("b.get() -> %p\n", b.get());
	
	for (auto a : *b.get())
		printf("a(%p): %d\n", &a, a.get());

	for (auto a : *b.get())
		a.set(42);
	
	for (auto a : *b.get())
		printf("a(%p): %d\n", &a, a.get());
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
