#ifndef FIXED_HPP
#define FIXTED_HPP

class Fixed {
	private:
		int fixed_point_num;
		static const int fractional_bits = 8;
	public:
		Fixed(); // itializes the fixed-point number value to 0. [X]
		// copy constructor [X]
		Fixed(const Fixed& other);
		// copy assignment operator overload
		// 복사 대입 연산자 오버로딩
		Fixed& operator=(const Fixed& other);
		// destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif