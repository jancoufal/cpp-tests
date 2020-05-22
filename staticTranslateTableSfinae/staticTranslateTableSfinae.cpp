// staticTranslateTableSfinae.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include "translate.h"

int main()
{
	// do not do this in a real code
	using namespace translate;
	
	printf("lookup():\n");
	printf("red: %d\n", lookup(Color::Red).value_or(-1));
	printf("alpha: %d\n", lookup(Color::Alpha).value_or(-1));
	
	printf("yaw: %d\n", lookup(Rotation::Yaw).value_or(-1));
	printf("roll: %d\n", lookup(Rotation::Roll).value_or(-1));

	printf("lookupReverse():\n");
	auto oc = lookupReverse_Color(1); // red
	printf("red: %s\n", oc ? std::to_string(static_cast<int>(oc.value())).c_str() : "not_found");
	oc = lookupReverse_Color(4); // alpha
	printf("alpha: %s\n", oc ? std::to_string(static_cast<int>(oc.value())).c_str() : "not_found");

	auto ot = lookupReverse_Rotation(3); // yaw
	printf("yaw: %s\n", ot ? std::to_string(static_cast<int>(ot.value())).c_str() : "not_found");
	ot = lookupReverse_Rotation(-1); // no defined
	printf("roll: %s\n", ot ? std::to_string(static_cast<int>(ot.value())).c_str() : "not_found");
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
