#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();				//| Construtor padrão.
		Fixed(const int value);			//| Construtor por cópia INT.
		Fixed(const float value);		//| Construtor por cópia FLOAT.
		Fixed(const Fixed &fixed);		//| Construtor por cópia FIXED.
		~Fixed();				//| Destrutor padrão.

		Fixed &operator=(const Fixed &fixed);	//| Operator de atribuição.

		int toInt( void ) const;		//| Getter INT.
		float toFloat( void ) const;		//| Getter FLOAT.
		int getRawBits( void ) const;		//| Getter _value.

		void setRawBits( int const raw );	//| Setter _value.
	private:
		int _value;
		static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif //| FIXED_HPP
