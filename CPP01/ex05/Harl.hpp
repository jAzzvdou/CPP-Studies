#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl(); //| Construtor
		~Harl(); //| Destrutor

		//|----------| Método |----------|//
		void complain( std::string level );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif //| HARL_HPP
