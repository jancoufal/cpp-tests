#pragma once
#pragma once

#include <cstdio>

//
// Drilling robot
//
class DrillingRobot {
public:
	enum DrillBitType { DB_UNDEFINED, DB_METAL, DB_WOOD };
	enum Rpm { RPM_LOW, RPM_MEDIUM, RPM_HIGH };
	enum CoolantType { CT_NONE, CT_WATER, CT_OIL };

private:
	const char* EnumToString(DrillBitType drillBit);
	const char* EnumToString(Rpm rpm);
	const char* EnumToString(CoolantType coolant);

public:
	void AttachDrillBit(unsigned int diameter, DrillBitType drillBit);
	void DetachDrillBit();

	void ConfigureRpm(Rpm rpm);

	void StartCooling(CoolantType coolant);
	void StopCooling();

	void MoveMaterial(int x, int y);
	void Drill(unsigned int depth);

	void DoBreak();
};


//
// Trait classes
//
class MetalDrillBit;
class WoodDrillBit;

class LowRpm;
class MediumRpm;
class HighRpm;

class NoCoolant;
class WaterCoolant;
class OilCoolant;

class SequentialDrilling;
class SequentialDrillingWithBreak;

class Iron;
class Aluminium;
class Pine;
class Teak;
class Plastic;


//
// Trait debug title.
//
template<typename>
class TraitDebugTitle {
public:
	const char* GetTitle() { return "(no title)"; }
};

#define DBG_TRAIT_TITLE(trait) \
template<> \
class TraitDebugTitle<trait> { \
public: \
	const char* GetTitle() { return "Drilling " #trait " material"; } \
};

DBG_TRAIT_TITLE(Iron)
DBG_TRAIT_TITLE(Aluminium)
DBG_TRAIT_TITLE(Pine)
DBG_TRAIT_TITLE(Teak)
DBG_TRAIT_TITLE(Plastic)


//
// Material traits
//
template<typename>
class MaterialTraits {
};

template<>
class MaterialTraits<Iron> {
public:
	typedef MetalDrillBit DrillBitType;
	typedef MediumRpm RpmType;
	typedef WaterCoolant CoolantType;
	typedef SequentialDrillingWithBreak SequentialDrillingType;
};

template<>
class MaterialTraits<Aluminium> {
public:
	typedef MetalDrillBit DrillBitType;
	typedef LowRpm RpmType;
	typedef OilCoolant CoolantType;
	typedef SequentialDrilling SequentialDrillingType;
};

template<>
class MaterialTraits<Pine> {
public:
	typedef WoodDrillBit DrillBitType;
	typedef MediumRpm RpmType;
	typedef NoCoolant CoolantType;
	typedef SequentialDrilling SequentialDrillingType;
};

template<>
class MaterialTraits<Teak> {
public:
	typedef WoodDrillBit DrillBitType;
	typedef LowRpm RpmType;
	typedef NoCoolant CoolantType;
	typedef SequentialDrillingWithBreak SequentialDrillingType;
};

template<>
class MaterialTraits<Plastic> {
public:
	typedef MetalDrillBit DrillBitType;
	typedef HighRpm RpmType;
	typedef NoCoolant CoolantType;
	typedef SequentialDrilling SequentialDrillingType;
};


//
// Attach drill bit
//
template<typename>
void AttachDrillBit(DrillingRobot& drillingRobot, unsigned int diameter) {
	drillingRobot.AttachDrillBit(diameter, DrillingRobot::DB_UNDEFINED);
}

template<> void AttachDrillBit<MetalDrillBit>(DrillingRobot& drillingRobot, unsigned int diameter);
template<> void AttachDrillBit<WoodDrillBit>(DrillingRobot& drillingRobot, unsigned int diameter);


//
// Configure RPM
//
template<typename>
void ConfigureRpm(DrillingRobot& drillingRobot) {
}

template<> void ConfigureRpm<LowRpm>(DrillingRobot& drillingRobot);
template<> void ConfigureRpm<MediumRpm>(DrillingRobot& drillingRobot);
template<> void ConfigureRpm<HighRpm>(DrillingRobot& drillingRobot);


//
// Coolant handler
//
template<typename>
class CoolantHandler {
};

template<>
class CoolantHandler<NoCoolant> {
public:
	void StartCooling(DrillingRobot& drillingRobot) {
	}

	void StopCooling(DrillingRobot& drillingRobot) {
	}
};

template<>
class CoolantHandler<WaterCoolant> {
public:
	void StartCooling(DrillingRobot& drillingRobot) {
		drillingRobot.StartCooling(DrillingRobot::CT_WATER);
	}

	void StopCooling(DrillingRobot& drillingRobot) {
		drillingRobot.StopCooling();
	}
};

template<>
class CoolantHandler<OilCoolant> {
public:
	void StartCooling(DrillingRobot& drillingRobot) {
		drillingRobot.StartCooling(DrillingRobot::CT_OIL);
	}

	void StopCooling(DrillingRobot& drillingRobot) {
		drillingRobot.StopCooling();
	}
};


//
// Break handler
//
template<typename>
class SequentialDrllingHandler {
};

template<>
class SequentialDrllingHandler<SequentialDrilling> {
public:
	void DoBreak(DrillingRobot& drillingRobot) {
	}
};


template<>
class SequentialDrllingHandler<SequentialDrillingWithBreak> {
public:
	void DoBreak(DrillingRobot& drillingRobot) {
		drillingRobot.DoBreak();
	}
};


//
// Drill specific product
//
template <typename Material>
void DrillCandleHolder(DrillingRobot& drillingRobot, unsigned int diameter, unsigned int numHoles, unsigned int depth, unsigned int xSpacing, unsigned int startX, unsigned int startY) {

	typedef MaterialTraits<Material> TMaterial;

	TraitDebugTitle<Material> dbgTitle;
	printf("\n%s\n", dbgTitle.GetTitle());


	AttachDrillBit<TMaterial::DrillBitType>(drillingRobot, diameter);
	ConfigureRpm<TMaterial::RpmType>(drillingRobot);
	CoolantHandler<TMaterial::CoolantType> coolantHandler;
	SequentialDrllingHandler<TMaterial::SequentialDrillingType> sequentialDrillingHandler;

	for (unsigned int i = 0; i < numHoles; ++i, startX += xSpacing) {

		drillingRobot.MoveMaterial(startX, startY);
		coolantHandler.StartCooling(drillingRobot);
		drillingRobot.Drill(depth);
		coolantHandler.StopCooling(drillingRobot);

		if (i != numHoles - 1)
			sequentialDrillingHandler.DoBreak(drillingRobot);
	}

	drillingRobot.DetachDrillBit();
}

