#pragma once

#include "muchawon_enum.h"

#include <type_traits>
#include <tuple>

namespace muchawon
{

template<typename T, int dimension = 1>
class unit_type
{
public:
	unit_type() = delete;
	unit_type(T type) : type_(type) {}
	unit_type(T type, int dimension) : type_(type), dimension_(dimension) {}
	virtual ~unit_type() = default;

	template<typename T0>
	requires is_same_type<T, T0>
	auto operator+(const unit_type<T0>& rhs) { return unit_type<T>(type_, dimension_); }

	template<typename T0>
	requires is_same_type<T, T0>
	auto operator-(const unit_type<T0>& rhs) { return unit_type<T>(type_, dimension_); }

	template<typename T0>
	auto operator*(const unit_type<T0>& rhs)
	{
		if constexpr (std::is_same<T, T0>::value)
			return unit_type<T>(type_, dimension_ + rhs.dimension_);
		else
		{

		}
	}

	template<typename T0>
	auto operator/(const unit_type<T0>& rhs)
	{
		if constexpr (std::is_same<T, T0>::value)
			return unit_type<T>(type_, dimension_ - rhs.dimension_);
		else
		{

		}
	}

private:
	T type_;
	int dimension_ = dimension;
};

template<typename... Us>
class complex_unit
{
private:
	std::tuple<Us...> units_;
};

}