#pragma once



template <typename T>
struct vec2 {

    T x,y;
    

	vec2();
	vec2(const T xx,const T yy);
    
	vec2<T>& operator=  (const vec2<T> rhs);
    vec2<T>& operator+= (const vec2<T> rhs);
    vec2<T>& operator-= (const vec2<T> rhs);
    vec2<T>& operator*= (const vec2<T> rhs);
	vec2<T>& operator/= (const vec2<T> rhs);

	vec2<T>& operator*= (const T rhs);
	vec2<T>& operator/= (const T rhs);

	template <typename T>
	friend vec2<T> operator+ (const vec2<T> lhs, const vec2<T> rhs);
	template <typename T>
	friend vec2<T> operator- (const vec2<T> lhs,const vec2<T> rhs);
	template <typename T>
	friend vec2<T> operator* (const vec2<T> lhs,const vec2<T> rhs);
	template <typename T>
	friend vec2<T> operator/ (const vec2<T> lhs,const vec2<T> rhs);

	template <typename T>
	friend vec2<T> operator* (const vec2<T> lhs,const T rhs);
	template <typename T>
	friend vec2<T> operator/ (const vec2<T> lhs,const T rhs);

};







