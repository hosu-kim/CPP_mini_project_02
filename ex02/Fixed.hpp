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

		// TASK 1: comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// TASK 2: arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// TASK 3
		// Pre-increment: 먼저 증가 후 값 반환
		Fixed& operator++();
		// Post-increment: 반환 후 증가
		Fixed operator++(int);
		// Pre-decrement: 먼저 감소 후 값 반환
		Fixed& operator--();
		// Post-decrement: 반환 후 감소
		Fixed operator--(int);

		// TASK 4
		// static은 객체가 없어도 호출이 가능하다는 뜻이다.
		static Fixed& min(Fixed& fpn1, Fixed& fpn2);
		static const Fixed& min(const Fixed& fpn1, const Fixed& fpm2);
		static Fixed& max(Fixed& fpn1, Fixed& fpn2);
		static const Fixed& max(const Fixed& fpn1, Fixed& fpn2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif