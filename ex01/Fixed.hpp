#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed(); // itializes the fixed-point number value to 0. [X]
		// A constructor that takes a constant integer as a parameter.
		// It converts it to the corresponding fixed-point value.
		// The fractional bits value should be initialized to 8.
		Fixed(const int value);
	
		
		// copy constructor [X]
		Fixed(const Fixed& other);
		// copy assignment operator overload
		// 복사 대입 연산자 오버로딩
		Fixed& operator=(const Fixed& other);
		// destructor
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif