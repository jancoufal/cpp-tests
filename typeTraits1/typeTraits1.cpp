// typeTraits1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include "drill-robot.h"

typedef void(*PFN_DRILL)(DrillingRobot&, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

PFN_DRILL getDrill(int type)
{
	switch (type) {
	case 1: return DrillCandleHolder<Iron>;
	case 2: return DrillCandleHolder<Aluminium>;
	case 3: return DrillCandleHolder<Pine>;
	case 4: return DrillCandleHolder<Teak>;
	case 5: return DrillCandleHolder<Plastic>;
	default: return nullptr;
	}
}


int main()
{
	DrillingRobot drillingRobot;

	/*
	// OK
	DrillCandleHolder<Iron>(drillingRobot, 10, 4, 20, 10, 0, 0);
	DrillCandleHolder<Aluminium>(drillingRobot, 10, 4, 20, 10, 0, 0);
	DrillCandleHolder<Pine>(drillingRobot, 10, 4, 20, 10, 0, 0);
	DrillCandleHolder<Teak>(drillingRobot, 10, 4, 20, 10, 0, 0);
	DrillCandleHolder<Plastic>(drillingRobot, 10, 4, 20, 10, 0, 0);
	*/

	PFN_DRILL fnDrill = nullptr;
	for (auto i = 0; i < 7; ++i) {

		if ((fnDrill = getDrill(i)) != nullptr) {

			fnDrill(drillingRobot, 10, 4, 20, 10, 0, 0);
		}
	}

	printf("done\n");
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
