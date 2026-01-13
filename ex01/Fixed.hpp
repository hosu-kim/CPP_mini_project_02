#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed(); // itializes the fixed-point number value to 0. [X]
		Fixed(const int value); // TASK 1
		Fixed(const float value); // TASK 2
		
		// copy constructor [X]
		Fixed(const Fixed& other);
		// copy assignment operator overload
		// 복사 대입 연산자 오버로딩
		Fixed& operator=(const Fixed& other);
		// destructor
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const; // TASK 3
		int toInt(void) const; // TASK 4
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif