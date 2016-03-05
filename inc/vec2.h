#pragma once
#include "vec2_DEF.h"





template <typename T>
vec2<T>::vec2()
	:x(0), y(0)
{}
template <typename T>
vec2<T>::vec2(const T xx, const T yy)
	: x(xx), y(yy)
{}

template <typename T>
vec2<T>& vec2<T>:: operator=  (const vec2<T> rhs) {

	x = rhs.x;
	y = rhs.y;

	return *this;
}
template <typename T>
vec2<T>& vec2<T>:: operator+= (const vec2<T> rhs) {

	x += rhs.x;
	y += rhs.y;

	return *this;
}
template <typename T>
vec2<T>& vec2<T>:: operator-= (const vec2<T> rhs) {

	x -= rhs.x;
	y -= rhs.y;

	return *this;
}
template <typename T>
vec2<T>& vec2<T>:: operator*= (const vec2<T> rhs) {

	x *= rhs.x;
	y *= rhs.y;

	return *this;
}
template <typename T>
vec2<T>& vec2<T>:: operator/= (const vec2<T> rhs) {

	x /= rhs.x;
	y /= rhs.y;

	return *this;
}

template <typename T>
vec2<T>& vec2<T>:: operator*= (const T rhs) {

	x *= rhs;
	y *= rhs;

	return *this;
}
template <typename T>
vec2<T>& vec2<T>:: operator/= (const T rhs) {

	x /= rhs;
	y /= rhs;

	return *this;
}

template <typename T>
vec2<T> operator+ (const vec2<T> lhs, const vec2<T> rhs) {

	vec2<T> ret(lhs);

	ret += rhs;

	return ret;
}
template <typename T>
vec2<T> operator- (const vec2<T> lhs, const vec2<T> rhs) {

	vec2<T> ret(lhs);

	ret -= rhs;

	return ret;
}
template <typename T>
vec2<T> operator* (const vec2<T> lhs, const vec2<T> rhs) {

	vec2<T> ret(lhs);

	ret *= rhs;

	return ret;
}
template <typename T>
vec2<T> operator/ (const vec2<T> lhs, const vec2<T> rhs) {

	vec2<T> ret(lhs);

	ret /= rhs;

	return ret;
}

template <typename T>
vec2<T> operator* (const vec2<T> lhs, const T rhs) {

	vec2<T> ret(lhs);

	ret *= rhs;

	return ret;
}
template <typename T>
vec2<T> operator/ (const vec2<T> lhs, const T rhs) {

	vec2<T> ret(lhs);

	ret /= rhs;

	return ret;
}