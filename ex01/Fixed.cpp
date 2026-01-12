#include "Fixed.hpp"

// constructor
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// 과제1
// constructor that takes a constant integer
// 비트 시프트로 이동할수록 정수에 2가 제곱됨.
Fixed::Fixed(const int intValue): _fixedPointValue(intValue << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

// 과제2: constructor that takes a constant floating-point number as a parameter
//       converts it to the corresponding fixed-point value.
//       the fractional bits value should be initialized to 8
// Initializes _fixedPointValue by converting the provided float to fixed-point format.
// 비트 연산자는 정수에서만 적용 가능하기 때문에 곱셈을 사용함.    vvv
Fixed::Fixed(const float value): _fixedPointValue(value * (1 << _fractionalBits)) {
	std::cout << "Float constructor called" << std::endl;
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

// TASK 3: A member function float toFloat( void ) const;
//         that converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const {
	return _fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
