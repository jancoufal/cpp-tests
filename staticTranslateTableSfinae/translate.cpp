#include "translate.h"

#include "hidden-defines.h"

namespace translate
{

	static constexpr std::pair<Color, int> Color_LUT[] = {
		{ Color::Red, COLOR_RED },
		{ Color::Green, COLOR_GREEN },
		{ Color::Blue, COLOR_BLUE },
		//	{ Color::Alpha, COLOR_ALPHA },	// it is not there for testing purposes
	};

	static constexpr std::pair<Rotation, int> Rotation_LUT[] = {
		{ Rotation::Pitch, ROTATION_PITCH },
		{ Rotation::Roll, ROTATION_ROLL },
		{ Rotation::Yaw, ROTATION_YAW },
	};

	//
	// lookup & reverse lookup templates
	//
	template<typename K, typename V, size_t N>
	static constexpr std::optional<V> lookup(K needle, const std::pair<K, V>(&lut)[N])
	{
		for (const auto& pair : lut)
			if (pair.first == needle)
				return std::make_optional(pair.second);

		return std::nullopt;
	}

	template<typename K, typename V, size_t N>
	static constexpr std::optional<K> lookupReverse(V needle, const std::pair<K, V>(&lut)[N])
	{
		for (const auto& pair : lut)
			if (pair.second == needle)
				return std::make_optional(pair.first);

		return std::nullopt;
	}

	//
	// implementations
	//

	constexpr std::optional<value_t> lookup(Color color)
	{
		return lookup(color, Color_LUT);
	}
	
	constexpr std::optional<value_t> lookup(Rotation rotation)
	{
		return lookup(rotation, Rotation_LUT);
	}

	constexpr std::optional<Color> lookupReverse_Color(value_t color)
	{
		return lookupReverse(color, Color_LUT);
	}


	constexpr std::optional<Rotation> lookupReverse_Rotation(value_t rotation)
	{
		return lookupReverse(rotation, Rotation_LUT);
	}
}
