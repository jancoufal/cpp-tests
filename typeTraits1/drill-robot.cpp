#include "drill-robot.h"

#define ENUM_TO_STRING_SWITCH(v) switch(v) {
#define ENUM_TO_STRING_CASE(c) case c: return #c;
#define ENUM_TO_STRING_SWITCH_END() default: return ""; }

const char* DrillingRobot::EnumToString(DrillBitType drillBit) {
	ENUM_TO_STRING_SWITCH(drillBit)
		ENUM_TO_STRING_CASE(DB_UNDEFINED)
		ENUM_TO_STRING_CASE(DB_METAL)
		ENUM_TO_STRING_CASE(DB_WOOD)
		ENUM_TO_STRING_SWITCH_END()
		//return _T("DrillBitType");
}
const char* DrillingRobot::EnumToString(Rpm rpm) {
	ENUM_TO_STRING_SWITCH(rpm)
		ENUM_TO_STRING_CASE(RPM_LOW)
		ENUM_TO_STRING_CASE(RPM_MEDIUM)
		ENUM_TO_STRING_CASE(RPM_HIGH)
		ENUM_TO_STRING_SWITCH_END()
		//return _T("Rpm");
}
const char* DrillingRobot::EnumToString(CoolantType coolant) {
	ENUM_TO_STRING_SWITCH(coolant)
		ENUM_TO_STRING_CASE(CT_NONE)
		ENUM_TO_STRING_CASE(CT_WATER)
		ENUM_TO_STRING_CASE(CT_OIL)
		ENUM_TO_STRING_SWITCH_END()
		//return _T("CoolantType");
}

void DrillingRobot::AttachDrillBit(unsigned int diameter, DrillBitType drillBit) {
	printf("Attaching %s drill bit, diameter %d\n", EnumToString(drillBit), diameter);
}

void DrillingRobot::DetachDrillBit() {
	printf("Detaching drill bit\n");
}

void DrillingRobot::ConfigureRpm(Rpm rpm) {
	printf("Setting RPM to %s\n", EnumToString(rpm));
}

void DrillingRobot::StartCooling(CoolantType coolant) {
	printf("Starting cooling with %s\n", EnumToString(coolant));
}

void DrillingRobot::StopCooling() {
	printf("Stopping cooling\n");
}

void DrillingRobot::MoveMaterial(int x, int y) {
	printf("Moving material, x = %d, y = %d\n", x, y);
}

void DrillingRobot::Drill(unsigned int depth) {
	printf("Drilling, depth = %d\n", depth);
}

void DrillingRobot::DoBreak() {
	printf("Giving a break\n");
}




template<>
void AttachDrillBit<MetalDrillBit>(DrillingRobot& drillingRobot, unsigned int diameter) {
	drillingRobot.AttachDrillBit(diameter, DrillingRobot::DB_METAL);
}

template<>
void AttachDrillBit<WoodDrillBit>(DrillingRobot& drillingRobot, unsigned int diameter) {
	drillingRobot.AttachDrillBit(diameter, DrillingRobot::DB_WOOD);
}





template<>
void ConfigureRpm<LowRpm>(DrillingRobot& drillingRobot) {
	drillingRobot.ConfigureRpm(DrillingRobot::RPM_LOW);

}
template<>
void ConfigureRpm<MediumRpm>(DrillingRobot& drillingRobot) {
	drillingRobot.ConfigureRpm(DrillingRobot::RPM_MEDIUM);
}

template<>
void ConfigureRpm<HighRpm>(DrillingRobot& drillingRobot) {
	drillingRobot.ConfigureRpm(DrillingRobot::RPM_HIGH);
}



