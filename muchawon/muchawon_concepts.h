#pragma once

#include <type_traits>

namespace muchawon
{

template<typename T>
concept is_numeric = std::is_arithmetic_v<T>;

template<typename T, typename T0>
concept is_same_type = std::is_same_v<T, T0>;

}