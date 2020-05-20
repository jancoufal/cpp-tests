// enumClassAsBitfield.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <type_traits>
#include <cstdint>
#include <cstdio>

/*
 * This would enable bitwise or for all enum classes.
 * That's something we do not want to do.
 *
template<typename E>
E operator|(E lhs, E rhs)
{
	typedef typename std::underlying_type<E>::type underlying;
	return static_cast<E>(static_cast<underlying>(lhs) | static_cast<underlying>(rhs));
}
*/

// SFINAE
template<typename E>
struct enable_bitmask_operators
{
	static constexpr bool enable = false;
};

template<typename E>
typename std::enable_if<enable_bitmask_operators<E>::enable, std::underlying_type_t<E>>::type operator|(E lhs, E rhs)
{
	return static_cast<std::underlying_type_t<E>>(static_cast<std::underlying_type_t<E>>(lhs) | static_cast<std::underlying_type_t<E>>(rhs));
}

template<typename E>
typename std::enable_if<enable_bitmask_operators<E>::enable, bool>::type operator&(std::underlying_type_t<E> bitField, E enumValue)
{
	return bitField & static_cast<std::underlying_type_t<E>>(enumValue);
}

// enable bitfield macro
#define ENABLE_ENUM_CLASS_BITFIELD(ENUM_TYPE) \
	using ENUM_TYPE##BitField = std::underlying_type_t<ENUM_TYPE>; \
	template<> struct enable_bitmask_operators<ENUM_TYPE> { \
		static constexpr bool enable = true; \
	}

// bitwise enabled
enum class Color : uint16_t { red = 1, green = 2, blue = 4, alpha = 8 };
ENABLE_ENUM_CLASS_BITFIELD(Color);

// bitwise disabled
enum class Rotation { pitch, roll, yaw };


void printColors(ColorBitField colors)
{
	printf("Colors: ");
	if (colors & Color::red)
		printf("Red ");
	if (colors & Color::green)
		printf("Green ");
	if (colors & Color::blue)
		printf("Blue ");
	if (colors & Color::alpha)
		printf("Alpha ");
	printf("\n");
}

int main()
{
	ColorBitField colors = Color::red | Color::alpha;
	printColors(colors);
	
	//Rotation rotaions = Rotation::yaw | Rotation::roll;
	
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
