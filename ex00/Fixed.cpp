#include "Fixed.hpp"

// constructor
//             vvv member initializer list
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// copy assignment operator overload (복사 대입 연산자 오버로딩)
// operator는 C++ 키워드임
// : 연산자가 어떻게 작동할지 내가 직접 정의하겠음.
//   Fixed 객체끼리는 =가 어떻게 동작할지 정의함.
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

// destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// const: 읽기 전용
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;

	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); // TASK 5