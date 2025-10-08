#pragma once

class Fixed
{
	public:
		Fixed(); 								//| Construtor padrão.
		Fixed(const Fixed &fixed); 				//| Construtor de cópia.
		~Fixed(); 								//| Destrutor padrão.

		Fixed &operator=(const Fixed &fixed); 	//| Operador de atribuição.
		int getRawBits( void ) const; 			//| Getter.
		void setRawBits( int const raw ); 		//| Setter.

	private:
		int _value;
		static const int _bits = 8;
};
