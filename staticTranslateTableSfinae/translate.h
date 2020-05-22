#pragma once

#include <optional>
#include "exported-types.h"

namespace translate
{
	using value_t = int;

	extern constexpr std::optional<value_t> lookup(Color color);
	extern constexpr std::optional<value_t> lookup(Rotation rotation);

	extern constexpr std::optional<Color> lookupReverse_Color(value_t color);
	extern constexpr std::optional<Rotation> lookupReverse_Rotation(value_t rotation);
	
}
