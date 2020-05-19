// compileTimeGeneratedLookupTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include <array>

// C++17

constexpr auto f(const int x)
{
    return x + 1;
};

template<class T, size_t N, class F>
constexpr auto make_table(F func, T first)
{
    std::array<T, N> a{ first };
    for (size_t i = 1; i < N; ++i)
    {
        a[i] = func(a[i - 1]);
    }
    return a;
}

int main()
{
    constexpr auto arr = make_table<int, 1024>(f, 1);
	
    printf("lookup value: %d\n", arr[1023]);
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
