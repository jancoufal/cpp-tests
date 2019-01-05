// staticTranslateTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <string>
#include <utility>

// TODO: needs template specialization for types,
// that cannot be compare with simple equality (e.g. strings).
template<typename K, typename V, size_t N>
V lookup(K needle, std::pair<K,V> (&lut)[N], V notFoundValue = nullptr)
{
	for (auto p : lut)
		if (p.first == needle)
			return p.second;

	return notFoundValue;
}

// doesn't work of course, because lookup() is not specialized
const wchar_t* translateTest1(const wchar_t* v)
{
	static std::pair<const wchar_t*, const wchar_t*> TRANSLATE_TABLE[] = {
		{ L"key1", L"1. value" },
		{ L"key2", L"2. value" },
		{ L"key3", L"3. value" },
	};

	return lookup(v, TRANSLATE_TABLE);
}

const int translateTest2(const int v)
{
	static std::pair<int, int> TRANSLATE_TALBE[] = {
		{ 1, 42 },
		{ 2, 666 },
		{ 3, 1337 },
	};

	return lookup(v, TRANSLATE_TALBE, -1);
}

int main()
{
	std::wstring wstrKey(L"key2");
	printf("test1: %ws\n", translateTest1(wstrKey.c_str()));

	int intKey = 2;
	printf("test2: %d", translateTest2(intKey));
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
