// nearestPowerOfTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <stdint.h>
#include <bitset>

bool isPowerOfTwo(uint32_t n)
{
	return n && !(n & (n - 1));
}

uint8_t msbDeBruijn32(uint32_t n)
{
	static const uint8_t multiplyByDeBruijnBitPosition[] = {
		0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
		8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
	};

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;

	return multiplyByDeBruijnBitPosition[(uint32_t)(n * 0x07c4acddu) >> 27];
}

uint32_t nearestHigherPowerOfTwo(uint32_t n)
{
	return 1 << (msbDeBruijn32(n) + 1);
}

int main()
{
	printf("DeBruijn most significat bit test:\n");

	for (uint32_t n = 0u; n < 260u; n++)
	{
		auto bs = std::bitset<10>(n);
		printf("%4u (0b%s) -> msb: %u, power of two: %s, nearist higher power of two: %u\n",
			n,
			bs.to_string().c_str(),
			msbDeBruijn32(n),
			isPowerOfTwo(n) ? "y" : "n",
			nearestHigherPowerOfTwo(n)
		);
	}
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
