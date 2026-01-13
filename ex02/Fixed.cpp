#include "Fixed.hpp"

// constructor
Fixed::Fixed() : _fixedPointValue(0) {
}

// 과제1
// constructor that takes a constant integer
// 비트 시프트로 이동할수록 정수에 2가 제곱됨.
Fixed::Fixed(const int intValue): _fixedPointValue(intValue << _fractionalBits) {
}

// 과제2: constructor that takes a constant floating-point number as a parameter
//       converts it to the corresponding fixed-point value.
//       the fractional bits value should be initialized to 8
// Initializes _fixedPointValue by converting the provided float to fixed-point format.
// 비트 연산자는 정수에서만 적용 가능하기 때문에 곱셈을 사용함.                vvv
Fixed::Fixed(const float value): _fixedPointValue((int)roundf(value * (1 << _fractionalBits))) {
}

// copy constructor
Fixed::Fixed(const Fixed& other) {
	*this = other;
}

// copy assignment operator overload (복사 대입 연산자 오버로딩)
// operator는 C++ 키워드임
// : 연산자가 어떻게 작동할지 내가 직접 정의하겠음.
//   Fixed 객체끼리는 =가 어떻게 동작할지 정의함.
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

// destructor
Fixed::~Fixed() {
}

// const: 읽기 전용
int Fixed::getRawBits(void) const {
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

// TASK 1
// 멤버에 접근할 때 포인터는 -> 연산자를 쓰고 참조는 . 연산자를 쓴다.
// ->: 포인터가 가리키는 곳으로 찾아가서 멤버 접근
// .: 바로 멤버 접근
// `this`는 포인터임.
bool Fixed::operator>(const Fixed &other) const {
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->getRawBits() >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->getRawBits() != other.getRawBits();
}

// TASK 2
Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// TASK 3
// Pre-increment: 먼저 증가 후 값 반환
Fixed& Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

// Post-increment: 반환 후 증가
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp; // 증가 전의 값을 반환
}

// Pre-decrement: 먼저 감소 후 값 반환
Fixed& Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}
// Post-decrement: 반환 후 감소
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp; // 감소 전의 값을 반환
}

// TASK 4: A static member function min
//         that takes two references to fixed-point numbers
//         as parameters, and returns a reference to the smallest one.
// 구현부에서는 static을 빼야 함.
Fixed& Fixed::min(Fixed& fpn1, Fixed& fpn2) {
	if (fpn1.toFloat() <= fpn2.toFloat())
		return fpn1;
	else
		return fpn2;
}

// TASK 5: A static member function min
//         that takes two references to constant fixed-point numbers
//         as parameters, and returns a reference to the smallest one.
// const가 매개변수에 없으면 const 객체를 전달할 수 없기 때문에 따로 구현해준다.
const Fixed& Fixed::min(const Fixed& fpn1, const Fixed& fpn2) {
	if (fpn1.toFloat() <= fpn2.toFloat())
		return fpn1;
	else
		return fpn2;
}

// TASK 6: A static member function max that
//         takes two references to fixed-point numbers
//         as parameters, and returns a reference to the greatest one.
Fixed& Fixed::max(Fixed& fpn1, Fixed& fpn2) {
	if (fpn1.toFloat() >= fpn2.toFloat())
		return fpn1;
	else
		return fpn2;
}

// TASK 7: TASK 7: A static member function max
//         that takes two references to constant fixed-point numbers
//         as parameters, and returns a reference to the greatest one.
const Fixed& Fixed::max(const Fixed& fpn1, const Fixed& fpn2) {
	if (fpn1.toFloat() >= fpn2.toFloat())
		return fpn1;
	else
		return fpn2;
}