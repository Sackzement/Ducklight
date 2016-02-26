#pragma once
#include <initializer_list>

template<size_t S,typename T>
class vec {

	T m_array[S] = {};

public:
	vec(std::initializer_list<T> l = {}) {

		const size_t lSize = l.size();

		
		
		const T* it             = l.begin();
		size_t numVValidValues  = lSize;

		if (lSize > S)
			numVValidValues = S;

		for (size_t i = 0; i < numVValidValues; ++i,++it)
			m_array[i] = *it;

		

		size_t numZeroValues = 0;
		if (S > lSize)
			numZeroValues = S - numVValidValues;

		for (size_t i = 0; i < numZeroValues; ++i)
			m_array[i + numVValidValues] = 0;
	}


	T& operator [] (size_t n) {
		return m_array[n];
	}

};