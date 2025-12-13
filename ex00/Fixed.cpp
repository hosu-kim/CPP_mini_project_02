#include "Fixed.hpp"

// constructor
Fixed::Fixed() : fixed_point_num(0) {
}

// copy constructor
Fixed::Fixed(const Fixed& other): fixed_point_num(0) {
}

// operator는 C++ 키워드임
// : 연산자가 어떻게 작동할지 내가 직접 정의하겠음.
//   Fixed 객체끼리는 =가 어떻게 동작할지 정의함.
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->fixed_point_num = other.fixed_point_num;
	}

	return *this;
}