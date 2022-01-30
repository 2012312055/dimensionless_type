#pragma once

#include "muchawon_concepts.h"

#define _numeric_calc_(calc) \
template<typename T0> \
requires muchawon::is_numeric<T0> \
auto operator##calc##(T0 val) \
{ \
	return muchawon_type<T, U>(val_ ##calc## val, unit_); \
}

#define _muchawon_type_calc_(calc) \
template<typename T0, typename U0> \
auto operator##calc##(const muchawon_type<T0, U0>& rhs) \
{ \
	return (muchawon_type<decltype(val_ ##calc## rhs.val_), decltype(unit_ ##calc## rhs.unit_)>(val_ ##calc## rhs.val_, unit_ ##calc## rhs.unit_)); \
}

template<typename T, typename U>
class muchawon_type
{
	template<typename T0, typename U0>
	friend class muchawon_type;

public:
	muchawon_type() = delete;
	muchawon_type(const T& val, const U& unit) : val_(val), unit_(unit) {}
	muchawon_type(T&& val, U&& unit) noexcept : val_(std::move(val)), unit_(std::move(unit)) {}
	virtual ~muchawon_type() = default;

	T* operator->() { return &val_; }

	_numeric_calc_(*);
	_numeric_calc_(/);

	_muchawon_type_calc_(+);
	_muchawon_type_calc_(-);
	_muchawon_type_calc_(*);
	_muchawon_type_calc_(/);

	T getVal() { return val_; }
	void setVal(const T& val) { val_ = val; }
	U getUnit() { return unit_; }
	void setUnit(const U& unit) { unit_ = unit; }

private:
	T val_;
	U unit_;
};