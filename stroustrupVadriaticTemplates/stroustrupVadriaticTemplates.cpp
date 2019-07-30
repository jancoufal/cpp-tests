// stroustrupVadriaticTemplates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// http://www.stroustrup.com/C++11FAQ.html#variadic-templates

#include "pch.h"
#include <string>
#include <iostream>


void test_print(const char *s)
{
	while (s && *s)
	{
		if (*s == '%' && *++s != '%')
			throw std::runtime_error("invalid format: missing arguments");

		std::cout << *s++;
	}
}


template<typename T, typename... Args>
void test_print(const char *s, T value, Args... args)
{
	while (s && *s)
	{
		if (*s == '%' && *++s != '%')
		{
			if (std::is_same<T, int>::value)			{ std::cout << " [this is int] "; }
			else if(std::is_same<T, float>::value)		{ std::cout << " [this is float] "; }
			else if(std::is_same<T, double>::value)		{ std::cout << " [this is double] "; }
			else if(std::is_same<T, const char*>::value){ std::cout << " [this is const char *] "; }
			else if(std::is_same<T, std::string>::value){ std::cout << " [this is std::string] "; }

			std::cout << value;
			return test_print(++s, args...);
		}

		std::cout << *s++;
	}

	throw std::runtime_error("extra arguments provided to test_print2");
}


int main()
{
	const std::string pi = "pi";
	const std::string phi = "phi";
	const char* m = "The value of %s is %g (unless you live in %s).\n";

	test_print("Simple non-formated string in test_print1().\n");

	try {
		test_print(m);
	}
	catch(std::runtime_error &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl;
	}

	test_print(m, pi, 3.1415, "Indiana");

	try {
		test_print(m, phi, 1.1618, "Mississippi", "and extra param");
	}
	catch (std::exception &e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}

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
